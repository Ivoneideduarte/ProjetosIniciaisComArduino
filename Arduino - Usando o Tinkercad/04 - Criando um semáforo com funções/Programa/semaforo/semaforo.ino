// Para definição das portas é recomendado o 
// #define por não armazenar dados na memória e pelas portas serem valores fixos, 
// diferentemente dos tipos primitivos de variáveis

#define ledVermelho 10 // Led vermelho ligado na porta 10 do Arduino
#define ledAmarelo 9   // Led amarelo ligado na porta 9 do Arduino
#define ledVerde 8     // Led verde ligado na porta 8 do Arduino

void setup() 
{
  // pinMode(pino, modo)
  // Esta função configura o pino especificado para funcionar como uma entrada(INPUT) ou saída(OUTPUT)
 
  pinMode(ledVermelho, OUTPUT); // Configura o pino digital 10 como saída
  pinMode(ledAmarelo, OUTPUT);  // Configura o pino digital 9 como saída
  pinMode(ledVerde, OUTPUT);    // Configura o pino digital 8 como saída
}

void loop() 
{ 
  // Chamando as funções e determinando o tempo
  vermelho(2500);
  verde(2000);
  amarelo(1500);
}

// Funções
void vermelho(int tmp)
{
  // digitalWrite(pino, valor)
  // Aciona um valor ligado(HIGH) ou desligado(LOW) em um pino digital
  
  digitalWrite(ledVermelho, HIGH); // Ativa o pino digital 10
  digitalWrite(ledAmarelo, LOW);   // Desativa o pino digital 9
  digitalWrite(ledVerde, LOW);     // Desativa o pino digital 8
  delay(tmp);                      // Tempo de espera
}

void verde(int tmp)
{
  digitalWrite(ledVermelho, LOW); // Desativa o pino digital 10
  digitalWrite(ledAmarelo, LOW);  // Desativa o pino digital 9
  digitalWrite(ledVerde, HIGH);   // Ativa o pino digital 8
  delay(tmp);                     // Tempo de espera
}

void amarelo(int tmp)
{
  digitalWrite(ledVermelho, LOW); // Desativa o pino digital 10
  digitalWrite(ledAmarelo, HIGH); // Ativa o pino digital 8
  digitalWrite(ledVerde, LOW);    // Desativa o pino digital 8
  delay(tmp);                     // Tempo de espera
}
