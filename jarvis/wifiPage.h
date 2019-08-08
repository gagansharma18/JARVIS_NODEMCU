const char MAIN_page[] PROGMEM = R"=====(
<html>

<head>
	<script>
		var connection = new WebSocket('wss://'+location.hostname+':81/', ['arduino']);connection.onopen = function () {  connection.send('Connect ' + new Date()); }; connection.onerror = function (error) {    console.log('WebSocket Error ', error);};connection.onmessage = function (e) {  console.log('Server: ', e.data);};function sendRGB() {  var r = parseInt(document.getElementById('r').value).toString(16);  var g = parseInt(document.getElementById('g').value).toString(16);  var b = parseInt(document.getElementById('b').value).toString(16);  if(r.length < 2) { r = '0' + r; }   if(g.length < 2) { g = '0' + g; }   if(b.length < 2) { b = '0' + b; }   var rgb = '#'+r+g+b;    console.log('RGB: ' + rgb); connection.send(rgb); }
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
</body>

</html>
)=====";
