# HC-SR04-Library

An Arduino library for the HC-SR04 ultrasonic distance sensor, providing a simple and efficient way to measure distance.

## Features

-   Easy-to-use constructor.
-   Accurate distance measurement in centimeters.
-   Accurate distance measurement in inches.
-   Robust and simple code structure.

## Installation

### 1. Using the Arduino Library Manager

1.  Open the Arduino IDE.
2.  Go to `Sketch > Include Library > Manage Libraries...`.
3.  Search for "HC-SR04-Library".
4.  Click on "Install".

### 2. Installing in PlatformIO

1.  Open your project's `platformio.ini` file.
2.  In the `[env]` section for your board, find the `lib_deps` line and add the library's GitHub address.

    ```ini
    [env:uno]
    platform = atmelavr
    board = uno
    framework = arduino
    lib_deps =
        [https://github.com/Zaptrons/HC-SR04-Library.git#v1.0.0](https://github.com/Zaptrons/HC-SR04-Library.git#v1.0.0)
    ```

    *Note:* Replace `YourUsername` with your GitHub username and `v1.0.0` with your desired version tag.

### 3. Manual Installation

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
```
## Contributing
We welcome contributions! If you have any suggestions, bug reports, or feature requests, please open an issue or create a pull request on the GitHub repository.

## License
This library is released under the MIT License.