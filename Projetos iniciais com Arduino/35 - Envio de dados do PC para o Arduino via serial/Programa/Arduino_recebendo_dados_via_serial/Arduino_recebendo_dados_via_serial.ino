#define led 3
int valorLido;

void setup()
{
  Serial.begin(9600);
  pinMode(led, OUTPUT);
}

void loop()
{ //Informa se existem dados chegando na serial

  if (Serial.available() > 0)
  { //Significa que existem dados para serem lidos
    valorLido = Serial.read(); //Pega o valor lido na serial e armazena na variável valorLido
  }
  if (valorLido == '1')
  {
    digitalWrite(led, HIGH);
  } else
  {
    digitalWrite(led, LOW);
  }
}
