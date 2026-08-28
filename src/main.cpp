#include <Arduino.h>

#define WATER_LEVEL_PIN 33

void setup()
{
    Serial.begin(115200);

    delay(1000);

    Serial.println("Water Level Experiment 3 - Stable Medium Water Level");
    Serial.println("ADC_Value");
}

void loop()
{
    int waterLevel = analogRead(WATER_LEVEL_PIN);

    Serial.println(waterLevel);

    delay(1000);
}