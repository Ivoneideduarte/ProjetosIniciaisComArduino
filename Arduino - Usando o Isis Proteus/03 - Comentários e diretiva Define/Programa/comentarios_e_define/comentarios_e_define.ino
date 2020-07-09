/*
 * Objetivo: Explicar como fazer comentários no programa e usar a diretiva Define para apelidar os comandos e pinos do Arduino
 * Autora: Téc. em Mecatrônica - Ivoneide Duarte
 * Data: Julho de 2020
 */

//A diretiva 'Define' dar apelidos aos comandos e pinos do Arduino
#define ledAmarelo 12
#define ledVerde 13

void setup() 
{
  pinMode(ledVerde, OUTPUT);    //O pino 13 do Arduino está configurado como saída digital
  pinMode(ledAmarelo, OUTPUT);  //O pino 12 do Arduino está configurado como saída digital
}

void loop() 
{
  digitalWrite(ledVerde, HIGH);  //O pino 13 do Arduino será ligado
  digitalWrite(ledAmarelo, LOW); //O pino 12 do Arduino será desligado
  delay(200);                    //Tempo de espera em milissegundos
  digitalWrite(ledVerde, LOW);   //O pino 13 do Arduino será desligado
  digitalWrite(ledAmarelo, HIGH);//O pino 12 do Arduino será ligado
  delay(200);                    //Tempo de espera em milissegundos
}
