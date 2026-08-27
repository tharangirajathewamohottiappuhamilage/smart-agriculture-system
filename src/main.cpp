#include <Arduino.h>

#define WATER_LEVEL_PIN 33

void setup()
{
    Serial.begin(115200);

    delay(1000);

    pinMode(WATER_LEVEL_PIN, INPUT);

    Serial.println("Water Level Sensor Experiment 1 - Dry Sensor");
    Serial.println("ADC_Value");
}

void loop()
{
    int waterLevelValue = analogRead(WATER_LEVEL_PIN);

    Serial.println(waterLevelValue);

    delay(500);
}