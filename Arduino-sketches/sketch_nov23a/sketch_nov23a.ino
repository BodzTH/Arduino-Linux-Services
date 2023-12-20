#include <SoftwareSerial.h>
#include <DHT.h>

#define DHTPIN 2  // Replace with the actual pin connected to the DHT sensor
#define DHTTYPE DHT11  // Replace with the sensor type (DHT11, DHT21, DHT22)

SoftwareSerial ESPSerial(16, 17); // RX pin 16, TX pin 17

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600); // Start Serial for debugging
  ESPSerial.begin(9600);

  dht.begin();
}

void loop() {
  if (ESPSerial.available()) {
    String command = ESPSerial.readStringUntil('\n');

    if (command == "read_sensor") {
      float temperature = dht.readTemperature();
      float humidity = dht.readHumidity();

      if (isnan(temperature) || isnan(humidity)) {
        ESPSerial.println("Failed to read from sensor");
      } else {
        ESPSerial.print("Temperature:");
        ESPSerial.print(temperature);
        ESPSerial.print(",Humidity:");
        ESPSerial.println(humidity);
      }
    }
  }
}
