#include <LiquidCrystal.h> //Inclusão da biblioteca do display LCD

LiquidCrystal lcd(7, 6, 5, 4, 3, 2);

#define pinTrigger 11
#define pinEcho 12
#define ledVerde 10
#define ledAmarelo 9
#define ledVermelho 8

float pulse;          //Variável que armazena o tempo de duração do echo
float distancia_cm;   //Variável que armazena o valor da distância em centímetros

void setup()
{
  lcd.begin(16, 2);

  pinMode(pinTrigger, OUTPUT);   //Pino de trigger será saída digital
  pinMode(pinEcho, INPUT);       //Pino de echo será entrada digital
  digitalWrite(pinTrigger, LOW); //Saída trigger inicia em nível baixo

  pinMode(ledVerde, OUTPUT);
  pinMode(ledAmarelo, OUTPUT);
  pinMode(ledVermelho, OUTPUT);
  
  Serial.begin(9600);
}

void loop()
{
  trigPulse(); //Aciona o trigger do módulo ultrassônico
  ledDistancia();
  
  pulse = pulseIn(pinEcho, HIGH); //Mede o tempo em que o pino de echo fica em nível alto
  distancia_cm = pulse / 58.82;   //Valor da distância em centímetros

  // 340m/s
  // 34000cm/s

  /*
       100000 us - 17000 cm/s
            x us - 1cm
          1E6
     x = -----
         17E3
  */
  
  lcd.home();
  lcd.print("Curso de Arduino");
  lcd.setCursor(0, 1);
  lcd.print("Dist: ");
  lcd.print(distancia_cm);
  lcd.setCursor(12, 1);
  lcd.print("cm");

  Serial.print("Distancia: ");
  Serial.print(distancia_cm); //Imprime o valor na serial
  Serial.println("cm");
  delay(500);                   //Taxa de atualização

}

void trigPulse()
{
  digitalWrite(pinTrigger, HIGH);  //Pulso de trigger em nível alto
  delayMicroseconds(10);           //duração de 10 micro segundos
  digitalWrite(pinTrigger, LOW);   //Pulso de trigge em nível baixo
}

void ledDistancia()
{
  //Inicializa com todos os LEDs apagados
  digitalWrite(ledVerde, LOW);
  digitalWrite(ledAmarelo, LOW);
  digitalWrite(ledVermelho, LOW);

  //Acende cada LED conforme a distância indicada no sensor
  if (distancia_cm > 20)
  {
    digitalWrite(ledVerde, HIGH);
  }
  if (distancia_cm <= 20 and distancia_cm >= 10)
  {
    digitalWrite(ledAmarelo, HIGH);
  }
  if (distancia_cm < 10)
  {
    digitalWrite(ledVermelho, HIGH);
  }
}
