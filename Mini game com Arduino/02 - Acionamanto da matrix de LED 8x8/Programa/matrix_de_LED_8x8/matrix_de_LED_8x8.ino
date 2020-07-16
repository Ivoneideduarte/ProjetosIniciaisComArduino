/*
   LINHA
   LINHA - PINO DA MATRIX - PORTA DO ARDUINO
   linha 01 - pin 09 - porta 13
   linha 02 - pin 14 - porta 08
   linha 03 - pin 08 - porta A3
   linha 04 - pin 12 - porta 10
   linha 05 - pin 01 - porta 05
   linha 06 - pin 07 - porta A2
   linha 07 - pin 02 - porta 04
   linha 08 - pin 05 - porta A0

   COLUNA
   COLUNA - PINO DA MATRIX - PORTA DO ARDUINO
   coluna 01 - pin 13 - porta 09
   coluna 02 - pin 03 - porta 03
   coluna 03 - pin 04 - porta 02
   coluna 04 - pin 10 - porta 12
   coluna 05 - pin 06 - porta A1
   coluna 06 - pin 11 - porta 11
   coluna 07 - pin 15 - porta 07
   coluna 08 - pin 16 - porta 06
*/
void setup()
{
  for (int porta = 2; porta <= 13; porta++)
  {
    pinMode(porta, OUTPUT);
  }
  pinMode(A0, OUTPUT);
  pinMode(A1, OUTPUT);
  pinMode(A2, OUTPUT);
  pinMode(A3, OUTPUT);
}

void loop()
{
  //Linhas
  digitalWrite(13, LOW);  //linha 01
  digitalWrite(8, LOW);  //linha 02
  digitalWrite(A3, LOW); //linha 03
  digitalWrite(10, LOW); //linha 04
  digitalWrite(5, LOW);  //linha 05
  digitalWrite(A2, LOW); //linha 06
  digitalWrite(4, LOW);  //linha 07
  digitalWrite(A0, LOW); //linha 08

  //Colunas
  digitalWrite(9, HIGH);  //coluna 01
  delay(50);
  digitalWrite(3, HIGH);  //coluna 02
  delay(50);
  digitalWrite(2, HIGH);  //coluna 03
  delay(50);
  digitalWrite(12, HIGH);  //coluna 04
  delay(50);
  digitalWrite(A1, HIGH);  //coluna 05
  delay(50);
  digitalWrite(11, HIGH);  //coluna 06
  delay(50);
  digitalWrite(7, HIGH);  //coluna 07
  delay(50);
  digitalWrite(6, HIGH);  //coluna 08
  delay(50);

  digitalWrite(9, LOW);
  digitalWrite(3, LOW);
  digitalWrite(2, LOW);
  digitalWrite(12, LOW);
  digitalWrite(A1, LOW);
  digitalWrite(11, LOW);
  digitalWrite(7, LOW);
  digitalWrite(9, LOW);
}

//void setup()
//{
//  for (int porta = 2; porta <= 13; porta++)
//  {
//    pinMode(porta, OUTPUT);
//  }
//  pinMode(A0, OUTPUT);
//  pinMode(A1, OUTPUT);
//  pinMode(A2, OUTPUT);
//  pinMode(A3, OUTPUT);
//}
//
//void loop()
//{
//  //Linhas
//  digitalWrite(13, LOW);  //linha 01
//  digitalWrite(8, LOW);  //linha 02
//  digitalWrite(5, HIGH);  //linha 05
//  
//  //Colunas
//  digitalWrite(9, HIGH);  //coluna 01
//}
