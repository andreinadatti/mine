//Sensore umidità prodotto su Tinkercad
float humidity;
int x = A2;
void setup()
{
Serial.begin(9600);
}
void loop()
{
humidity=analogRead(x);
  Serial.println(map(humidity,0,1023,10,70));
  delay(100);
}
