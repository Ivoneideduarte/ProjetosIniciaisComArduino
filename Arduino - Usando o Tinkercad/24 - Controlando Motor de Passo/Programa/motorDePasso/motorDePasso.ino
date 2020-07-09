#include <Stepper.h>

#define entrada1 8
#define entrada2 9
#define entrada3 10
#define entrada4 11

const int passosPorGiro = 64; //Stride Angle - Datasheet
Stepper motorPasso(passosPorGiro, entrada1, entrada3, entrada2, entrada4);

void setup() 
{ 
  motorPasso.setSpeed(500); //Velocidade de passos - RPM
}

void loop() 
{
  for(int i=0; i<64; i++)
  {
    motorPasso.step(passosPorGiro);// Passo no sentido horário
  }
  delay(3000);
}
