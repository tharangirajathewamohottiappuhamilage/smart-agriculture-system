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

## Hardware Setup

![Soil Moisture Sensor Setup](images/soil_sensor_setup.jpeg)

## Wiring Diagram

![Soil Moisture Sensor wiring](images/soil_sensor_wiring_diagram.jpeg)

## Serial Monitor Output

![Serial Output](images/soil_sensor_serial_output.png)


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


## 2. DHT11 Temperature and Humidity Sensor

### Objective

The DHT11 sensor was investigated to understand its temperature and relative humidity measurements, short-term stability, response to environmental changes, and recovery behavior.

The sensor was tested independently using an ESP32 before integrating it with the complete Smart Agriculture Monitoring and Irrigation System.

### Hardware

* **Microcontroller:** ESP32
* **Sensor:** DHT11
* **Temperature unit:** °C
* **Humidity unit:** %RH
* **Communication:** Digital
* **DHT11 DATA pin:** GPIO 17

### DHT11 Wiring

The DHT11 was connected to the ESP32 as follows:

| DHT11 Pin | ESP32   |
| --------- | ------  |
| VCC       | 3.3V    |
| DATA      | GPIO 17 |
| GND       | GND     |

![DHT11 Setup](images/dht11_setup.jpeg)

![DHT11 Wiring](images/dht11_wiring_diagram.jpeg)

### Software

The DHT11 was programmed using PlatformIO and the Arduino framework.

The following libraries were used:

* DHT sensor library
* Adafruit Unified Sensor

The sensor was configured as:

```cpp
#define DHT_PIN 17
#define DHT_TYPE DHT11
```

The ESP32 reads temperature and relative humidity from the DHT11 at a sampling interval of approximately 2 seconds.

### Data Format

The sensor output was changed to a CSV-compatible format to simplify data collection and later analysis:

```text
Temperature_C,Humidity_RH
25.80,53.40
25.90,53.40
25.90,53.30
```

### Serial Monitor Output

The DHT11 measurements were observed through the PlatformIO Serial Monitor.

![DHT11 Serial Output](images/dht11_serial_output.png)

---

## DHT11 Experiments

Two experiments were performed to characterize the behavior of the sensor.

### Experiment 1 — Stable Room Conditions

#### Objective

The first experiment investigated the short-term stability of the DHT11 under relatively stable indoor room conditions.

#### Procedure

The DHT11 was left undisturbed while temperature and relative humidity measurements were collected.

The collected measurements are stored in:

`data/dht11/experiment1_stable.csv`

#### Initial Observation

The measurements showed highly stable temperature readings during the observation period. Relative humidity showed only small short-term fluctuations.

The initial analysis showed:

| Measurement           |     Result |
| --------------------- | ---------: |
| Temperature minimum   |   26.70 °C |
| Temperature maximum   |   26.70 °C |
| Temperature variation |    0.00 °C |
| Humidity minimum      |  52.30 %RH |
| Humidity maximum      |  52.60 %RH |
| Humidity variation    |   0.30 %RH |
| Average humidity      | ≈52.46 %RH |

#### Interpretation

The results indicate that the sensor produced stable repeated measurements under relatively stable environmental conditions.

However, stability should not be interpreted as measurement accuracy. This experiment evaluates short-term consistency rather than absolute accuracy because no calibrated reference instrument was used.

---

### Experiment 2 — Environmental Response and Recovery

#### Objective

The second experiment investigated how the DHT11 responds to a temporary environmental disturbance and how its measurements change after the disturbance is removed.

#### Experimental Procedure

The experiment was divided into three phases:

| Phase                      |     Time | Condition                                |
| -------------------------- | -------: | ---------------------------------------- |
| Phase 1 — Normal           |  0–3 min | Sensor left undisturbed                  |
| Phase 2 — Hand near sensor |  3–5 min | Hand placed near the sensor              |
| Phase 3 — Recovery         | 5–10 min | Hand removed and sensor left undisturbed |

The sampling interval was approximately **2 seconds**. A total of **299 measurements** were collected over approximately **9 minutes 56 seconds**.

The complete dataset is stored in:

`data/dht11/experiment2_response_recovery.csv`

#### Statistical Results

| Phase       | Temperature | Temperature | Temperature | Humidity | Humidity  | Humidity     |
|             | Min (°C)    | Max (°C)    | Average (°C)| Min(%RH) | Max (%RH) | Average (%RH)|
| ------------| ----------: | ----------: | ----------: | -------: | --------: | -----------: |
| Normal      |        25.8 |      26.4   |      26.277 |     52.4 |      53.4 |       52.694 |
| Hand near   |        26.4 |        27.1 |      26.787 |     52.4 |    65.7   |       61.953 |
| sensor      |             |             |             |          |           |              |
| Recovery    |        26.6 |        27.1 |     26.852  |     53.1 |    61.4   |       54.100 |

#### Temperature Response

During the normal phase, the average temperature was approximately **26.277 °C**. When the hand was placed near the sensor, the temperature increased and reached a maximum of **27.1 °C**.

The maximum temperature increase relative to the normal-phase average was approximately:

**27.1 − 26.277 = 0.823 °C**

During the recovery phase, the temperature gradually moved toward the initial room condition, reaching approximately **26.7 °C** at the end of the experiment.

![DHT11 Temperature Response and Recovery](images/dht11_experiment2_temperature.png)

#### Humidity Response

The normal-phase average relative humidity was approximately **52.694 %RH**.

When the hand was placed near the sensor, humidity increased substantially and reached a maximum of **65.7 %RH**.

The maximum increase relative to the normal-phase average was approximately:

**65.7 − 52.694 = 13.006 percentage points**

After the hand was removed, the humidity gradually decreased toward the original environmental condition. The final measurement was approximately **53.4 %RH**.

![DHT11 Humidity Response and Recovery](images/dht11_experiment2_humidity.png)

#### Engineering Interpretation

The experiment demonstrated that the DHT11 responds measurably to a temporary environmental disturbance.

The temperature increased by approximately **0.823 °C** relative to the normal-phase average, while relative humidity increased by approximately **13.006 percentage points**. The humidity response was considerably more pronounced than the temperature response.

After the hand was removed, both measurements gradually moved toward the original environmental conditions. This demonstrates the sensor's environmental response and recovery behavior.

The results indicate that the DHT11 can detect short-term changes in temperature and relative humidity and therefore has potential for environmental monitoring in the Smart Agriculture system.

However, these experiments demonstrate **sensor response and short-term behavior, not absolute measurement accuracy**. Accuracy would require comparison against a calibrated reference instrument.

#### Data Analysis Files

The processed data and statistical results are available in:

```text
data/dht11/
├── experiment1_stable.csv
└── experiment2_response_recovery.csv
```

The analysis produced:

* Temperature vs. Time graph
* Humidity vs. Time graph
* Phase-by-phase minimum, maximum, average, and range
* Response magnitude relative to the normal baseline
* Recovery observations


### DHT11 Characterization Status

* [x] Understand DHT11 operation
* [x] Connect DHT11 to ESP32
* [x] Collect stable-condition measurements
* [x] Test environmental response
* [x] Test recovery behavior
* [x] Store measurements as CSV
* [x] Document hardware setup
* [x] Document wiring
* [x] Complete statistical analysis
* [x] Generate response graphs
* [ ] Test sensor in a different location
