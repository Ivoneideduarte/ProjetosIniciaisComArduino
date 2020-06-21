#define pinBotao 3
#define pinLed 4

void setup()
{
  /*O botão será configurado no modo input pullup
    Isso faz com que o resistir interno do Arduino de pullup seja habilitado
  */
  pinMode(pinBotao, INPUT_PULLUP);
  pinMode(pinLed, OUTPUT);
}

void loop()
{
  if (digitalRead(pinBotao))
  { //Botão não pressionado, led acesso
    digitalWrite(pinLed, HIGH);
  }
  else
  { //Botão pressionado, led apagado
     digitalWrite(pinLed, LOW);
  }
}
