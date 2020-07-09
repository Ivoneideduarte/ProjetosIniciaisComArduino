 #define pot A0
#define motor 3
#define tmp 10
int valPot; // Valor do potenciômetro

void setup() 
{
 pinMode(pot, INPUT);
 pinMode(motor, OUTPUT);

 valPot=0; //Inicialização da variável 
 Serial.begin(9600);
}

void loop() 
{
  Serial.println(valPot = map(analogRead(pot), 0, 1023, 0, 255)); //Mapeando os valores do pot e pwm
  analogWrite(motor, valPot); //Ajustar a velocidade de rotação do motor de acordo com o potenciômetro
  delay(tmp); 
}
