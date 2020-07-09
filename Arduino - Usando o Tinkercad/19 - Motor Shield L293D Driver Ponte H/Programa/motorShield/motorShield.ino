#include <AFMotor.h>

AF_DCMotor motor1(1);

void setup() 
{
  motor1.setSpeed(0); //Definindo a velocidade do motor, pwm (0 - 255)  
}

void loop() 
{
  motor1.setSpeed(255); //Velocidade máxima
  motor1.run(FORWARD); //Sentido de rotação(Horário)
  delay(5000);

  motor1.setSpeed(0);
  motor1.run(RELEASE);
  delay(200);

  motor1.setSpeed(255); //Velocidade máxima
  motor1.run(BACKWARD); //Sentido de rotação(Anti-Horário)
  delay(5000);

  motor1.setSpeed(0);
  motor1.run(RELEASE);
  delay(200);
}
