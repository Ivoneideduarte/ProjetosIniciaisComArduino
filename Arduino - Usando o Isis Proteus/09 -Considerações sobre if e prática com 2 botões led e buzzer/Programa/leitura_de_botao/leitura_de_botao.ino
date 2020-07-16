#define botaoLiga 7
#define botaoDesliga 8
#define buzzer 3
#define led 2

void setup()
{
  pinMode(botaoLiga, INPUT_PULLUP);
  pinMode(botaoDesliga, INPUT_PULLUP);
  pinMode(buzzer, OUTPUT);
  pinMode(led, OUTPUT);
}

void loop()
{
  if (!digitalRead(botaoLiga)) //Verifica se o botão está pressionado, ou seja, recebendo nível lógico baixo
  { //Porta inversora NOT (!)
    digitalWrite(led, HIGH); //Liga o LED
  }
  if (!digitalRead(botaoDesliga))
  {
    digitalWrite(buzzer, HIGH);
    delay(150);
    digitalWrite(buzzer, LOW);
    delay(150);

    digitalWrite(buzzer, HIGH);
    delay(150);
    digitalWrite(buzzer, LOW);
    delay(150);

    digitalWrite(buzzer, HIGH);
    delay(150);
    digitalWrite(buzzer, LOW);
    delay(150);

    digitalWrite(led, LOW);
  }
}
