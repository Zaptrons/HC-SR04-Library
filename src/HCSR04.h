/**
 * @file HCSR04.h
 * @brief A library for controlling the HC-SR04 ultrasonic distance sensor.
 * @author Your Name
 * @version 1.0.0
 */

#ifndef HCSR04_H
#define HCSR04_H

#include <Arduino.h>

/**
 * @class HCSR04
 * @brief Controls the HC-SR04 sensor to measure distance.
 * This class provides methods to initialize the sensor and get distance readings in both
 * centimeters and inches.
 */
class HCSR04
{
private:
    uint8_t _trigPin; ///< The pin connected to the Trig pin of the HC-SR04 sensor.
    uint8_t _echoPin; ///< The pin connected to the Echo pin of the HC-SR04 sensor.

    /**
     * @brief Sends a pulse to the sensor and measures the duration of the echo.
     * @return The duration of the echo pulse in microseconds. Returns 0 if no pulse is received within the timeout period.
     */
    unsigned long _getPulseDuration();

public:
    /**
     * @brief Constructor for the HCSR04 class.
     * @param trigPin The Arduino pin connected to the sensor's Trig pin.
     * @param echoPin The Arduino pin connected to the sensor's Echo pin.
     */
    HCSR04(uint8_t trigPin, uint8_t echoPin);

    /**
     * @brief Initializes the sensor pins.
     * Sets the trigger pin as an output and the echo pin as an input.
     */
    void begin();

    /**
     * @brief Measures the distance in centimeters.
     * @return The distance in centimeters. Returns -1.0 if the sensor times out.
     */
    float getDistanceCM();

    /**
     * @brief Measures the distance in inches.
     * @return The distance in inches. Returns -1.0 if the sensor times out.
     */
    float getDistanceIN();
};

#endif // HCSR04_H


