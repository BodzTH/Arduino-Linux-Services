#include <ESP8266WiFi.h>

const char* ssid = "Orange-ESP32";
const char* password = "arduinoesp32";
const char* serverIP = "192.168.1.2"; // Replace with your Linux system's IP
const int serverPort = 5008; // Replace with your chosen port number

WiFiClient client;

void setup() {
  Serial.begin(115200);
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    
  }

  
}

void loop() {
  if (WiFi.status() == WL_CONNECTED) {
    if (!client.connected()) {
      if (client.connect(serverIP, serverPort)) {
        while (Serial.available() > 0) {
          String s = Serial.readString();
          client.println(s);
        }
        client.println("Hello, Server!"); // Send a test message if no serial data available
      } else {
        client.println("Connection to server failed");
      }
    }
  } else {
    
    WiFi.begin(ssid, password);
    while (WiFi.status() != WL_CONNECTED) {
      delay(500);
    }
  }
}
