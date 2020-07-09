//Portas analógicas: São portas de entrada

#define pot A0 // Potenciômetro conectado na porta A0 do Arduino 

void setup() 
{
  pinMode(pot, INPUT); // Configura o pino analógico A0 como entrada, linha de código opcional

  Serial.begin(9600); //Inicia comunicação com monitor serial com velocidade de 9600bps
}

void loop() 
{
  Serial.println(analogRead(pot)); //Retorna o valor lido no pino de entrada
  delay(100);
}
