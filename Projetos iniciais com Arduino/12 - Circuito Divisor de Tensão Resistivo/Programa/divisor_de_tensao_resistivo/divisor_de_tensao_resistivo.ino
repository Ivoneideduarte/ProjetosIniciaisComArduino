#define portaAnalogica A0

void setup()
{
  pinMode(portaAnalogica, INPUT);

  Serial.begin(9600);
}

void loop()
{
  Serial.println(analogRead(portaAnalogica));
}
