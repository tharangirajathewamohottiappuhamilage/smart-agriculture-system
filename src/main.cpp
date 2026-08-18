#include <Arduino.h>

#define LDR_PIN 34

void setup()
{
    Serial.begin(115200);

    delay(1000);

    Serial.println("LDR Experiment 4 - Threshold Validation");
    Serial.println("ADC_Value");
}

void loop()
{
    int ldrValue = analogRead(LDR_PIN);

    Serial.println(ldrValue);

    delay(1000);
}