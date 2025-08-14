#include "HCSR04.h"

// Constants for the speed of sound.
// These are defined as `static const` to make them internal to this file and prevent
// potential conflicts with other libraries.
static const float SOUND_SPEED_CM = 0.0343; // Speed of sound in cm/us
static const float SOUND_SPEED_IN = 0.0135; // Speed of sound in inches/us

// A timeout value for the pulseIn() function.
// Set to 30ms, which is a safe value for typical distance measurements.
static const unsigned long PULSE_TIMEOUT_US = 30000;

/**
 * @brief Constructor for the HCSR04 class.
 * @param trigPin The Arduino pin connected to the sensor's Trig pin.
 * @param echoPin The Arduino pin connected to the sensor's Echo pin.
 */
HCSR04::HCSR04(uint8_t trigPin, uint8_t echoPin) {
    _trigPin = trigPin;
    _echoPin = echoPin;
}

/**
 * @brief Initializes the sensor pins.
 * Sets the trigger pin as an output and the echo pin as an input.
 */
void HCSR04::begin() {
    pinMode(_trigPin, OUTPUT);
    pinMode(_echoPin, INPUT);
}

/**
 * @brief Sends a pulse to the sensor and measures the duration of the echo.
 * This is a private helper function to avoid code duplication.
 * @return The duration of the echo pulse in microseconds.
 */
unsigned long HCSR04::_getPulseDuration() {
    // Clears the trigPin to ensure a clean start
    digitalWrite(_trigPin, LOW);
    delayMicroseconds(2);

    // Sends a 10us pulse to trigger the sensor
    digitalWrite(_trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(_trigPin, LOW);

    // Reads the echo pin, returning the sound wave travel time in microseconds
    return pulseIn(_echoPin, HIGH, PULSE_TIMEOUT_US);
}

/**
 * @brief Measures the distance in centimeters.
 * @return The distance in centimeters. Returns -1.0 if the sensor times out.
 */
float HCSR04::getDistanceCM() {
    unsigned long duration = _getPulseDuration();

    // If the pulse times out, return an error value.
    if (duration == 0) {
        return -1.0;
    }

    // Calculate the distance: (time * speed) / 2 (since the pulse travels to the object and back)
    float distance = (duration * SOUND_SPEED_CM) / 2.0;
    return distance;
}

/**
 * @brief Measures the distance in inches.
 * @return The distance in inches. Returns -1.0 if the sensor times out.
 */
float HCSR04::getDistanceIN() {
    unsigned long duration = _getPulseDuration();

    // If the pulse times out, return an error value.
    if (duration == 0) {
        return -1.0;
    }

    // Calculate the distance: (time * speed) / 2
    float distance = (duration * SOUND_SPEED_IN) / 2.0;
    return distance;
}