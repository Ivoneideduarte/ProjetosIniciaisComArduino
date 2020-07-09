#include <Servo.h>

#define pot A0 //Potenciômetro

Servo s1; //Servo

int angS1; //Ângulo do servo
int a;

void setup() {
  s1.attach(2); //Porta de controle que o serve está ligado
  angS1=0; //Inicializa em 0
  s1.write(angS1); //0 a 180
  Serial.begin(9600);
}

void loop() {
  angS1=0;
  s1.write(angS1);
  a = s1.read();
  Serial.println(a);
  delay(3000);

  angS1=90;
  s1.write(angS1);
  a = s1.read();
  Serial.println(a);
  delay(3000);

  angS1=180;
  s1.write(angS1);
  a = s1.read();
  Serial.println(a);
  delay(3000);
}
