#include <ESP8266WiFi.h>

const char* ssid = "Orange-ESP32";
const char* password = "arduinoesp32";
const char* serverIP = "192.168.1.2";
const int serverPort = 5008;

WiFiClient client;

void setup() {
  WiFi.begin(ssid, password);
  Serial.begin(9600);
  while(WiFi.status() != WL_CONNECTED){
    delay(100);
  }
  if (client.connect(serverIP, serverPort)) {
  }
}

void loop() {
  if (WiFi.status() == WL_CONNECTED) {
    while (client.connected()) {
      if (client.available()) {
        // Read data from the server
        String serverData = client.readStringUntil('\n');
        delay(50);
        String ard;
        if(serverData == "TempHum"){
           if(Serial.available()){
            Serial.write("TempHum");
            ard = Serial.readStringUntil('\n');
            }
         client.println(ard);
          }
          else {
            client.println("No input");
            delay(2000);
          }
      }
      // Additional code for other functionalities can be added here
    } else {
      client.connect(serverIP, serverPort);
    }
  } 
}
