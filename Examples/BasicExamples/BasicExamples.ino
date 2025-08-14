#include "HCSR04.h"

// Define the trigger and echo pins for the sensor
const uint8_t TRIG_PIN = 9;
const uint8_t ECHO_PIN = 10;

// Create an instance of the HCSR04 library
HCSR04 sensor(TRIG_PIN, ECHO_PIN);

void setup() {
  // Start the serial communication to print the distance
  Serial.begin(9600);
  while (!Serial); // Wait for the serial port to connect (only for boards with native USB)

  // Initialize the sensor pins
  sensor.begin();
  Serial.println("HC-SR04 Sensor Test");
}

void loop() {
  // Get the distance in centimeters
  float distance_cm = sensor.getDistanceCM();
  
  if (distance_cm != -1.0) {
    // If the measurement is valid, print the result
    Serial.print("Distance in CM: ");
    Serial.println(distance_cm);
  } else {
    // If the measurement timed out, print an error message
    Serial.println("Measurement timed out or out of range.");
  }
  
  delay(1000); // Wait for a second before the next measurement
}