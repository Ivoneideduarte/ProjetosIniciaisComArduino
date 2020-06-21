#define led 3     // Definindo a porta 3 do Arduino com o nome 'led' 
#define maximo 16 // Valor máximo do pwm: 255
#define minimo 0  // Valor mínimo do pwm: 0
#define tmp 100   // Definindo o tempo de espera

void setup()
{
  pinMode(led, OUTPUT); // Configura o pino digital 3 como saída
}

void loop()
{
  //  Para (valor_inicial até condição_final passo n)faça
  //  Inicio
  //      Instruções;
  //  Fim;
  
  //  valor_inicial é uma instrução de atribuição do valor inicial do laço para a variável de controle.
  //  condição final é uma condição que controla o laço.
  //  passo é o incremento do laço.
  
  for (int i = minimo; i < maximo; i++)
  {
    analogWrite(led, i);
    //digitalWrite(led, HIGH);
    delay(tmp);
  }

  for (int i = maximo; i > minimo; i--)
  {
    analogWrite(led, i);
    //digitalWrite(led, LOW);
    delay(tmp);
  }
}
