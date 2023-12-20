#include "DHT.h"
#include <SoftwareSerial.h>

#define DHTPIN 2

// Uncomment whatever type you're using!
#define DHTTYPE DHT11 // DHT 11
//#define DHTTYPE DHT22 // DHT 22 (AM2302), AM2321
//#define DHTTYPE DHT21 // DHT 21 (AM2301)

SoftwareSerial espSerial(1, 3);
DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(115200);
  espSerial.begin(115200);
  dht.begin();
  delay(200);
}

void loop() {
  if (espSerial.available() > 0) {
    String server = espSerial.readStringUntil('\n'); // Read until newline character
    
    // Switch-case block to handle different components
    if (server == "LCD") {
      // Code to handle LCD component
    } else if (server == "Motion Sensor") {
      // Code to handle Motion Sensor component
    } else if (server == "TempHum") {
      // Code to handle Temperature and Humidity component
      float h = dht.readHumidity();
      float t = dht.readTemperature();
      
      Serial.print("H: ");
      Serial.print(h);
      Serial.print("% ");
      Serial.print("T: ");
      Serial.print(t);
      Serial.print("C");
      
      String str = "coming from arduino: H= " + String(h) + " T= " + String(t);
      espSerial.println(str);
    } else if (server == "Moorse Code") {
      // Code to handle Morse Code component
    } else {
      // Handle cases where the server string doesn't match any known components
      // You can add default behavior or error handling here
    }
  }

  delay(200); // Adjust delay as needed for stability
}
