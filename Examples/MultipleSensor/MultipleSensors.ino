#include "HCSR04.h"

// Define pins for two separate sensors
const uint8_t TRIG_PIN1 = 9;
const uint8_t ECHO_PIN1 = 10;

const uint8_t TRIG_PIN2 = 11;
const uint8_t ECHO_PIN2 = 12;

// Create two instances of the library, one for each sensor
HCSR04 sensor1(TRIG_PIN1, ECHO_PIN1);
HCSR04 sensor2(TRIG_PIN2, ECHO_PIN2);

void setup() {
  Serial.begin(9600);
  while (!Serial);

  // Initialize both sensors
  sensor1.begin();
  sensor2.begin();

  Serial.println("Multiple HC-SR04 Sensors Example");
}

void loop() {
  // Get distance from the first sensor
  float distance1_cm = sensor1.getDistanceCM();
  if (distance1_cm != -1.0) {
    Serial.print("Sensor 1 Distance: ");
    Serial.print(distance1_cm);
    Serial.println(" cm");
  } else {
    Serial.println("Sensor 1 Measurement timed out.");
  }

  // Get distance from the second sensor
  float distance2_cm = sensor2.getDistanceCM();
  if (distance2_cm != -1.0) {
    Serial.print("Sensor 2 Distance: ");
    Serial.print(distance2_cm);
    Serial.println(" cm");
  } else {
    Serial.println("Sensor 2 Measurement timed out.");
  }
  
  Serial.println("--------------------"); // Separator for better readability
  delay(1000);
}