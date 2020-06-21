//Função Constrain => Serve para restringir uma faixa de leitura/retorno.
//constrain(valor_lido, min_saida, max_saida);
#define pot A0

void setup() 
{
  pinMode(pot, INPUT);
  Serial.begin(9600);
}

void loop() 
{
  Serial.println(constrain(analogRead(pot), 500, 800));
  delay(250);
}
