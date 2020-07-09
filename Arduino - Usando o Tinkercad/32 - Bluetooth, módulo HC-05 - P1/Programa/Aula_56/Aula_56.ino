int portas_led[4] = {2, 3, 4, 5}; //Portas de conexão digital

void setup()
{
  for (int pinos_led = 0; pinos_led < 4; pinos_led++)
  {
    pinMode(portas_led[pinos_led], OUTPUT);
  }
  Serial.begin(9600); //Inicializa a porta serial
}

void loop() 
{
  char c = Serial.read(); //O valor lido na serial será armazenado na variável c 
  // Posição 0 = portas_led[0]
  if (c == 'A') {digitalWrite(portas_led[0], HIGH);} //Quadrado
  if (c == 'a') {digitalWrite(portas_led[0], LOW);}  //Triângulo
  // Posição 1 = portas_led[1]
  if (c == 'B') {digitalWrite(portas_led[1], HIGH);}
  if (c == 'b') {digitalWrite(portas_led[1], LOW);}
  // Posição 2 = portas_led[2]
  if (c == 'C') {digitalWrite(portas_led[2], HIGH);}
  if (c == 'c') {digitalWrite(portas_led[2], LOW);}
  // Posição 3 = portas_led[3]
  if (c == 'D') {digitalWrite(portas_led[3], HIGH);}
  if (c == 'd') {digitalWrite(portas_led[3], LOW);}
}
