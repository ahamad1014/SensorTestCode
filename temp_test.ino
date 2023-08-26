#include <ESP8266WiFi.h>
#include <OneWire.h>
#include <DallasTemperature.h>

#define ONE_WIRE_BUS D4

OneWire oneWire(ONE_WIRE_BUS);

DallasTemperature sensors(&oneWire);

// WiFi Credentials
const char* ssid = "ESP8266";
const char* password = "asdfghjkl";

void setup() {
  Serial.begin(115200);
  sensors.begin();

}

void loop() {
  sensors.requestTemperatures();
  int temperature=sensors.getTempCByIndex(0);
  Serial.print("Temperature: ");
  Serial.println(temperature);
  delay(1000);
}
