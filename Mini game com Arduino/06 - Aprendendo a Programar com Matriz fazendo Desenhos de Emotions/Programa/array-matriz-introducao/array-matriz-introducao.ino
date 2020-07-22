String placas[3][4] =
{ //Matriz 3x4
  {"Uno", "Leonardo", "Mega", "Dueminalove"},
  {"Micro", "Mini", "Pro-Mini", "Nano"},
  {"Nano33", "Nano Every", "MKR", "Portenta"}
};
int i, j; //i = linha, j = coluna
String tipo;

void setup() 
{
  Serial.begin(9600);
}

void loop() 
{
  for (i = 0; i <= 3; i++) 
  {
    if (i == 0) 
    {
      tipo = "Comercial.";
    }
    else if (i == 1) 
    {
      tipo = "Pequenas.";
    }
    else 
    {
      tipo = "IoT.";
    }
    Serial.println("Placas Arduino do tipo: " + tipo);
    for (j = 0; j <= 3; j++) 
    {
      Serial.println(placas[i][j]);
      delay(1000);
    }
  }
  Serial.println();
}
