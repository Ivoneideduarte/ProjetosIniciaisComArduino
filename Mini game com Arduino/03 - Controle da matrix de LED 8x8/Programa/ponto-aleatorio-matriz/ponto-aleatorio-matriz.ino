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

int sorteio;

void setup()
{
  for (int port = 2; port <= 13; port++) {
    pinMode(port, OUTPUT);
  }
  pinMode(A0, OUTPUT);
  pinMode(A1, OUTPUT);
  pinMode(A2, OUTPUT);
  pinMode(A3, OUTPUT);
}

void loop()
{
  sorteio = random(1, 9); //1 à 8
  ponto(); //Chama a função 
  sorteio = random(9, 17); //9 à 16
  ponto();
  delay(100);
}

void ponto()
{
  switch (sorteio)
  {
    case 1:
      digitalWrite(13, LOW); //LINHA 01
      digitalWrite(8, HIGH); //LINHA 02
      digitalWrite(A3, HIGH);//LINHA 03
      digitalWrite(10, HIGH);//LINHA 04
      digitalWrite(5, HIGH); //LINHA 05
      digitalWrite(A2, HIGH);//LINHA 06
      digitalWrite(4, HIGH); //LINHA 07
      digitalWrite(A0, HIGH);//LINHA 08
      break;

    case 2:
      digitalWrite(13, HIGH); //LINHA 01
      digitalWrite(8, LOW); //LINHA 02
      digitalWrite(A3, HIGH);//LINHA 03
      digitalWrite(10, HIGH);//LINHA 04
      digitalWrite(5, HIGH); //LINHA 05
      digitalWrite(A2, HIGH);//LINHA 06
      digitalWrite(4, HIGH); //LINHA 07
      digitalWrite(A0, HIGH);//LINHA 08
      break;

    case 3:
      digitalWrite(13, HIGH); //LINHA 01
      digitalWrite(8, HIGH); //LINHA 02
      digitalWrite(A3, LOW);//LINHA 03
      digitalWrite(10, HIGH);//LINHA 04
      digitalWrite(5, HIGH); //LINHA 05
      digitalWrite(A2, HIGH);//LINHA 06
      digitalWrite(4, HIGH); //LINHA 07
      digitalWrite(A0, HIGH);//LINHA 08
      break;

    case 4:
      digitalWrite(13, HIGH); //LINHA 01
      digitalWrite(8, HIGH); //LINHA 02
      digitalWrite(A3, HIGH);//LINHA 03
      digitalWrite(10, LOW);//LINHA 04
      digitalWrite(5, HIGH); //LINHA 05
      digitalWrite(A2, HIGH);//LINHA 06
      digitalWrite(4, HIGH); //LINHA 07
      digitalWrite(A0, HIGH);//LINHA 08
      break;

    case 5:
      digitalWrite(13, HIGH); //LINHA 01
      digitalWrite(8, HIGH); //LINHA 02
      digitalWrite(A3, HIGH);//LINHA 03
      digitalWrite(10, HIGH);//LINHA 04
      digitalWrite(5, LOW); //LINHA 05
      digitalWrite(A2, HIGH);//LINHA 06
      digitalWrite(4, HIGH); //LINHA 07
      digitalWrite(A0, HIGH);//LINHA 08
      break;

    case 6:
      digitalWrite(13, HIGH); //LINHA 01
      digitalWrite(8, HIGH); //LINHA 02
      digitalWrite(A3, HIGH);//LINHA 03
      digitalWrite(10, HIGH);//LINHA 04
      digitalWrite(5, HIGH); //LINHA 05
      digitalWrite(A2, LOW);//LINHA 06
      digitalWrite(4, HIGH); //LINHA 07
      digitalWrite(A0, HIGH);//LINHA 08
      break;

    case 7:
      digitalWrite(13, HIGH); //LINHA 01
      digitalWrite(8, HIGH); //LINHA 02
      digitalWrite(A3, HIGH);//LINHA 03
      digitalWrite(10, HIGH);//LINHA 04
      digitalWrite(5, HIGH); //LINHA 05
      digitalWrite(A2, HIGH);//LINHA 06
      digitalWrite(4, LOW); //LINHA 07
      digitalWrite(A0, HIGH);//LINHA 08
      break;

    case 8:
      digitalWrite(13, HIGH); //LINHA 01
      digitalWrite(8, HIGH); //LINHA 02
      digitalWrite(A3, HIGH);//LINHA 03
      digitalWrite(10, HIGH);//LINHA 04
      digitalWrite(5, HIGH); //LINHA 05
      digitalWrite(A2, HIGH);//LINHA 06
      digitalWrite(4, HIGH); //LINHA 07
      digitalWrite(A0, LOW);//LINHA 08
      break;

    case 9:
      digitalWrite(9, HIGH); //COLUNA 01
      digitalWrite(3, LOW); //COLUNA 02
      digitalWrite(2, LOW); //COLUNA 03
      digitalWrite(12, LOW); //COLUNA 04
      digitalWrite(A1, LOW); //COLUNA 05
      digitalWrite(11, LOW); //COLUNA 06
      digitalWrite(7, LOW); //COLUNA 07
      digitalWrite(6, LOW); //COLUNA 08
      break;

    case 10:
      digitalWrite(9, LOW); //COLUNA 01
      digitalWrite(3, HIGH); //COLUNA 02
      digitalWrite(2, LOW); //COLUNA 03
      digitalWrite(12, LOW); //COLUNA 04
      digitalWrite(A1, LOW); //COLUNA 05
      digitalWrite(11, LOW); //COLUNA 06
      digitalWrite(7, LOW); //COLUNA 07
      digitalWrite(6, LOW); //COLUNA 08
      break;

    case 11:
      digitalWrite(9, LOW); //COLUNA 01
      digitalWrite(3, LOW); //COLUNA 02
      digitalWrite(2, HIGH); //COLUNA 03
      digitalWrite(12, LOW); //COLUNA 04
      digitalWrite(A1, LOW); //COLUNA 05
      digitalWrite(11, LOW); //COLUNA 06
      digitalWrite(7, LOW); //COLUNA 07
      digitalWrite(6, LOW); //COLUNA 08
      break;

    case 12:
      digitalWrite(9, LOW); //COLUNA 01
      digitalWrite(3, LOW); //COLUNA 02
      digitalWrite(2, LOW); //COLUNA 03
      digitalWrite(12, HIGH); //COLUNA 04
      digitalWrite(A1, LOW); //COLUNA 05
      digitalWrite(11, LOW); //COLUNA 06
      digitalWrite(7, LOW); //COLUNA 07
      digitalWrite(6, LOW); //COLUNA 08
      break;

    case 13:
      digitalWrite(9, LOW); //COLUNA 01
      digitalWrite(3, LOW); //COLUNA 02
      digitalWrite(2, LOW); //COLUNA 03
      digitalWrite(12, LOW); //COLUNA 04
      digitalWrite(A1, HIGH); //COLUNA 05
      digitalWrite(11, LOW); //COLUNA 06
      digitalWrite(7, LOW); //COLUNA 07
      digitalWrite(6, LOW); //COLUNA 08
      break;

    case 14:
      digitalWrite(9, LOW); //COLUNA 01
      digitalWrite(3, LOW); //COLUNA 02
      digitalWrite(2, LOW); //COLUNA 03
      digitalWrite(12, LOW); //COLUNA 04
      digitalWrite(A1, LOW); //COLUNA 05
      digitalWrite(11, HIGH); //COLUNA 06
      digitalWrite(7, LOW); //COLUNA 07
      digitalWrite(6, LOW); //COLUNA 08
      break;

    case 15:
      digitalWrite(9, LOW); //COLUNA 01
      digitalWrite(3, LOW); //COLUNA 02
      digitalWrite(2, LOW); //COLUNA 03
      digitalWrite(12, LOW); //COLUNA 04
      digitalWrite(A1, LOW); //COLUNA 05
      digitalWrite(11, LOW); //COLUNA 06
      digitalWrite(7, HIGH); //COLUNA 07
      digitalWrite(6, LOW); //COLUNA 08
      break;

    case 16:
      digitalWrite(9, LOW); //COLUNA 01
      digitalWrite(3, LOW); //COLUNA 02
      digitalWrite(2, LOW); //COLUNA 03
      digitalWrite(12, LOW); //COLUNA 04
      digitalWrite(A1, LOW); //COLUNA 05
      digitalWrite(11, LOW); //COLUNA 06
      digitalWrite(7, LOW); //COLUNA 07
      digitalWrite(6, HIGH); //COLUNA 08
      break;
  }
}
