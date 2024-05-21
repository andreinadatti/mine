#include <SimpleDHT.h>
#define ANALOG_PIN A0
#define DIGITAL_PIN 1

SimpleDHT22 dht22(DIGITAL_PIN);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(0, INPUT);
}
void loop() {
  // put your main code here, to run repeatedly:
  int soil_moisture= analogRead(ANALOG_PIN);
  int light_intensity = digitalRead(0);
  float temperature=0;
  float air_humidity=0;
  dht22.read2(&temperature, &air_humidity, NULL);

  /*Serial.print("Temp: ");
  Serial.print((float)temp);
  Serial.print(" C, Humidity: ");
  Serial.print((float)hum);
  Serial.print("%, Soil Humidity: ");
  Serial.print(soilHumidity);
  Serial.print(", NeedLight: ");
  Serial.print(lightSensor ? "Yes" : "No");
  Serial.println();*/

  Serial.print(air_humidity);
  Serial.print(",");
  Serial.print(temperature);
  Serial.print(",");
  Serial.print(soil_moisture);
  Serial.print(",");
  Serial.println(light_intensity);
  delay(3000);

}