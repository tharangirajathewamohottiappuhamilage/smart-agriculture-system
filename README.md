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


| Phase | Temperature Min (°C) | Temperature Max (°C) | Temperature Average (°C) | Humidity Min (%RH) | Humidity Max (%RH) | Humidity Average (%RH) |
|---|---:|---:|---:|---:|---:|---:|
| Normal | 25.8 | 26.4 | 26.277 | 52.4 | 53.4 | 52.694 |
| Hand near sensor | 26.4 | 27.1 | 26.787 | 52.4 | 65.7 | 61.953 |
| Recovery | 26.6 | 27.1 | 26.852 | 53.1 | 61.4 | 54.100 |


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


### Experiment 3 — Environmental Variation at Different Locations

#### Objective

The third experiment investigated how the DHT11 temperature and humidity sensor responds to different environmental conditions by testing the sensor at two different locations.

The purpose was to determine whether the sensor measurements change when the surrounding environmental conditions change and to observe the stability of the measurements at each location.

#### Experimental Procedure

The experiment was performed in two locations:

| Phase      |     Time | Location   | Condition                                 |
| ---------- | -------: | ---------- | ----------------------------------------- |
| Location A |  0–5 min | Location A | Sensor placed at the first test location  |
| Location B | 5–20 min | Location B | Sensor moved to a different room/location |

The sensor was connected to the ESP32 and measurements were collected continuously.

The sampling interval was approximately **2 seconds**.

A total of **602 measurements** were collected:

* **Location A:** 150 measurements
* **Location B:** 452 measurements

The complete dataset is stored in:

`data/dht11/experiment3_different_location.csv`

#### Results

The measurements showed clear differences between the two locations.

At **Location A**, the temperature remained approximately between **25.1 °C and 25.3 °C**, while relative humidity was approximately between **47.4 %RH and 48.0 %RH**.

After the sensor was moved to **Location B**, the temperature decreased gradually. The measurements reached approximately **24.1 °C**, showing that Location B was cooler than Location A.

The humidity at Location B remained relatively stable, generally around **47.9–48.2 %RH**.

#### Statistical Analysis

The main statistics considered in this experiment were the minimum, maximum, average, and range of the temperature and humidity measurements.

| Location   | Measurement      | Minimum | Maximum | Range | Average |
| ---------- | ---------------- | ------: | ------: | ----: | ------: |
| Location A | Temperature (°C) |   25.10 |   25.30 |  0.20 |  ≈25.20 |
| Location A | Humidity (%RH)   |   47.40 |   48.00 |  0.60 |  ≈47.75 |
| Location B | Temperature (°C) |   24.10 |   24.80 |  0.70 |  ≈24.30 |
| Location B | Humidity (%RH)   |   47.70 |   48.20 |  0.50 |  ≈47.98 |

> **Note:** The averages are calculated from the collected measurements and may be displayed rounded to two decimal places.

#### Observations

At Location A, the temperature remained relatively stable during the first five minutes, with only a small variation between approximately 25.1 °C and 25.3 °C.

When the sensor was moved to Location B, the temperature decreased noticeably. The temperature gradually changed from approximately 24.7–24.8 °C to approximately 24.1 °C.

The humidity showed much less variation compared with the temperature. At Location A, humidity gradually decreased from approximately 48.0 %RH to around 47.4 %RH. At Location B, humidity remained relatively stable around 47.9–48.2 %RH.

These results demonstrate that the DHT11 can detect differences in environmental temperature between locations.

#### Engineering Interpretation

The experiment demonstrated that the DHT11 measurements are affected by the surrounding environmental conditions.

The most significant change was observed in temperature. Location A was warmer, with measurements around **25.1–25.3 °C**, whereas Location B produced lower temperature measurements, reaching approximately **24.1 °C**.

The humidity measurements showed considerably smaller changes. This indicates that the humidity conditions at the two locations were relatively similar even though their temperatures differed.

The gradual temperature change after moving the sensor also demonstrates that the DHT11 does not necessarily change immediately to the final environmental value. The sensor requires some time to respond to and stabilize under the new environmental conditions.

This behavior is important for the Smart Agriculture Monitoring and Irrigation System because environmental sensors may need a stabilization period after installation or movement before their measurements are interpreted by the monitoring or machine-learning components.

As with the previous experiments, this experiment does **not establish the absolute measurement accuracy** of the DHT11 because the sensor was not compared against a calibrated reference instrument.

#### Experiment 3 Graphs

**Temperature vs. Time**

![DHT11 Experiment 3 Temperature](images/dht11_experiment3_temperature.png)

**Humidity vs. Time**

![DHT11 Experiment 3 Humidity](images/dht11_experiment3_humidity.png)

The graphs show the temperature and humidity measurements throughout the experiment. The transition from **Location A to Location B occurred at approximately 5 minutes**.

#### Dataset

The complete experimental dataset is available at:

`data/dht11/experiment3_different_location.csv`

The dataset contains the following columns:

```text
Temperature_C,Humidity_RH
```

#### DHT11 Characterization Status

* [x] Understand DHT11 operation
* [x] Connect DHT11 to ESP32
* [x] Collect stable-condition measurements
* [x] Test environmental response
* [x] Test recovery behavior
* [x] Test sensor at different locations
* [x] Analyze temperature and humidity variation
* [x] Generate temperature and humidity graphs

The results from these experiments provide an initial characterization of the DHT11 sensor before integrating it into the complete Smart Agriculture Monitoring and Irrigation System.
