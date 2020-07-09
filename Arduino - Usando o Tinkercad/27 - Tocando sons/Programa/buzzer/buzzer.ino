#define buzzer 9

void setup()
{
  pinMode(buzzer, OUTPUT);
}

void loop()
{
  //tone(porta, frequência)
  //noTone(porta)
  
  //tone(porta, frequência, duração)
  //31 - 4978hz
  
  tone(9, 200, 500);
  delay(550); 
  tone(9, 300, 500);
  delay(550);
  tone(9, 400, 500);
  delay(550);
  tone(9, 500, 500);
  delay(3000);
}
