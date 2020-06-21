#include <Servo.h> //Biblioteca do Servo

//Definição das portas dos potenciômetros
#define pot1 A0 //Controla o giro do eixo do braço
#define pot2 A1
#define pot3 A2
#define pot4 A3 //Controla a abertura e fechamento da garra

//Declaração dos servos
Servo s1,s2,s3,s4;
 
//Variáveis para receber o ângulo de posicionamento de cada um dos servos
int angS1,angS2,angS3,angS4;

void setup() {
  //Anexar a porta do Arduino que o servo está conectado
  s1.attach(2);
  s2.attach(3);
  s3.attach(4);
  s4.attach(5);
}

void loop() {
  //Ler o valor do potenciômetro e transformar em ângulo e enviar para o servo
  angS1=map(analogRead(pot1),0,1023,0,180);
  angS2=map(analogRead(pot2),0,1023,0,180);
  angS3=map(analogRead(pot3),0,1023,0,180);
  angS4=map(analogRead(pot4),0,1023,0,180);
  s1.write(angS1);
  s2.write(angS2);
  s3.write(angS3);
  s4.write(angS4);
  delay(100);
}
