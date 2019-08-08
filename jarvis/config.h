int myPins[] = {5,4,0,2,14,12,13,15};
#define WiFi_hostname "J.A.R.V.I.S"
#define SerialSpeed 115200
#define LED_RED     15
#define LED_GREEN   12
#define LED_BLUE    13
#define USE_SERIAL Serial
BearSSL::ESP8266WebServerSecure server(443);
ESP8266WebServer serverHTTP(80);
WebSocketsServer webSocket = WebSocketsServer(81);
static const char serverCert[] PROGMEM = R"EOF(
-----BEGIN CERTIFICATE-----
MIIC6jCCAlOgAwIBAgIUKBaL83MmaYs6aZKQIA3qo9aq/BswDQYJKoZIhvcNAQEL
BQAwejELMAkGA1UEBhMCUk8xCjAIBgNVBAgMAUIxEjAQBgNVBAcMCUJ1Y2hhcmVz
dDEbMBkGA1UECgwST25lVHJhbnNpc3RvciBbUk9dMRYwFAYDVQQLDA1PbmVUcmFu
c2lzdG9yMRYwFAYDVQQDDA1lc3A4MjY2LmxvY2FsMB4XDTE5MDgwODE4NDM0NVoX
DTIwMDgwNzE4NDM0NVowejELMAkGA1UEBhMCUk8xCjAIBgNVBAgMAUIxEjAQBgNV
BAcMCUJ1Y2hhcmVzdDEbMBkGA1UECgwST25lVHJhbnNpc3RvciBbUk9dMRYwFAYD
VQQLDA1PbmVUcmFuc2lzdG9yMRYwFAYDVQQDDA1lc3A4MjY2LmxvY2FsMIGfMA0G
CSqGSIb3DQEBAQUAA4GNADCBiQKBgQDePcIXIoNz8Oc6c6XBcLIsZDyx86s+mLCI
mkEHS7XVw8NsH0bWoblWZWxWrZ9W8DKToVsdow/k7CsZ+MmdJg0fQeNmcb8kAsMi
ucr5rTwhMFKZ73nZ6YZ+X08UpGeKl5w0986p9tkcAtYVZBYvPI4BLZjlzE/RM2Qr
3OuiOYi6fwIDAQABo20wazAdBgNVHQ4EFgQUNZ9XsMwx35egz89+wyFKyWAYOZ0w
HwYDVR0jBBgwFoAUNZ9XsMwx35egz89+wyFKyWAYOZ0wDwYDVR0TAQH/BAUwAwEB
/zAYBgNVHREEETAPgg1lc3A4MjY2LmxvY2FsMA0GCSqGSIb3DQEBCwUAA4GBAMli
nR9haH8jdVgj5ndxdzJsTPTPRfBukwSYxTa18t+rz9WJs9tSqqDsqsiQvIhK3AGk
0eUW4xEcD68DTJ2ZsV4ss81qG2Cp4F22ah0BGh5EnRtjGCO5Y42W2ocVXRBOje8x
OejfJToGki7WK4JY9vBMpgm1HW2XgparoAhkYtio
-----END CERTIFICATE-----

)EOF";

static const char serverKey[] PROGMEM =  R"EOF(
-----BEGIN PRIVATE KEY-----
MIICdwIBADANBgkqhkiG9w0BAQEFAASCAmEwggJdAgEAAoGBAN49whcig3Pw5zpz
pcFwsixkPLHzqz6YsIiaQQdLtdXDw2wfRtahuVZlbFatn1bwMpOhWx2jD+TsKxn4
yZ0mDR9B42ZxvyQCwyK5yvmtPCEwUpnvednphn5fTxSkZ4qXnDT3zqn22RwC1hVk
Fi88jgEtmOXMT9EzZCvc66I5iLp/AgMBAAECgYEAwK5ivJQbzEWs9CyYJWKD16EA
Tniom5jeVVEH2D9342Ha6L8lN6j3e0Rr7aqSX1nZP83Bpaxed2ea5uWgRzNaY4VG
bAjBql2xqi/Cv6m91eKBO7Rs6XilTuYC5mVMirYjk4KWsV9/8Wf3UJQyUiLBNo2O
Hs8MziMnun2CTUAAPQECQQD5UrzEpwqfPtw3EVXmWHMhyEi2FesmHHd+G8J6yrCi
V0rWXs2ivfDfKnLO2f1AyMW9RzkmVhUYBCGaL3pyVUhfAkEA5DFbhOp0L4Fts6HV
5LVwBi6hXBj9SCsdX73aVaURvdd/JLBhA2qfZgYHtKJVGmkUqU0PJn2qzmClOYpQ
B0xB4QJBALQbh9AL14mIUG7bcBFRjgI2fAhFtzQ11kBcb1Zi+8yagK5xl91blxiv
wnYZVXCqWOZOAEPoZZ6OxXNrnunfH8MCQGiDMqdtukkHvnbHaG+Xqfcq5DyKNXcY
SBvRmG4hbD7GtDTZk5U9AER5/o18y/2MoynnYUj/xXtASGxSLNUq2AECQEGzh2WW
5+6CMFcqMA/7nxazba8O+fXmPzGEU8EyB5FTh4B9Bh4sqWnL4r2AEy2p+DINScKm
F60R++Ki95+scIY=
-----END PRIVATE KEY-----

)EOF";
