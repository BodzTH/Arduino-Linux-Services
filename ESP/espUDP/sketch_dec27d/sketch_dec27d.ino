#include <ESP8266WiFi.h>
#include <ESP8266WiFiMulti.h>
#include <WiFiUdp.h>
#ifndef STASSID
#define STASSID "@_@"
#define STAPSK "esp01sardy"
#endif

const char* ssid = STASSID;
const char* password = STAPSK;

const char* host = "192.168.0.100";
const uint16_t port = 5008;

ESP8266WiFiMulti WiFiMulti;

void setup() {
  Serial.begin(9600);

  // We start by connecting to a WiFi network
  WiFi.mode(WIFI_STA);
  WiFiMulti.addAP(ssid, password);

  while (WiFiMulti.run() != WL_CONNECTED) {
    delay(500);
  }

  delay(1000);
}

void loop() {
  // Use WiFiUDP class for UDP communication
  WiFiUDP udpClient;

  if (!udpClient.begin(port)) {
    delay(5000);
    return;
  }

  IPAddress serverIP;
  serverIP.fromString(host);

  // This will send the request to the server
  udpClient.beginPacket(serverIP, port);
  udpClient.print("hello from ESP8266");
  udpClient.endPacket();

  delay(100);

  char packetBuffer[255];
  int packetSize = udpClient.parsePacket();
  if (packetSize) {
    int len = udpClient.read(packetBuffer, sizeof(packetBuffer));
    if (len > 0) {
      packetBuffer[len] = 0;
      char line = packetBuffer[0];
      if (line == '1') {
        Serial.write('D');
        delay(500);
        String s = Serial.readStringUntil('\r');
        udpClient.beginPacket(serverIP, port);
        udpClient.print(s);
        udpClient.endPacket();
        delay(500);
      } else if (line == '2') {
        String lcd = ""; // Store Morse data
        for (int i = 1; i < len; i++) { // Start from index 1, skipping the command identifier
          if (packetBuffer[i] != '\r') {
            lcd += packetBuffer[i]; // Append non-delimiter characters to Morse string
          } else {
            break; // Stop reading at the delimiter ('\r')
          }
        }
        Serial.print('L' + lcd); // Print 'B' and Morse data
        delay(500);
      } else if (line == '3') {
        String moorse = ""; // Store Morse data
        for (int i = 1; i < len; i++) { // Start from index 1, skipping the command identifier
          if (packetBuffer[i] != '\r') {
            moorse += packetBuffer[i]; // Append non-delimiter characters to Morse string
          } else {
            break; // Stop reading at the delimiter ('\r')
          }
        }
        Serial.print('B' + moorse); // Print 'B' and Morse data
        delay(500);
      } else if (line == '4') {
        Serial.write('M');
        delay(500);
        String s = Serial.readStringUntil('\r');
        udpClient.beginPacket(serverIP, port);
        udpClient.print(s);
        udpClient.endPacket();
        delay(500);
      } else {
        udpClient.beginPacket(serverIP, port);
        udpClient.print("Wrong prompt");
        udpClient.endPacket();
      }
    }
  }
  udpClient.stop();

  delay(6000);
}
