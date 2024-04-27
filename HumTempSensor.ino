//Sensore di umidità e temperatura creati su Tinkercad, stampa dei risulttai in formato csv
const int analogIn = A0;
int humiditysensorOutput = 0;
// Defining Variables
int RawValue= 0;
double Voltage = 0;
double tempC = 0;
double tempF = 0;

void setup() {  
  Serial.begin(9600);
  pinMode(A1, INPUT);
}

void loop() {
  RawValue = analogRead(analogIn);
  Voltage = (RawValue / 1023.0) * 5000; // 5000 to get millivots.
  tempC = (Voltage - 500) * 0.1; // 500 is the offset 
  Serial.print(tempC, 1); // Stampa la temperatura in Celsius con una cifra decimale
  Serial.print(","); // Virgola per separare i valori
  humiditysensorOutput = analogRead(A1);
  Serial.print(map(humiditysensorOutput, 0, 1023, 10, 70)); // Stampa l'umidità mappata
  Serial.println(); // Andare a capo alla fine della riga

  delay(100);  // Ripeti ogni 5 secondi
}
