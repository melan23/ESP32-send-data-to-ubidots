
//DHT declarations

#include <dht.h> 
dht sensor;
int readResp;
float hum, tem;
const int dhtPin = 23;

#define DHT11
//#define DHT22

// Connections

#include <WiFi.h>
#include <HTTPClient.h>

const char* ssid     = "melani";
const char* password = "meongmeong";

int status = WL_IDLE_STATUS;
char server[] = "http://things.ubidots.com";
const int port = 80;
String token = "BBFF-OIiW99j5hQL3y64B1LLcvAmZQv5HcW";

String humString, temString;

WiFiClient client;

// Ubidots
String DEVICE_LABEL = "pemantau-suhu";
String humidityVarLabel = "suhu";
String temperatureVarLabel = "suhu";

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  wifiInit();
}

void loop() {
  readDHT();
  sendData();
  delay(10000);
}
