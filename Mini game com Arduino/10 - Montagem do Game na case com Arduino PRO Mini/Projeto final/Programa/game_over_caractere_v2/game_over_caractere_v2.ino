//Incrementar um buzzer no game over
#include <LedControl.h>

LedControl lc = LedControl(12, 11, 10, 1); // Pins: DIN,CLK,CS, # of Display connected

unsigned long delayTime = 1000;

//Caracteres para o Game Over
byte invaders1a[] =
{
  B00100100,
  B00100100,
  B01111110,
  B11011011,
  B11111111,
  B11111111,
  B10100101,
  B00100100
};

byte invaders1b[] =
{
  B00100100,
  B10100101,
  B11111111,
  B11011011,
  B11111111,
  B01111110,
  B00100100,
  B01000010
};

void setup()
{
  lc.shutdown(0, false);
  lc.setIntensity(0, 5);
  lc.clearDisplay(0);
}

void loop()
{
  space1a();
  delay(delayTime);

  space1b();
  delay(delayTime);
}

//Funções
void space1a()
{
  for (int i = 0; i < 8; i++)
  {
    lc.setRow(0, i, invaders1a[i]);
  }
}

void space1b()
{
  for (int i = 0; i < 8; i++)
  {
    lc.setRow(0, i, invaders1b[i]);
  }
}
