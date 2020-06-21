/*
   Autora - Ivoneide Duarte
   Data - 17/12/2018 - 16/06/2020

*/
//Biblioteca nativa do Arduino
#include <SoftwareSerial.h> // Faz a conversão de uma porta comum para uma serial
#define RX 11
#define TX 12
SoftwareSerial bluetooth(RX, TX); // RX => TX | TX => RX

int portas_led[4] = {2, 3, 4, 5}; //Portas de conexão digital

void setup() 
{
  bluetooth.begin(9600); // INICIA COMUNICAÇÃO SERIAL DO BLUETOOTH
  Serial.begin(9600);    // INICIA SERIAL MONITOR
  Serial.println("Digite os comandos: ");

  for (int pinos_led = 0; pinos_led < 4; pinos_led++)
  {
    pinMode(portas_led[pinos_led], OUTPUT);
  }
}

void loop() 
{
  while (bluetooth.available()) // ENQUANTO O BLUETOOTH ESTIVER ATIVO EXECUTA O BLOCO
  {
    //Verifica se recebeu alguma informação
    char comando = bluetooth.read(); // ARMAZENA NA VARIÁVEL COMANDO A LEITURA DO BLUETOOTH

    Serial.print("Comando: ");
    Serial.println(comando); // IMPRIME O COMANDO NO SERIAL MONITOR

    if (comando == 'A') {
      digitalWrite(portas_led[0], HIGH); // Posição 0 = portas_led[0]
    }
    if (comando == 'a') {
      digitalWrite(portas_led[0], LOW);
    }

    if (comando == 'B') {
      digitalWrite(portas_led[1], HIGH); // Posição 1 = portas_led[1]
    }
    if (comando == 'b') {
      digitalWrite(portas_led[1], LOW);
    }

    if (comando == 'C') {
      digitalWrite(portas_led[2], HIGH); // Posição 2 = portas_led[2]
    }
    if (comando == 'c') {
      digitalWrite(portas_led[2], LOW);
    }

    if (comando == 'D') {
      digitalWrite(portas_led[3], HIGH); // Posição 3 = portas_led[3]
    }
    if (comando == 'd') {
      digitalWrite(portas_led[3], LOW);
    }

  } // And while
} //And Loop
