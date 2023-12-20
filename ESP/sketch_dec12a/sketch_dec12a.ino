#include <ESP8266WiFi.h>

const char* ssid = "Orange-ESP32";
const char* password = "arduinoesp32";
const char* serverIP = "192.168.1.2"; // Replace with your Linux system's IP
const int serverPort = 5008; // Replace with your chosen port number

WiFiClient client;

void setup() {
  Serial.begin(115200);
  WiFi.begin(ssid, password);
}

void loop() {
  if (WiFi.status() == WL_CONNECTED) {
    if (client.connected()) {
      String server = client.readString();
      if (server == "LCD") {
        if (Serial.available() > 0) {
          String s = Serial.readString();
          client.println(s);
        } else {
          client.println("No connection with Arduino");
        }
      } else if (server == "Motion Sensor") {
        if (Serial.available() > 0) {
          String s = Serial.readString();
          client.println(s);
        } else {
          client.println("No connection with Arduino");
        }
      } else if (server == "TempHum") {
        if (Serial.available() > 0) {
          String s = Serial.readString();
          client.println(s);
        } else {
          client.println("No connection with Arduino");
        }
      } else if (server == "Moorse Code") {
        if (Serial.available() > 0) {
          String s = Serial.readString();
          client.println(s);
        } else {
          client.println("No connection with Arduino");
        }
      } else {
        // Case handling from python
      }
      // If statement for TCP??
      if (client.connect(serverIP, serverPort)) {
        client.println("Hello, Server!"); // Send a test message if no serial data available
      }
    }
  } else {
    // Handle situations when WiFi is not connected
  }
}
