#define pinRele 7
#define pinSom 4

bool rele;

void setup() 
{
  pinMode(pinRele,OUTPUT);
  pinMode(pinSom,INPUT);
  rele = false; // Inicializando a variável relé em false
  digitalWrite(pinRele,rele); // Inicia desligado
}

void loop() 
{
  if(digitalRead(pinSom)==HIGH)
  { // Detecta o som
    rele=!rele; // Troca o estado do relé
  }
  digitalWrite(pinRele,rele);
}
