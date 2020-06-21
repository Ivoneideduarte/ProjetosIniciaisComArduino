//Biblioteca nativa do Arduino
#include <SoftwareSerial.h> //Faz a conversão de uma porta comum para uma serial
#define rele 7
#define RX 11
#define TX 12
SoftwareSerial bluetooth(RX, TX); // RX => TX | TX => RX

void setup() 
{
  pinMode(rele,OUTPUT);
  
  bluetooth.begin(9600); //INICIA COMUNICAÇÃO SERIAL DO BLUETOOTH
  Serial.begin(9600);    //INICIA SERIAL MONITOR
  Serial.println("Digite os comandos: ");
}

void loop() 
{
  while (bluetooth.available()) //ENQUANTO O BLUETOOTH ESTIVER ATIVO EXECUTA O BLOCO
  {
    //Verifica se recebeu alguma informação
    char comando = bluetooth.read(); // ARMAZENA NA VARIÁVEL COMANDO A LEITURA DO BLUETOOTH

    Serial.print("Comando: ");
    Serial.println(comando); // IMPRIME O COMANDO NO SERIAL MONITOR

    if(comando=='A'){digitalWrite(rele,HIGH);}
    if(comando=='a'){digitalWrite(rele,LOW);}

  } // And while
}
