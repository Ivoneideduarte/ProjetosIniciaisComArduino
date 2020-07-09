//Variáveis globais
int led = 10; //Variável 'led' do tipo inteiro

void setup() 
{
  //Configurações iniciais
  pinMode(led,OUTPUT); //OUTPUT = Saída - INPUT = Entrada
}

void loop() 
{
  digitalWrite(led,HIGH); //HIGH = Liga 5v  
  delay(2000);            //Espera 2000 milissegundos = 2 segundos
  digitalWrite(led,LOW);  //LOW = Desliga 0v  
  delay(2000);            //Espera 2000 milissegundos = 2 segundos
}
