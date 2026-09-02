#include <Arduino.h>

#define WATER_LEVEL_PIN 33

String classifyWaterLevel(int adcValue)
{
    if (adcValue <= 500)
    {
        return "EMPTY";
    }
    else if (adcValue <= 1500)
    {
        return "LOW";
    }
    else if (adcValue <= 1999)
    {
        return "MEDIUM";
    }
    else if (adcValue <= 2080)
    {
        return "HIGH";
    }
    else
    {
        return "FULL";
    }
}

void setup()
{
    Serial.begin(115200);

    delay(1000);

    Serial.println("Water Level Experiment 4 - Threshold Determination");
    Serial.println("ADC_Value,Classification");
}

void loop()
{
    int waterLevel = analogRead(WATER_LEVEL_PIN);

    String classification = classifyWaterLevel(waterLevel);

    Serial.print(waterLevel);
    Serial.print(",");
    Serial.println(classification);

    delay(1000);
}