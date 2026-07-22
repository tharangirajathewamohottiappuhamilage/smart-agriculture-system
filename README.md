# Smart Agriculture Monitoring and Irrigation System 🌱

## Soil Moisture Sensor Investigation

This is the first phase of the Smart Agriculture Monitoring and Irrigation System.

The objective is to understand sensor behaviour, collect measurements, perform calibration, and prepare the sensor for future IoT integration.

## Hardware

- ESP32 Development Board
- Soil Moisture Sensor
- Breadboard
- Jumper Wires
- USB Cable


## Sensor Working Principle

The soil moisture sensor measures changes in electrical conductivity caused by water content in soil.

The sensor output is converted into an ADC value by the ESP32.


## Calibration Experiment

The sensor was tested under different soil conditions.

| Condition | ADC Value Range |
|---|---|
| Dry soil | 0-200 |
| Moist soil | 200-1000 |
| Wet soil | Above 1000 |


## Observations

- ADC values increased when soil moisture increased.
- Multiple readings were averaged to reduce sensor noise.
- Calibration values were obtained experimentally.


## Software

- Visual Studio Code
- PlatformIO
- Arduino Framework
- C++


## Current Status

Completed:
- Sensor connection
- Data collection
- Calibration
- ESP32 implementation


## Future Work

- Add temperature and humidity monitoring
- Add water level monitoring
- Control irrigation pump automatically
- Send data through WiFi
- Store data in database
- Apply machine learning for irrigation prediction