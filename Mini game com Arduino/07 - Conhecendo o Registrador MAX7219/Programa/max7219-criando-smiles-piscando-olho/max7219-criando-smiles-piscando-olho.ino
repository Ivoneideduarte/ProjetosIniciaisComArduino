//#include "LedControl.h" //Procura essa bibliteca dentro do meu computador
#include <LedControl.h> //Esse pacote da biblioteca está na pasta raiz do meu Arduino

/*
  Agora, precisamos de um LedControl para trabalhar.
 ***** Esses números de pinos provavelmente não funcionarão com seu hardware *****
  o pino 6 está conectado ao DataIn
  o pino 8 está conectado ao CLK
  o pino 7 está conectado ao LOAD
  Temos apenas um único MAX72XX.
*/
int DIN = 12; // Dados de entrada
int CS =  10; // Habilita o carregamento
int CLK = 11; // Clock

LedControl lc = LedControl(DIN, CLK, CS, 1);

unsigned long delaytime = 100;

void setup()
{
  //Funções
  lc.shutdown(0, false); // Não quero que o meu display trabalhe em nível baixo
  lc.setIntensity(0, 8); // Intensidade de brilho 8
  lc.clearDisplay(0);    // Limpa o display
}

void loop() 
{
  olhoAberto();
  delay(2000);
  olhoFechando();
  delay(200);
  olhoFechado();
  delay(100);

}

void olhoAberto() 
{ 
  //8 elementos
  byte a[8] = {B00000000,
               B01100110,
               B01100110,
               B00000000,
               B00000000,
               B01000010,
               B00111100,
               B00000000
              };

  lc.setRow(0, 0, a[0]);
  lc.setRow(0, 1, a[1]);
  lc.setRow(0, 2, a[2]);
  lc.setRow(0, 3, a[3]);
  lc.setRow(0, 4, a[4]);
  lc.setRow(0, 5, a[5]);
  lc.setRow(0, 6, a[6]);
  lc.setRow(0, 7, a[7]);
}

void olhoFechando() 
{
  byte a[8] = {B00000000,
               B00000000,
               B01100110,
               B00000000,
               B00000000,
               B01000010,
               B00111100,
               B00000000
              };

  lc.setRow(0, 0, a[0]);
  lc.setRow(0, 1, a[1]);
  lc.setRow(0, 2, a[2]);
  lc.setRow(0, 3, a[3]);
  lc.setRow(0, 4, a[4]);
  lc.setRow(0, 5, a[5]);
  lc.setRow(0, 6, a[6]);
  lc.setRow(0, 7, a[7]);
}

void olhoFechado() 
{
  byte a[8] = {B00000000,
               B00000000,
               B00000000,
               B00000000,
               B00000000,
               B01000010,
               B00111100,
               B00000000
              };

  lc.setRow(0, 0, a[0]);
  lc.setRow(0, 1, a[1]);
  lc.setRow(0, 2, a[2]);
  lc.setRow(0, 3, a[3]);
  lc.setRow(0, 4, a[4]);
  lc.setRow(0, 5, a[5]);
  lc.setRow(0, 6, a[6]);
  lc.setRow(0, 7, a[7]);
}
