const char index_html[] PROGMEM = R"rawliteral(
<!DOCTYPE HTML><html>
<head>
  <meta charset="utf-8"/>
  <meta name="viewport" content="width=device-width, initial-scale=1">
  <style>
    html {
     text-align: center;
    }
    h2 { font-size: 3.0rem; }
    .dbi { font-size: 0.7rem; }
    .dht-labels{
      font-size: 1.5rem;
      vertical-align:middle;
      padding-bottom: 15px;
    }
    .wifi-icon{
        background:
            url(data:image/svg+xml;base64,PD94bWwgdmVyc2lvbj0iMS4wIiBlbmNvZGluZz0iaXNvLTg4NTktMSI/Pg0KPCEtLSBHZW5lcmF0b3I6IEFkb2JlIElsbHVzdHJhdG9yIDE5LjAuMCwgU1ZHIEV4cG9ydCBQbHVnLUluIC4gU1ZHIFZlcnNpb246IDYuMDAgQnVpbGQgMCkgIC0tPg0KPHN2ZyB2ZXJzaW9uPSIxLjEiIGlkPSJDYXBhXzEiIHhtbG5zPSJodHRwOi8vd3d3LnczLm9yZy8yMDAwL3N2ZyIgeG1sbnM6eGxpbms9Imh0dHA6Ly93d3cudzMub3JnLzE5OTkveGxpbmsiIHg9IjBweCIgeT0iMHB4Ig0KCSB2aWV3Qm94PSIwIDAgNTEyIDUxMiIgc3R5bGU9ImVuYWJsZS1iYWNrZ3JvdW5kOm5ldyAwIDAgNTEyIDUxMjsiIHhtbDpzcGFjZT0icHJlc2VydmUiPg0KPGc+DQoJPGc+DQoJCTxwYXRoIGQ9Ik0yNTYsMzYxLjY5M2MtMjQuOTc3LDAtNDUuMjk3LDIwLjMyLTQ1LjI5Nyw0NS4yOTdzMjAuMzIsNDUuMjk3LDQ1LjI5Nyw0NS4yOTdzNDUuMjk3LTIwLjMyLDQ1LjI5Ny00NS4yOTcNCgkJCVMyODAuOTc3LDM2MS42OTMsMjU2LDM2MS42OTN6Ii8+DQoJPC9nPg0KPC9nPg0KPGc+DQoJPGc+DQoJCTxwYXRoIGQ9Ik0yNTYsMjYxLjAzM2MtNDUuNjY3LDAtODYuNDk2LDIxLjA4Ny0xMTMuMjgsNTQuMDNsNDkuMjIxLDQ5LjIyMWMwLDAsMjIuOTU3LTMyLjc1Myw2NC4wNi0zMi43NTMNCgkJCWM0MC4yNjQsMCw2NC4wNiwzMi43NTMsNjQuMDYsMzIuNzUzbDQ5LjIyMS00OS4yMjFDMzQyLjQ5NiwyODIuMTIsMzAxLjY2OCwyNjEuMDMzLDI1NiwyNjEuMDMzeiIvPg0KCTwvZz4NCjwvZz4NCjxnPg0KCTxnPg0KCQk8cGF0aCBkPSJNMjU2LDU5LjcxM2MtMTYxLjkzNywwLTI1Mi42MDMsMTA4LjkzLTI1NiwxMTIuNjMxbDQ5Ljk3Nyw0OS45NzdjNTAuNzE3LTU2LjUyMywxMjQuMjg0LTkyLjE0NSwyMDYuMDIzLTkyLjE0NQ0KCQkJczE1NS4zMDcsMzUuNjIzLDIwNi4wMjMsOTIuMTQ1TDUxMiwxNzIuMzQzQzUwOC42MDMsMTY4LjY0Myw0MTcuNzI4LDU5LjcxMywyNTYsNTkuNzEzeiIvPg0KCTwvZz4NCjwvZz4NCjxnPg0KCTxnPg0KCQk8cGF0aCBkPSJNMjU2LDE2MC4zNzNjLTczLjQxNCwwLTEzOS40MjYsMzIuMjU3LTE4NC42NDMsODMuMzI4bDQ5LjkyNyw0OS45MjdjMzIuMzM5LTM4LjM3LDgwLjcyNS02Mi43OTMsMTM0LjcxNi02Mi43OTMNCgkJCWM1My45OSwwLDEwMi4zNzYsMjQuNDIzLDEzNC43MTYsNjIuNzkzbDQ5LjkyNy00OS45MjdDMzk1LjQyNiwxOTIuNjI5LDMyOS40MTQsMTYwLjM3MywyNTYsMTYwLjM3M3oiLz4NCgk8L2c+DQo8L2c+DQo8Zz4NCjwvZz4NCjxnPg0KPC9nPg0KPGc+DQo8L2c+DQo8Zz4NCjwvZz4NCjxnPg0KPC9nPg0KPGc+DQo8L2c+DQo8Zz4NCjwvZz4NCjxnPg0KPC9nPg0KPGc+DQo8L2c+DQo8Zz4NCjwvZz4NCjxnPg0KPC9nPg0KPGc+DQo8L2c+DQo8Zz4NCjwvZz4NCjxnPg0KPC9nPg0KPGc+DQo8L2c+DQo8L3N2Zz4NCg==)
            no-repeat
            left center;
        padding: 5px 10px 5px 25px;
    }
    .wifi-item{
        font-size: 1.5rem;
        vertical-align:middle;
        padding-bottom: 15px;
        background: #cce5ff;
        margin: 14px;
        padding: 10px;
    }
    .wifi-list{
        list-style-type: none;
        padding: 10px;
        background: #3399ff;
    }
    .wifi-ssid{
        padding-left: 10px;
        display: inline-block;
    }

    .form-data{
        font-size: 1.5rem;
        padding: 10px;
        display: inline-block;
    }

    .form-btn{
        font-size: 1.5rem;
        padding: 10px;
        background: #3399ff;
        display: inline-block;
        color:white;
    }
  </style>
