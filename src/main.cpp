#include <Arduino.h>


constexpr uint8_t SOIL_SENSOR_PIN = 32;


// Calibration values from your experiment
constexpr int DRY_THRESHOLD = 200;
constexpr int MOIST_THRESHOLD = 1000;


int readSoilMoistureAverage(uint8_t samples = 10)
{
    long total = 0;

    for(uint8_t i = 0; i < samples; i++)
    {
        total += analogRead(SOIL_SENSOR_PIN);
        delay(10);
    }

    return total / samples;
}


String getSoilCondition(int value)
{

    if(value < DRY_THRESHOLD)
    {
        return "DRY";
    }
    else if(value < MOIST_THRESHOLD)
    {
        return "MOIST";
    }
    else
    {
        return "WET";
    }

}


void setup()
{

    Serial.begin(115200);

    delay(1000);

    Serial.println("==============================");
    Serial.println("Smart Agriculture System");
    Serial.println("Soil Moisture Monitoring");
    Serial.println("==============================");

}


void loop()
{

    int moistureValue = readSoilMoistureAverage();


    Serial.print("ADC Value: ");
    Serial.println(moistureValue);


    Serial.print("Condition: ");
    Serial.println(getSoilCondition(moistureValue));


    delay(1000);

}