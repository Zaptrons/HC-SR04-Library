# HC-SR04-Library

An Arduino library for the HC-SR04 ultrasonic distance sensor, providing a simple and efficient way to measure distance.

## Features

-   Easy to use constructor.
-   Accurate distance measurement in centimeters.
-   Accurate distance measurement in inches.
-   Robust and simple code structure.

## Installation

### Using the Arduino Library Manager

1.  Open the Arduino IDE.
2.  Go to `Sketch > Include Library > Manage Libraries...`.
3.  Search for "HC-SR04-Library".
4.  Click on "Install".

### Manual Installation

1.  Download the repository as a ZIP file.
2.  In the Arduino IDE, go to `Sketch > Include Library > Add .ZIP Library...`.
3.  Select the downloaded ZIP file.

## Getting Started

### Hardware Connections

Connect the HC-SR04 sensor to your Arduino board as follows:

| HC-SR04 Pin | Arduino Pin |
| ----------- | ----------- |
| VCC         | 5V          |
| Trig        | Your chosen Trig Pin |
| Echo        | Your chosen Echo Pin |
| GND         | GND         |

### Code Example

Here is a simple example to get started:

```cpp
#include "HCSR04.h"

// Define the trigger and echo pins
const uint8_t TRIG_PIN = 9;
const uint8_t ECHO_PIN = 10;

// Create an instance of the library
HCSR04 sensor(TRIG_PIN, ECHO_PIN);

void setup() {
    Serial.begin(9600);
    sensor.begin();
}

void loop() {
    // Get distance in centimeters
    float distance_cm = sensor.getDistanceCM();
    if (distance_cm != -1.0) {
        Serial.print("Distance in CM: ");
        Serial.println(distance_cm);
    } else {
        Serial.println("Measurement timed out.");
    }

    delay(1000); // Wait for a second before the next measurement
}