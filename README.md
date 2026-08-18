## adaptive-traffic-system
Arduino based traffic light system with adaptive left turns

# Features

- Red, yellow, and green traffic lights
- Left turning signals
- Pedestrian crossing system
- Pedestrian button
- Changing RGB pedestrian indicator
- Ultrasonic sensor vehicle detection
- Adaptively adjusted turning time when a vehicle is detected

![Logo](https://github.com/vryanu/adaptive-traffic-system/blob/main/pictures/Picture.png?raw=true)

## Hardware

- Arduino Uno
- HC-SR04 ultrasonic sensor
- LEDs
- RGB LED
- Push button
- Resistors

## Software

- Arduino
- C++
- I used TinkerCad

## How It Works

The HC-SR04 sensor measures the distance between the sensor and
an object, if an object is detected within 53 inches in, the
merging lane the turning phase changes from 2 seconds to 5 seconds.

![Logo](https://github.com/vryanu/adaptive-traffic-system/blob/main/pictures/Picture%20with%20sensor.png?raw=true)
