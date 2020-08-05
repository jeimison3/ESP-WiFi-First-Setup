#include <Arduino.h>

// Import required libraries
#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <Hash.h>
#include <ESPAsyncTCP.h>
#include <ESPAsyncWebServer.h>
// #include <FS.h>
#include "LittleFS.h"
#include <ArduinoOTA.h>

const char* ssid     = "ESP8266-Access-Point";
const char* password = "123456789";

String redesWiFi = "";


// Create AsyncWebServer object on port 80
AsyncWebServer server(80);


#include "page.h"


bool resetRede() {
  return LittleFS.remove("/wifi.txt");
}

bool salvaRede(String* ssid, String* pass) { 
  //Abre o arquivo para escrita ("w" write)
  //Sobreescreve o conteúdo do arquivo
  File rFile = LittleFS.open("/wifi.txt","w+"); 
  if(!rFile){
    Serial.println("ERRO NO FS.");
    return false;
  } else {
    rFile.printf("%s\n%s\n",ssid->c_str(),pass->c_str());
    Serial.printf("Salvo (%s,%s)",ssid->c_str(),pass->c_str());
    rFile.close();
    return true;
  }
}


bool getRede() {
  File rFile = LittleFS.open("/wifi.txt","r");
  if (!rFile) {
    return false;
  }
  String ssid = rFile.readStringUntil('\n');
  String pass = rFile.readStringUntil('\n');
  Serial.printf("SSID RECONHECIDO (%s,%s)", ssid.c_str(),pass.c_str());
  rFile.close();

  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, pass);
  while (WiFi.status() != WL_CONNECTED) {
    delay(250);
    Serial.print(".");
  }
  Serial.println("CONECTADO");
  return true;
}


void buscaRedes(){
  WiFi.mode(WIFI_STA);
  WiFi.disconnect();
  delay(100);
  int redes = WiFi.scanNetworks();
    redesWiFi = "";
    for(int i =0; i<redes; i++){
      redesWiFi += WiFi.SSID(i)+'\n'+WiFi.RSSI(i)+'\n';
      Serial.print("Network name: ");
      Serial.println(WiFi.SSID(i));
      Serial.print("Signal strength: ");
      Serial.println(WiFi.RSSI(i));
      Serial.println("-----------------------");
    }
}


void setup(){
  delay(50);
  
  Serial.begin(115200);
  if(!LittleFS.begin()){
    Serial.printf("Erro ao abrir FS.");
    delay(2000);
    ESP.restart();
  }

  if(getRede()){

    ArduinoOTA.setHostname("NodeMCU");
    ArduinoOTA.onStart([]() {
      Serial.println("Inicio...");
    });
    ArduinoOTA.onEnd([]() {
      Serial.println("Fim!");
    });
    ArduinoOTA.onProgress([](unsigned int progress, unsigned int total) {
      Serial.printf("Progresso: %u%%r", (progress / (total / 100)));
    });
    ArduinoOTA.onError([](ota_error_t error) {
      Serial.printf("Erro [%u]: ", error);
      if (error == OTA_AUTH_ERROR) Serial.println("Autenticacao falhou.");
      else if (error == OTA_BEGIN_ERROR) Serial.println("Falha no inicio.");
      else if (error == OTA_CONNECT_ERROR) Serial.println("Falha na conexao.");
      else if (error == OTA_RECEIVE_ERROR) Serial.println("Falha na recepcao.");
      else if (error == OTA_END_ERROR) Serial.println("Falha no fim.");
    });
    ArduinoOTA.begin();

    // Print ESP8266 Local IP Address
    Serial.print("IP=");
    Serial.println(WiFi.localIP());

    // resetRede();

  } else {
    buscaRedes();

    Serial.print("Setting AP (Access Point)…");
    // Remove the password parameter, if you want the AP (Access Point) to be open
    WiFi.softAP(ssid, password);

    IPAddress IP = WiFi.softAPIP();
    Serial.print("AP IP address: ");
    Serial.println(IP);

    // Route for root / web page
    server.on("/", HTTP_GET, [](AsyncWebServerRequest *request){
      request->send_P(200, "text/html", index_html);
    });
    server.on("/wifi", HTTP_GET, [](AsyncWebServerRequest *request){
      request->send_P(200, "text/plain", redesWiFi.c_str());
    });
    server.on("/conecta", HTTP_GET, [](AsyncWebServerRequest *request){
      Serial.println("PARAMS:");
      for(int i=0; i<request->params(); i++){
        Serial.print(request->getParam(i)->name());
        Serial.print("=");
        Serial.println(request->getParam(i)->value());
      }
      Serial.println("###############");
      bool resultado = false;
      if(request->hasParam("ssid") && request->hasParam("pass")){
        String ssid = request->getParam("ssid")->value();
        String pass = request->getParam("pass")->value();
        
        if (salvaRede(&ssid,&pass)) resultado = true;
      }
      request->send_P(resultado?200:403, "text/plain", String(".").c_str());
      // delay(500);
      if(resultado) ESP.restart();
    });

  }

  // Start server
  server.begin();
}
 
void loop(){
  ArduinoOTA.handle();
}
