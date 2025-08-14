#include "HCSR04.h"

// Define sensor and LED pins
const uint8_t TRIG_PIN = 9;
const uint8_t ECHO_PIN = 10;
const uint8_t LED_PIN = 13; // Using the built-in LED on most Arduino boards

// Create the sensor object
HCSR04 sensor(TRIG_PIN, ECHO_PIN);

void setup() {
  Serial.begin(9600);
  while (!Serial);

  sensor.begin();
  pinMode(LED_PIN, OUTPUT);
  Serial.println("Advanced HC-SR04 Example with LED");
}

void loop() {
  float distance_cm = sensor.getDistanceCM();
  
  if (distance_cm != -1.0) {
    Serial.print("Distance: ");
    Serial.print(distance_cm);
    Serial.println(" cm");
    
    // Check if the object is within a certain range (e.g., less than 20 cm)
    if (distance_cm < 20.0) {
      digitalWrite(LED_PIN, HIGH); // Turn the LED on
    } else {
      digitalWrite(LED_PIN, LOW); // Turn the LED off
    }
  } else {
    Serial.println("Measurement timed out.");
    digitalWrite(LED_PIN, LOW); // Ensure LED is off on timeout
  }
  
  delay(500); // Shorter delay for a more responsive example
}