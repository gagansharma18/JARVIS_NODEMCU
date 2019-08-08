const char MAIN_page[] PROGMEM = R"=====(
<!DOCTYPE html>
<html>
<head>
<meta name="viewport" content="width=device-width, initial-scale=1">
  <style>
  .switch {
    position: relative;
    display: inline-block;
    width: 60px;
    height: 34px;
  }
  
  .switch input { 
    opacity: 0;
    width: 0;
    height: 0;
  }
  
  .slider {
    position: absolute;
    cursor: pointer;
    top: 0;
    left: 0;
    right: 0;
    bottom: 0;
    background-color: #ccc;
    -webkit-transition: .4s;
    transition: .4s;
  }
  
  .slider:before {
    position: absolute;
    content: "";
    height: 26px;
    width: 26px;
    left: 4px;
    bottom: 4px;
    background-color: white;
    -webkit-transition: .4s;
    transition: .4s;
  }
  
  input:checked + .slider {
    background-color: #2196F3;
  }
  
  input:focus + .slider {
    box-shadow: 0 0 1px #2196F3;
  }
  
  input:checked + .slider:before {
    -webkit-transform: translateX(26px);
    -ms-transform: translateX(26px);
    transform: translateX(26px);
  }
  
  /* Rounded sliders */
  .slider.round {
    border-radius: 34px;
  }
  
  .slider.round:before {
    border-radius: 50%;
  }
  </style>
	<script>
		new WebSocket('wss://' + location.hostname + ':81/', ['arduino']);
    connection.onopen = function() {
        connection.send('Connect ' + new Date());
    };
    connection.onerror = function(error) {
        console.log('WebSocket Error ', error);
    };
    connection.onmessage = function(e) {
        console.log('Server: ', e.data);
    };
    
    function sendRGB() {
        var r = parseInt(document.getElementById('r').value).toString(16);
        var g = parseInt(document.getElementById('g').value).toString(16);
        var b = parseInt(document.getElementById('b').value).toString(16);
        if (r.length < 2) {
            r = '0' + r;
        }
        if (g.length < 2) {
            g = '0' + g;
        }
        if (b.length < 2) {
            b = '0' + b;
        }
        var rgb = '#' + r + g + b;
        console.log('RGB: ' + rgb);
        connection.send(rgb);
    }
	</script>
</head>

<body>LED Control:
	<br/>
	<br/>R:
	<input id="r" type="range" min="0" max="255" step="1" oninput="sendRGB();" />
	<br/>G:
	<input id="g" type="range" min="0" max="255" step="1" oninput="sendRGB();" />
	<br/>B:
	<input id="b" type="range" min="0" max="255" step="1" oninput="sendRGB();" />
	<br/>
 <h2>Toggle Switch</h2>

<label class="switch">
  <input type="checkbox">
  <span class="slider"></span>
</label>

<label class="switch">
  <input type="checkbox" checked>
  <span class="slider"></span>
</label><br><br>

<label class="switch">
  <input type="checkbox">
  <span class="slider round"></span>
</label>

<label class="switch">
  <input type="checkbox" checked>
  <span class="slider round"></span>
</label>
</body>
</html>
)=====";
