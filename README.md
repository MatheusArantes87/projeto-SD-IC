TERMOcup - Medidor de Temperatura com Alerta Sonoro

Descrição:
------------
O TermoCup é um projeto simples e funcional desenvolvido com Arduino, que mede a temperatura de objetos utilizando o sensor DHT11. O artefato foi pensado para monitorar a temperatura de uma latinha colocada dentro de um recipiente térmico de isopor. Quando a temperatura da latinha atinge 10°C, um buzzer é acionado para alertar o usuário.

Este projeto é ideal para quem está começando no mundo do Arduino e deseja aprender sobre sensores de temperatura e controle de saídas sonoras.

Materiais Utilizados:
----------------------
- Arduino Uno (Robocore)
- Sensor de Temperatura e Umidade DHT11
- Buzzer Passivo
- Recipiente de isopor
- Latinha (bebida)
- Jumpers (cabos de conexão)
- Arduino IDE

Código Fonte:
--------------
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


Funcionamento:
---------------
1. O sensor DHT11 realiza a leitura da temperatura dentro do recipiente de isopor.
2. A temperatura é exibida no Serial Monitor da Arduino IDE.
3. Quando a temperatura atingir ou ficar abaixo de 10°C, o buzzer emitirá um som contínuo.
4. Se a temperatura estiver acima de 10°C, o buzzer permanecerá desligado.

Aplicações:
------------
- Controle de temperatura de bebidas.
- Experimentos de física e eletrônica básica.
- Projetos educacionais com Arduino.

Observações:
-------------
- O DHT11 possui precisão limitada e intervalo de leitura de aproximadamente 1 leitura a cada 2 segundos.
- O recipiente de isopor ajuda a isolar termicamente a latinha, melhorando a confiabilidade das medições.

Licença:
---------
Este projeto é de domínio aberto para fins educacionais. Modifique e compartilhe à vontade!