#define botaoLiga 7
#define led 2

void setup()
{
  pinMode(botaoLiga, INPUT);
  pinMode(led, OUTPUT);
}

void loop()
{
  if (digitalRead(botaoLiga)) //Verifica se o botão está pressionado, ou seja, recebendo nível lógico alto
  {
    digitalWrite(led, HIGH); //Liga o LED
  }
  else
  { 
    digitalWrite(led, LOW); //Desliga o LED
  }
}
