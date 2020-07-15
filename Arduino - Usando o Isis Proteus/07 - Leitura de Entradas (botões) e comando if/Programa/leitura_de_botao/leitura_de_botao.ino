#define btn 7
#define led 2

void setup() 
{
  pinMode(btn, INPUT);
  pinMode(led, OUTPUT);
}

void loop() 
{
  if(digitalRead(btn) == HIGH) //Verifica se o botão está pressionado, ou seja, recebendo nível lógico alto
  {
    digitalWrite(led, HIGH); //Liga o LED
    delay(2000);             //Espera 2s
    digitalWrite(led, LOW);  //Desliga o LED
  }
}
