#define DRD_TIMEOUT 2.0 // double reset detech timeout
#define DRD_ADDRESS 0x00
DoubleResetDetect drd(DRD_TIMEOUT, DRD_ADDRESS);
Ticker ticker;
WiFiManager wifiManager;

void tick(){
  int state = digitalRead(BUILTIN_LED);
  digitalWrite(BUILTIN_LED, !state);
}

//gets called when WiFiManager enters configuration mode
void configModeCallback (WiFiManager *myWiFiManager) {
  Serial.println("Entered config mode");
  Serial.println(WiFi.softAPIP());
  //if you used auto generated SSID, print it
  Serial.println(myWiFiManager->getConfigPortalSSID());
  //entered config mode, make led toggle faster
  ticker.attach(0.2, tick);
}

void wifiSetup(){
      pinMode(BUILTIN_LED, OUTPUT);
      ticker.attach(0.6, tick);
      //Se the AP Static IP
      IPAddress _ip = IPAddress(192, 168, 0, 1);
      IPAddress _gw = IPAddress(192, 168, 0, 1);
      IPAddress _sn = IPAddress(255, 255, 255, 0);
      if(drd.detect()){
        Serial.println("** double reset detect **");
        wifiManager.resetSettings();
        wifiManager.setAPStaticIPConfig(_ip, _gw, _sn);
        Serial.print("Resetting......");
        wifiManager.setAPCallback(configModeCallback);
        if (!wifiManager.autoConnect(WiFi_hostname)) {
          Serial.println("failed to connect and hit timeout");
          ESP.reset();
          delay(1000);
        }
        //if you get here you have connected to the WiFi
        Serial.println("connected...yeey :)");
        Serial.print("IP address:\t");
        Serial.println(WiFi.localIP());           // Send the IP address of the ESP8266 to the computer
      }
        ticker.detach();
        //keep LED off
        digitalWrite(BUILTIN_LED, HIGH);
    //WIFI END
  }
