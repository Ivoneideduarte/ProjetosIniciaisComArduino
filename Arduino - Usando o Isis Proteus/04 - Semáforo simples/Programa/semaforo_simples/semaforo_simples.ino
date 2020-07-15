/*
 * Objetivo: Fazer um programa que simula um semáforo
 * Autora: Téc. em Mecatrônica - Ivoneide Duarte
 * Data: Julho de 2020
 */

 //Definição dos pinos pelos respectivos nomes de identificação
 #define ledVermelho 13
 #define ledAmarelo 12
 #define ledVerde 11
 
void setup() 
{
  //Configuração dos pinos digitais como saída de dados
  pinMode(ledVermelho, OUTPUT);
  pinMode(ledAmarelo, OUTPUT);
  pinMode(ledVerde, OUTPUT);
}

void loop() 
{
  digitalWrite(ledVermelho, HIGH); //Liga o LED vermelho
  delay(4000);                     //Espera 4s
  digitalWrite(ledVermelho, LOW);  //Apaga LED vermelho
  digitalWrite(ledVerde, HIGH);    //Liga o LED verde

  delay(2500);                     //Espera 2,5s
  digitalWrite(ledVerde, LOW);     //Apaga o LED vermelho
  digitalWrite(ledAmarelo, HIGH);  //Liga LED vermelho
  
  delay(1000);                     //Espera 1s
  digitalWrite(ledAmarelo, LOW);   //Apaga o LED vermelho
}
