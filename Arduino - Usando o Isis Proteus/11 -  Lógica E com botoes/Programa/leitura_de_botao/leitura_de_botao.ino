#define botao1 8
#define botao2 7
#define buzzer 3
#define led 2

void setup()
{
  pinMode(botao1, INPUT_PULLUP);
  pinMode(botao2, INPUT_PULLUP);
  pinMode(led, OUTPUT);
  pinMode(buzzer, OUTPUT);
}

void loop()
{
  //  if (!digitalRead(botao1))
  //  {
  //    if (!digitalRead(botao2))
  //    {
  //      digitalWrite(led, HIGH);
  //      delay(2000);
  //      digitalWrite(led, LOW);
  //    }
  //  }

  if (!digitalRead(botao1) and !digitalRead(botao2) ) //Operador lógico E (and | &&)
  {//Caso os dois botões estiverem pressionados simultaneamente, irá acender o LED
    digitalWrite(led, HIGH);
    delay(2000);
    digitalWrite(led, LOW);
  }
}
