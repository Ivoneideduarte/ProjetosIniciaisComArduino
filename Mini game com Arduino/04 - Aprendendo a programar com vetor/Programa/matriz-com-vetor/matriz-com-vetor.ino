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

//Vetor de 8 posições
byte linhas[8] = {13, 8, A3, 10, 5, A2, 4, A0}; //Vai do índice 0 até o 7
byte colunas[8] = {9, 3, 2, 12, A1, 11, 7, 6};

void setup()
{
  for (byte x = 0; x <= 7; x++)
  { //Definindo os pinos das linhas
    pinMode(linhas[x], OUTPUT);    //Definindo as portas como saída
    digitalWrite(linhas[x], HIGH); //Acionando as linhas da Matriz de LEDs
  }
  for (byte y = 0; y <= 7; y++)
  { //Definindo os pinos das colunas
    pinMode(colunas[y], OUTPUT);   //Definindo as portas como saída
    digitalWrite(colunas[y], LOW); //Desligando as colunas da Matriz de LEDs
  }
}

void loop()
{
  
//digitalWrite(13, LOW); 
//for (byte y = 0; y <= 7; y++)
//{
//  digitalWrite(colunas[y], HIGH);
//  delay(1000);
//  if (y == 7)
//  {
//    for (byte y = 0; y <= 7; y++)
//    {
//      digitalWrite(colunas[y], LOW);
//    }
//  }
//}

  digitalWrite(13, LOW);

  for (byte y = 0; y <= 7; y++)
  {
    digitalWrite(colunas[y], HIGH);
    if (y == 0)
    {
      digitalWrite(colunas[7], LOW);
    }
    else
    {
      digitalWrite(colunas[(y - 1)], LOW);
    }
    delay(1000);
  }
}
