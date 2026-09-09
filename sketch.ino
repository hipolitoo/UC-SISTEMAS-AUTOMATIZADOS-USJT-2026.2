#include <DHT.h>

// Definições de pinos
const int BTN = 2;
const int LED = 8;
#define DHTPIN 4
#define DHTTYPE DHT22

// Inicialização do sensor
DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  
  // Configuração Botão e LED
  pinMode(BTN, INPUT_PULLUP);
  pinMode(LED, OUTPUT);
  
  // Inicializa o DHT22
  dht.begin();
}

void loop() {
  Serial.println("--- LEITURAS DA ESTACAO ---");

  // 1. Leitura Digital (Botão e LED)
  // Como usa PULLUP, LOW significa pressionado
  bool detectado = (digitalRead(BTN) == LOW); 
  digitalWrite(LED, detectado);
  
  if (detectado) {
    Serial.println("Botão: PRESSIONADO (LED Aceso)");
  } else {
    Serial.println("Botão: LIBERADO (LED Apagado)");
  }

  // 2. Leitura Analógica (Potenciômetro)
  int valorPot = analogRead(A0);
  Serial.print("Potenciômetro [");
  Serial.print(valorPot);
  Serial.print("]: ");
  
  if (valorPot < 400) {
    Serial.println("NORMAL");
  } else if (valorPot < 750) {
    Serial.println("ATENCAO");
  } else {
    Serial.println("ALARME/FALHA");
  }

  // 3. Leitura de Temperatura (DHT22)
  float temperatura = dht.readTemperature();
  
  Serial.print("Temperatura: ");
  // Verifica se a leitura falhou (is not a number)
  if (isnan(temperatura)) {
    Serial.println("FALHA DE SENSOR");
  } else {
    Serial.print(temperatura);
    Serial.print(" C -> ");
    
    if (temperatura < 30.0) {
      Serial.println("NORMAL");
    } else if (temperatura < 40.0) {
      Serial.println("ATENCAO");
    } else {
      Serial.println("ALARME/FALHA");
    }
  }

  Serial.println("---------------------------\n");
  
  // Aguarda 2 segundos entre as leituras (recomendado para o DHT22)
  delay(2000); 
}