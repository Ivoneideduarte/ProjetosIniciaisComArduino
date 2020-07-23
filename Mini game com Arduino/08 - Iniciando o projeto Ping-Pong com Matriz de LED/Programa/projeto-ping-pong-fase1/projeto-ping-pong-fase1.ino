//https://www.embarcados.com.br/modulo-matriz-de-leds-com-max7219/

#include <LedControl.h>

int DIN = 12;
int CS =  10;
int CLK = 11;

LedControl myMatrix = LedControl(DIN, CLK, CS, 1);

int column = 1, row = random(8) + 1; // decide em que ponto a bola deve iniciar
int directionX = 1, directionY = 1;  // certifica-se de que ela vai primeiro da esquerda para a direita
int speed = 300;                     // velocidade
int counter = 0, mult = 10;          // variáveis auxiliares para controle de velocidade


void setup()
{
  myMatrix.shutdown(0, false); // habilita o display
  myMatrix.setIntensity(0, 1); // define o brilho dos leds
  myMatrix.clearDisplay(0);    // limpa o display
  randomSeed(analogRead(0));   //
}


void loop()
{
  column += directionX;     //atualiza valor da coluna
  row += directionY;        //atualiza valor da linha

  //verifica se boa atingiu a raquete
  if (column == 6 && directionX == 1 && (0 == row || 1 == row || 2 == row || 3 == row || 4 == row || 5 == row || 6 == row || 7 == row))
  {
    directionX = -1; //rebate bola
  }

  //verica se bola atingiu paredes: topo, base ou lateral esquerda
  if (column == 0 && directionX == -1 )
  {
    directionX = 1;
  }
  if (row == 7 && directionY == 1 )
  {
    directionY = -1;
  }
  if (row == 0 && directionY == -1 )
  {
    directionY = 1;
  }

  //caso tenha atingido a coluna 7, significa que ultrapassou a raquete
  if (column == 7)
  {
    gameOver();  //chama a função oops, para finalizar o jogo
  }


  myMatrix.clearDisplay(0); // limpa a tela para o próximo quadro de animação

  myMatrix.setLed(0, column, row, HIGH); //Display , Coluna, Linha, Ligar/Desligar        //desenha bola na linha e coluna atual

  //Desenha raquete na coluna 7
  //myMatrix.setLed(numDisplay, coluna, linha, estado)
  myMatrix.setLed(0, 7, 0, HIGH);
  myMatrix.setLed(0, 7, 1, HIGH);
  myMatrix.setLed(0, 7, 2, HIGH);
  myMatrix.setLed(0, 7, 3, HIGH);
  myMatrix.setLed(0, 7, 4, HIGH);
  myMatrix.setLed(0, 7, 5, HIGH);
  myMatrix.setLed(0, 7, 6, HIGH);
  myMatrix.setLed(0, 7, 7, HIGH);

  //A cada ciclo a velocidade aumenta
  if (!(counter % mult)) 
  {//Se o resto não for zero
    speed -= 5;
    mult * mult;
  }
  delay(speed);
  counter++;
}

void gameOver()
{
  for (int x = 0; x < 3; x++)
  {
    myMatrix.clearDisplay(0);
    delay(250);
    for (int y = 0; y < 8; y++)
    {
      myMatrix.setRow(0, y, 255);
    }
    delay(250);
  }
  // reinicia todos os valores
  counter = 0;
  speed = 300;
  column = 1;
  row = random(8) + 1; // escolhe uma nova posição inicial
}
