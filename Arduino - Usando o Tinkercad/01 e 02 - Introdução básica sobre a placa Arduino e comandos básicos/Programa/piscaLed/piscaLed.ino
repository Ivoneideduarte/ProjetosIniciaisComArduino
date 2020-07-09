void setup()
{
  //Configurações iniciais

  /*
   * pinMode(pino, modo); 
   * pino: é o número da porta que queremos configurar.
   * modo pode ser:INPUT(entrada)
   *               OUTPUT(saída)
   *               INPUT_PULLUP
   * Permite configurar um pino específico para se comportar como um pino de entrada ou de saída.
   * Por padrão, os pinos do Arduino tem a função de entrada, de modo que não é necessário declará-los neste caso.
   * Já os pinos de saída devem ser configurados por meio dessa função, o que os leva a um estado de baixa impedância, de modo que eles podem fornecer corrente para outros circuitos.
   * Os pinos do microcontrolador Atmega podem fornecer até 40mA de corrente para outros componentes ou circuitos.
  */
  pinMode(13, OUTPUT); //OUTPUT = Saída - INPUT = Entrada
}

void loop()
{
  /*
   * digitalWrite(pino, valor);
   * pino: é o número do pino considerado.
   * valor: HIGH ou LOW
   * Escreve um valor HIGH(alto) ou LOW(baixo) em um pino digital que tenha sido configurado como OUTPUT(saída).
   * O valor HIGH equivale a uma tensão de 5v(ou 3.3v em algumas placas), e o valor LOW, a uma tensão elétrica  de 0v.
   */
  digitalWrite(13, HIGH); //HIGH = Ligada (5v) - LOW = Desligada (0v)
  delay(500);
  digitalWrite(13, LOW);
  delay(500);
}
