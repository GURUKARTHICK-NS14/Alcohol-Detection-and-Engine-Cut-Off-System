# Alcohol Detection and Engine Cut-Off System

## Overview
This project detects alcohol levels from the driver's breath using an MQ-3 alcohol sensor. 
If the alcohol level exceeds a predefined threshold, the system automatically cuts off 
the engine power and sends an alert message to the vehicle owner.

## Components Used
- Arduino Uno
- MQ-3 Alcohol Sensor
- GSM Module
- Relay Module
- Buzzer
- Power Supply

## Working
1. The alcohol sensor detects alcohol from the driver's breath.
2. Arduino processes the sensor data.
3. If alcohol level exceeds the limit:
   - Engine power is cut off using relay
   - Alert message is sent to the vehicle owner.

## Applications
- Prevents drunk driving
- Improves road safety
