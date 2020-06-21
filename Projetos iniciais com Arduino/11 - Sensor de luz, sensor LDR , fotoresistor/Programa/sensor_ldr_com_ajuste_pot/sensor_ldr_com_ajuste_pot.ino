#define ldr A0
#define led 2

int vldr = 0;

void setup()
{
  pinMode(ldr, INPUT);
  pinMode(led, OUTPUT);

  Serial.begin(9600);
}

void loop()
{
  //Valor de leitura dos sensores
  vldr = analogRead(ldr);
 
  if(vldr<300)
  {
    digitalWrite(led, LOW);
  }
  else
  {
    digitalWrite(led, HIGH);
  }
  Serial.println(vldr);
  
  delay(100);
}
