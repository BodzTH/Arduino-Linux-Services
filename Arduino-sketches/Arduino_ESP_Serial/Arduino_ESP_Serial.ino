#include "DHT.h"
//#include <SoftwareSerial.h>
#define DHTPIN 2

// Uncomment whatever type you're using!
#define DHTTYPE DHT11 // DHT 11
//#define DHTTYPE DHT22 // DHT 22 (AM2302), AM2321
//#define DHTTYPE DHT21 // DHT 21 (AM2301)

//SoftwareSerial espSerial(2, 3);
DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
//  espSerial.begin(9600);
  dht.begin();
  delay(200);
}

void loop() {

   while (Serial.available()){
    String esp = Serial.readStringUntil('\n'); // Read until newline character
    // Switch-case block to handle different components
    if (esp == "LCD") {
      // Code to handle LCD component
    } else if (esp == "Motion Sensor") {
      // Code to handle Motion Sensor component
    } else if (esp == "TempHum") {
      // Code to handle Temperature and Humidity component
      float h = dht.readHumidity();
      float t = dht.readTemperature();
      
      String str = "coming from arduino: H= " + String(h) + " T= " + String(t);
      Serial.println(str);
    } else if (esp == "Moorse Code") {
      // Code to handle Morse Code component
    } else {
      Serial.println("Arduino if not working");
    }
   }
  delay(500); // Adjust delay as needed for stability
}
