#include <Arduino.h>

#define LDR_PIN 34

void setup()
{
    Serial.begin(115200);

    delay(1000);

    Serial.println("Smart Agriculture - LDR Light Classification");
    Serial.println("ADC_Value,Light_Level");
}

void loop()
{
    int ldrValue = analogRead(LDR_PIN);

    const char* lightLevel;

    if (ldrValue <= 100)
    {
        lightLevel = "DARK";
    }
    else if (ldrValue <= 1000)
    {
        lightLevel = "DIM";
    }
    else if (ldrValue <= 3500)
    {
        lightLevel = "NORMAL";
    }
    else
    {
        lightLevel = "BRIGHT";
    }

    Serial.print(ldrValue);
    Serial.print(",");
    Serial.println(lightLevel);

    delay(1000);
}