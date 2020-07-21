/*
   LINHA
   LI - PI - AR
   01 - 09 - 13
   02 - 14 - 08
   03 - 08 - A3
   04 - 12 - 10
   05 - 01 - 05
   06 - 07 - A2
   07 - 02 - 04
   08 - 05 - A0

   COLUNA
   CO - PI - AR
   01 - 13 - 09
   02 - 03 - 03
   03 - 04 - 02
   04 - 10 - 12
   05 - 06 - A1
   06 - 11 - 11
   07 - 15 - 07
   08 - 16 - 06
*/
byte linhas[8] = {13, 8, A3, 10, 5, A2, 4, A0};
byte colunas[8] = {9, 3, 2, 12, A1, 11, 7, 6};
byte x, y;

void setup()
{
  Serial.begin(9600);
  for (x = 0; x <= 7; x++) 
  {
    pinMode(linhas[x], OUTPUT);
    digitalWrite(linhas[x], HIGH);
  }
  for (y = 0; y <= 7; y++) 
  {
    pinMode(colunas[y], OUTPUT);
    digitalWrite(colunas[y], LOW);
  }

}
void loop()
{
  for (x = 0; x <= 7; x++)
  {
    digitalWrite(linhas[x], LOW);
    if (x == 7) 
    {
      digitalWrite(linhas[7], HIGH);
    }
    else 
    {
      digitalWrite(linhas[(x - 1)], HIGH);
    }

    for (y = 0; y <= 7; y++) 
    {
      int velocidade = analogRead(A4);
      digitalWrite(colunas[y], HIGH);
      if (y == 0) 
      {
        digitalWrite(colunas[7], LOW);
      }
      else 
      {
        digitalWrite(colunas[(y - 1)], LOW);
      }
      delay(velocidade);
    }
  }
}
