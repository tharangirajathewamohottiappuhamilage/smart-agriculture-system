#include <Arduino.h>
#include <DHT.h>

#define DHT_PIN 17
#define DHT_TYPE DHT11

DHT dht(DHT_PIN, DHT_TYPE);

void setup()
{
    Serial.begin(115200);

    dht.begin();

    Serial.println("Temperature_C,Humidity_RH");
}

void loop()
{
    float humidity = dht.readHumidity();
    float temperature = dht.readTemperature();

    if (isnan(humidity) || isnan(temperature))
    {
        Serial.println("ERROR,ERROR");
        delay(2000);
        return;
    }

    Serial.print(temperature, 2);
    Serial.print(",");
    Serial.println(humidity, 2);

    delay(2000);
}