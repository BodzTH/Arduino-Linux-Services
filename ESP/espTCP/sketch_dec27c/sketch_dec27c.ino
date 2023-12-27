/*
    This sketch sends a string to a TCP server, and prints a one-line response.
    You must run a TCP server in your local network.
    For example, on Linux you can use this command: nc -v -l 3000
*/

#include <ESP8266WiFi.h>
#include <ESP8266WiFiMulti.h>

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
  static bool wait = false;
  // Use WiFiClient class to create TCP connections
  WiFiClient client;

  if (!client.connect(host, port)) {
    delay(5000);
    return;
  }

  // This will send the request to the server
  client.print("hello from ESP8266");
  delay(100);
  // read back one line from server
  char line = client.read();
  if (line == '1') {
    Serial.write('D');
    delay(500);
    String s = Serial.readStringUntil('\r');
    client.print(s);
    delay(500);
  }
  else if (line == '2') {
    String lcd = client.readStringUntil('\r');
    Serial.print('L' + lcd);
    delay(500);
  }
  else if (line == '3') {
    String moorse = client.readStringUntil('\r');
    Serial.print('B' + moorse);
    char s = Serial.read();
    delay(300);
    client.print(s);
    delay(500);
  }
  else if (line == '4') {
    Serial.write('M');
    delay(500);
    String s = Serial.readStringUntil('\r');
    client.print(s);
    delay(500);
  }

  else {
    client.print("Wrong prompt");
  }

  client.print("closing connection");
  client.stop();
  
  delay(6000);
}
