char letras[8] = {'I', 'v', 'o', 'n', 'e', 'i', 'd', 'e'};

void setup() 
{
  Serial.begin(9600);
}

void loop() 
{
  for (byte x = 0; x <= 7; x++) 
  {
    Serial.print(letras[x]);
    delay(500);
  }
  Serial.println();
}
