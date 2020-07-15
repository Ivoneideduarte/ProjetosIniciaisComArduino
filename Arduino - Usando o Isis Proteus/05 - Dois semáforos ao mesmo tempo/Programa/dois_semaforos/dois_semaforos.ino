/*
 * Objetivo: Semáforo duplo, com 6 leds
 * Autora: Téc. em Mecatrônica - Ivoneide Duarte
 * Data: Julho de 2020
 */

//Definição dos pinos pelos respectivos nomes de identificação
#define ledVermelho1 13
#define ledAmarelo1 12
#define ledVerde1 11

#define ledVermelho2 10
#define ledAmarelo2 9
#define ledVerde2 8
 
void setup() 
{
  //Configuração dos pinos digitais como saída de dados
  pinMode(ledVermelho1, OUTPUT);
  pinMode(ledAmarelo1, OUTPUT);
  pinMode(ledVerde1, OUTPUT);

  pinMode(ledVermelho2, OUTPUT);
  pinMode(ledAmarelo2, OUTPUT);
  pinMode(ledVerde2, OUTPUT);
}

void loop() 
{
  digitalWrite(ledVermelho1, HIGH); //Liga o LED vermelho1
  digitalWrite(ledVermelho2, HIGH); //Liga o LED vermelho2
  delay(1000);                      //Espera 1s

  digitalWrite(ledVermelho1, LOW);  //Apaga o LED vermelho1
  digitalWrite(ledVerde1, HIGH);    //Liga o LED verde1
  delay(3000);                      //Espera 3s

  digitalWrite(ledVerde1, LOW);     //Apaga o LED verde1
  digitalWrite(ledAmarelo1, HIGH);  //Liga o LED amarelo1
  delay(1000);                      //Espera 1s

  digitalWrite(ledAmarelo1, LOW);   //Apaga o LED amarelo1
  digitalWrite(ledVermelho1, HIGH); //Liga o LED vermelho1
  delay(1000);                      //Espera 1s

  digitalWrite(ledAmarelo2, LOW);   //Apaga o LED vermelho2
  digitalWrite(ledVermelho2, LOW);    //Liga o LED verde2
  digitalWrite(ledVerde2, HIGH);    //Liga o LED verde2
  delay(3000);                      //Espera 3s

  digitalWrite(ledVerde2, LOW);     //Apaga o LED verde2
  digitalWrite(ledAmarelo2, HIGH);  //Liga o LED amarelo2
  delay(1000);                      //Espera 1s

  digitalWrite(ledAmarelo2, LOW);  //Apaga o LED amarelo2
}
