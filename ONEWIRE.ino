#include "DHT.h"

#define DHTPIN 4
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(19200);
  dht.begin();
}

void loop() {
  delay(2000); 

  float h = dht.readHumidity();
  float t = dht.readTemperature();

  if (isnan(h) || isnan(t)) {
    Serial.println("Loi: Khong doc duoc cam bien!");
    return;
  }

  Serial.print("Do am: ");
  Serial.print(h);
  Serial.print("% | Nhiet do: ");
  Serial.print(t);
  Serial.println("C");
}