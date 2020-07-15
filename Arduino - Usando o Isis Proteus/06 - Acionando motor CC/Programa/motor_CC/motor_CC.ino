/*
 * Objetivo: Ligar motor CC no Arduino 
 * Autora: Téc. em Mecatrônica - Ivoneide Duarte
 * Data: Julho de 2020
 */

#define motor_CC 7
 
void setup() 
{
  //Configuração dos pinos digitais como saída de dados
  pinMode(motor_CC, OUTPUT);
}

void loop() 
{
  digitalWrite(motor_CC, HIGH); //Ligar o motor 
  delay(1000);                  //Espera 1s
  digitalWrite(motor_CC, LOW);  //Desliga o motor
  delay(1000);                   //Espera 1s
}
