#define led 4 // Led conectado na porta 4 do Arduino
#define btn 3 // Botão conectado na porta 3 do Arduino

void setup() 
{
  pinMode(led, OUTPUT); // Configura o pino digital 4 como saída
  pinMode(btn, INPUT);  // Configura o pino digital 3 como entrada
}

void loop() 
{
  //Leitura do estado do botão
  if(digitalRead(btn) == HIGH) //Botão acionado
  { // Se a leitura do botão estiver em nível lógico alto(5v)
    digitalWrite(led, HIGH); // Ativa o pino digital 4
  } 
  else //Botão não pressionado
  { // Senão
    digitalWrite(led, LOW); // Desativa o pino digital 4
  }
}
