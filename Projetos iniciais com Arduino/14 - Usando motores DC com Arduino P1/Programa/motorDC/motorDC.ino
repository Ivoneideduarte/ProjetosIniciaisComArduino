//O transistor liga e / ou desliga o motor 
//Se o pino base receber uma tensão, o transistor permite a passagem de corrente
//Se o pino base NÃO receber tensão, o transistor bloqueia a passagem de corrente

#define motor 2

void setup() 
{
  pinMode(motor, OUTPUT);
  digitalWrite(motor, HIGH);
}

void loop() 
{
  
}
