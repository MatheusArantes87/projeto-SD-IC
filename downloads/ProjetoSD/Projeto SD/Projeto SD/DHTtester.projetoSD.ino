
#include "DHT.h"

#define DHTPIN 2 // revisar     
#define DHTTYPE DHT11   

DHT dht(DHTPIN, DHTTYPE);

#define BUZZER 9// Revisar

void setup() {
  Serial.begin(9600);
  Serial.println("Vou ligar o DHT");
  dht.begin();
  Serial.println("DHT ligado");
  pinMode(BUZZER, OUTPUT);
  noTone(BUZZER);
}

void loop() {
  delay(5000);

  float temperatura = dht.readTemperature(true);

  if (isnan(temperatura)){
    Serial.println("Falha ao ler o sensor");
    return;
  }

Serial.print("Temperatura: ");
Serial.print((temperatura - 32)/1.8);
Serial.println("Celcius");

if (temperatura <= 50){
  tone(BUZZER,200);
  Serial.println("Temperatura adequada ");
} else{
  noTone(BUZZER);
}

 
}