</head>
<body>
  <h2>Escolha:</h2>
  <p id="searching">
    <span class="dht-labels">Aguarde...</span> 
  </p>

  <ul class="wifi-list">
  </ul>

  <div style="visibility:hidden;" id="form_senha">
  <span class="dht-labels">Senha:</span>
    <input class="form-data" type="text" id="input-senha" />
    <div onclick="conectar()" class="form-btn">Conectar</div>
  </div>

</body>
<script>
    var choseSsid="";
    var lista = [{ssid:'Rede 1',dbi:-51},{ssid:'Rede 2',dbi:-79}];

    function conectar(){
        var pass = document.getElementById('input-senha').value;
        document.getElementById('form_senha').style.visibility = "hidden";
        document.getElementsByTagName('h2')[0].textContent="Enviando...";
        var xhttp = new XMLHttpRequest();
        xhttp.onreadystatechange = function() {
            //if (xhttp.readyState == 4 && xhttp.status == 200) {
                document.getElementsByTagName('h2')[0].textContent="Salvo. Conectando.";
            //}
        };
        xhttp.open("GET", "/conecta?ssid="+choseSsid+"&pass="+pass, true);
        xhttp.send();
    }

    function carregaLista(){
        lista = [];
        document.getElementById('searching').style.visibility = "";
        document.getElementsByClassName('wifi-list')[0].style.visibility = "hidden";
        var xhttp = new XMLHttpRequest();
        xhttp.onreadystatechange = function() {
            if (this.readyState == 4 && this.status == 200) {
                redes = this.responseText.split('\n');
                for(var rede=0;rede<redes.length/2;rede++)
                    if(redes[rede*2]) lista.push( {ssid:redes[rede*2],dbi:redes[rede*2 +1]} );
                constroiLista();
            } else {
                constroiLista();
            }
        };
        xhttp.open("GET", "/wifi", true);
        xhttp.send();
    }

    function constroiLista(){

        htmlLista = document.getElementsByClassName('wifi-list')[0]
        for(var i=htmlLista.children.length-1; i >= 0; i--){ htmlLista.children[i].remove() }
        for(var item of lista){
            var novoItem = document.createElement("li");
            var icone = document.createElement("span");
            var dbi = document.createElement("sup");
            var ssidName = document.createElement("div");
            
            icone.className="wifi-icon";
            dbi.className="dbi";
            novoItem.className = "wifi-item";
            ssidName.className = 'wifi-ssid';

            ssidName.textContent = item['ssid'];

            dbi.textContent = String( item['dbi'] );
            


            novoItem.appendChild(icone)
            novoItem.appendChild(dbi)
            novoItem.appendChild(ssidName)

            novoItem.setAttribute('onclick',`ssidChoose("${item['ssid']}");`)
            
            
            htmlLista.appendChild( novoItem )
        }
        document.getElementById('searching').style.visibility = "hidden";
        document.getElementsByClassName('wifi-list')[0].style.visibility = "";
    }
    function ssidChoose(ssid){
        choseSsid = ssid;
        document.getElementById('searching').style.visibility = "hidden";
        document.getElementById('form_senha').style.visibility = "";
        document.getElementsByClassName('wifi-list')[0].remove();//.style.visibility = "hidden";
        document.getElementsByTagName('h2')[0].textContent=ssid;

    }

    window.onload = function() {
        carregaLista();
    }

</script>
</html>)rawliteral";