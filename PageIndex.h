const char MAIN_page[] PROGMEM = R"=====(
<!DOCTYPE html>
<html>
  <head>
    <meta name="viewport" content="width=device-width, initial-scale=1">
    <style>
      html {
        font-family: Arial;
        display: inline-block;
        margin: 0px auto;
        text-align: center;
      }
      
      .slidecontainer {
        width: 100%;
      }

      .slider {
        -webkit-appearance: none;
        width: 50%;
        height: 15px;
        border-radius: 5px;
        background-image: linear-gradient(rgb(190, 229, 245), rgb(98, 203, 252), rgb(190, 229, 245));
        outline: none;
        opacity: 0.7;
        -webkit-transition: .2s;
        transition: opacity .2s;
      }

      .slider:hover {
        opacity: 1;
      }

      .slider::-webkit-slider-thumb {
        -webkit-appearance: none;
        appearance: none;
        width: 75px;
        height: 50px;
        border-radius: 40%;
        background: #8e86fc;
        cursor: pointer;
      }

      .slider::-moz-range-thumb {
        width: 25px;
        height: 25px;
        border-radius: 50%;
        background: #4CAF50;
        cursor: pointer;
      }

      .botao{ 
        text-align: center;
        color: #00000052;
        font-size: large;
        font-weight: bold;
        border-radius: 15%;
        box-shadow: 0 5px #646464;
        height: 50px;
        width: 100px;
      }
      .botao:active {
        box-shadow: 0 0px #000000;
        transform: translateY(4px);
      }

      #frente{
        border: 4px solid #25ff2c3d;
        background-color: #a3f8a6f5;
      }

      #re{
        border: 4px solid #ff170f;
        background-color: #dd6e6ef6;
      }

      body{
        background-color: rgba(225, 249, 255, 0.925);
      }


    </style>
  </head>
  <body>

    <br><br>
    <div><button class="botao" id="frente"> Acelerar</button></div>
    <br><br>
    <div class="slidecontainer">
      <input type="range" min="-125" max="125" value="0" class="slider" id="myRange">
      <p>Angulo : <span id="demo"></span></p>
    <div><button class="botao" id = "re"> Re</button></div>
    </div>

    <script>
      function sendData(pos) {
        var xhttp = new XMLHttpRequest();
        xhttp.onreadystatechange = function() {
          if (this.readyState == 4 && this.status == 200) {
            console.log(this.responseText);
          }
        };
        xhttp.open("GET", "setPOS?stepperPOS="+pos, true);
        xhttp.send();
      } 
      var slider = document.getElementById("myRange");
      var output = document.getElementById("demo");
      var frente = document.getElementById("frente");
      var re = document.getElementById("re");

      output.innerHTML = slider.value;
      slider.oninput = function() {
        output.innerHTML = this.value;
        sendData(output.innerHTML);
      }

      frente.onmousedown=function(){
        sendButton('F');
      }

      frente.onmouseup=function(){
        sendButton('S');
      }

      re.onmousedown=function(){
        sendButton('R');
      }

      re.onmouseup=function(){
        sendButton('S');
      }

      function sendButton(char) {
        var xhttp = new XMLHttpRequest();
        xhttp.onreadystatechange = function() {
          if (this.readyState == 4 && this.status == 200) {
            console.log(this.responseText);
          }
        };
        xhttp.open("GET", "comand?button="+char, true);
        xhttp.send();
      } 


    </script>

  </body>
</html>
)=====";