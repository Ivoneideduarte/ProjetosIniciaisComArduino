#define btn 7
#define led 2

void setup() 
{
  pinMode(btn, INPUT_PULLUP);
  pinMode(led, OUTPUT);
}

void loop() 
{
  if(digitalRead(btn) == LOW) //Verifica se o botão está pressionado, ou seja, recebendo nível lógico baixo
  {
    digitalWrite(led, HIGH); //Liga o LED
    delay(2000);             //Espera 2s
    digitalWrite(led, LOW);  //Desliga o LED
  }
}
