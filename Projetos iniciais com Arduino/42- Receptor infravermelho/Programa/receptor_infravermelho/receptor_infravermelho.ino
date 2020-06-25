#include <IRremote.h> // Inclusão da biblioteca

#define receptor 11

IRrecv recIR(receptor);
decode_results resultado; // Decodificação do resultado

void setup()
{
  Serial.begin(9600);
  recIR.enableIRIn(); // Inicializar receptor IR
}

void loop()
{
  if (recIR.decode(&resultado))
  { // Verifica se houve envio de um sinal
    Serial.print("Valor: ");
    Serial.println(resultado.value, HEX); // Faz a impressão do valor do sinal recebido em hexadecimal
    recIR.resume(); // Prepara para receber um novo comando
  }
  
}
