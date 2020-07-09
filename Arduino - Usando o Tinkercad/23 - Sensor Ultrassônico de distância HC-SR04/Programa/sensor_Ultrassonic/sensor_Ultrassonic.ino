#include <HCSR04.h>

#define pinTrigger 3
#define pinEcho 2

UltraSonicDistanceSensor distanceSensor(pinTrigger, pinEcho);  
  
float  distancia_cm, distancia_m;

void setup () 
{
    Serial.begin(9600);  
}

void loop () 
{   
    distancia_cm = distanceSensor.measureDistanceCm(); //Distância em cm
    distancia_m/100;
    Serial.print("Distância: ");
    Serial.println(distancia_cm);
    //Serial.println("cm | ");
    //Serial.println(distancia_m);
    //Serial.println("m");
    Serial.println("-------------------------------");
    delay(300);
}
