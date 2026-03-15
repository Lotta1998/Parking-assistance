# Project Description: Arduino Parking Assistance System

This project is an Arduino-based parking assistance system designed to help a driver detect obstacles while parking. The system uses an ultrasonic distance sensor to measure how far an object is from the vehicle.

Depending on the measured distance, three LEDs indicate the safety level:

- **Green LED** lights up when the distance is greater than 40 cm, meaning it is safe.
- **Yellow LED** lights up when the distance is between 40 cm and 10 cm, indicating caution.
- **Red LED** lights up when the distance is less than 10 cm, warning that the vehicle is very close to an obstacle.

Additionally, a buzzer produces sound signals that become more urgent as the distance decreases. This helps the user react quickly without constantly looking at the sensor.