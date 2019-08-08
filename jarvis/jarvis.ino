/*
 * Jarvis
 * Created by: Gagan sharma
 */
#include "includes.h"
#include "index.h" //Our HTML webpage contents
#include "config.h" //Config file
#include "utils.h" //utils
#include "wifiSetup.h" //wifi setup
#include "setup.h" //setup

void loop() {
    webSocket.loop();
    serverHTTP.handleClient();
    server.handleClient();
    MDNS.update();
}
