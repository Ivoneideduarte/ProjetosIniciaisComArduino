#define velm1 3 //Controle de velocidade do motor
#define m1a 2   
#define m1b 4
#define velm2 11 //Controle de velocidade do motor
#define m2a 12
#define m2b 13
#define tmp 5000

int vel = 255; //Velocidade máxima
void setup() 
{
  pinMode(velm1, OUTPUT);
  pinMode(m1a, OUTPUT);
  pinMode(m1b, OUTPUT);
  pinMode(velm2, OUTPUT);
  pinMode(m2a, OUTPUT);
  pinMode(m2b, OUTPUT);
  
  analogWrite(velm1, 0);
  digitalWrite(m1a, LOW);
  digitalWrite(m1b, LOW);
  analogWrite(velm2, 0);
  digitalWrite(m2a, LOW);
  digitalWrite(m2b, LOW);
}

void loop() 
{
  //M1
  analogWrite(velm1, vel);
  digitalWrite(m1a, LOW);
  digitalWrite(m1b, HIGH);
  
  //M2
  analogWrite(velm2, vel);
  digitalWrite(m2a, HIGH);
  digitalWrite(m2b, LOW);
  
  delay(tmp);

  //M1
  digitalWrite(m1a, LOW);
  digitalWrite(m1b, HIGH);
  //M2
  digitalWrite(m2a, LOW);
  digitalWrite(m2b, HIGH);
 
  
}
