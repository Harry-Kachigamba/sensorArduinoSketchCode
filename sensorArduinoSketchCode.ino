#include "DHT.h" // A library for DHT(Digital Humidity, Temperature)  sensors

// Moisture Sensor Definitions
const int dry = 0;
const int wet = 300;
const int moisturePin = A0;

// DHT11 Sensor Definitions
#define dhtPin 12
#define dhtType DHT11

DHT dht(dhtPin, dhtType); // Initializing the DHT library

// Measurements Variables
float humidityVal;
float tempValC;

void setup() {
  Serial.begin(9600); // initializing baud rate serial communication
  dht.begin();
}

void loop() {
  // Reading Moisture Data
  int sensorVal = analogRead(moisturePin);
  int percentageMoisture = map(sensorVal, wet, dry, 100, 0);

  // Reading DHT11 sensor data
  humidityVal = dht.readHumidity();
  tempValC = dht.readTemperature();

  // Checking if DHT sensor data is valid
  if (isnan(humidityVal) || isnan(tempValC)) {
    Serial.println("Reading DHT sensor failed");
    return;
  }

  // Output data to Searial Monitor
  // Moisture Sensor Output
 Serial.print("Soil Moisture: ");
 Serial.println(percentageMoisture);

  // DHT11 Sensor Output
 Serial.print("Humidity: ");
 Serial.println(humidityVal);

 Serial.print("Temperature: ");
 Serial.println(tempValC);

  delay(50000);
}