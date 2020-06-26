#define pino A0
float temp = 0.0, ultimaTemp = 0.0;
//int temp = 0, ultimaTemp = 0;
int media[10];

void setup()
{
  Serial.begin(9600);
}

void loop()
{
  /*
      Faixa de tensão
      0v = 0
      5v = 1023
      Cada G.C.: 10mV/ºC
      Tensão em A0 = (valor lido em A0) * (5.0/1023)
      Temperatura = Tensão em A0 / 10mV

      Logo

      temp = (valor_lido_A0 * (5.0/1023)) / 10mV
      temp = (valor_lido_A0 * (5.0/1023)) / 0.01

  */

  for (int i = 0; i < 10; i++)
  { //Média da temperatura
    media[i] = (analogRead(pino) * (5.0 / 1023)) / 0.01;
    temp = temp + media[i];
    delay(100);
  }
  temp = temp / 10.0;

  if (temp != ultimaTemp)
  {
    ultimaTemp = temp;
    Serial.print("Temp: ");
    Serial.print(temp);
    Serial.println("ºC");
    delay(1000);
  }
}
