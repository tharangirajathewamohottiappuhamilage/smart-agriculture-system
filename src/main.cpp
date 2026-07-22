#include <Arduino.h>

// Soil moisture sensor is connected to GPIO 32
constexpr uint8_t SOIL_SENSOR_PIN = 32;

// Read the sensor several times and return the average
int readSoilMoistureAverage(uint8_t samples = 10)
{
    long total = 0;

    for (uint8_t i = 0; i < samples; i++)
    {
        total += analogRead(SOIL_SENSOR_PIN);
        delay(10); // small delay between readings
    }

    return total / samples;
}

void setup()
{
    Serial.begin(115200);
    delay(1000);

    Serial.println();
    Serial.println("====================================");
    Serial.println("Smart Agriculture System");
    Serial.println("Soil Moisture Sensor Calibration");
    Serial.println("====================================");
}

void loop()
{
    int rawValue = analogRead(SOIL_SENSOR_PIN);
    int averageValue = readSoilMoistureAverage();

    Serial.println("----------------------------");
    Serial.print("Raw ADC Value     : ");
    Serial.println(rawValue);

    Serial.print("Average ADC Value : ");
    Serial.println(averageValue);

    delay(1000);
}