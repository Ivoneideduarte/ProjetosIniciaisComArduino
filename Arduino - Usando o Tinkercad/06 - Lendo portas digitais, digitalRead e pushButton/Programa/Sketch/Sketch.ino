#define led 4           // Definindo a porta 4 do Arduino com o nome 'led' 
#define botao 3         // Definindo a porta 3 do Arduino com o nome 'botao' 
int botaoClicado = 0;   //Definindo variável 'botaoClicado' do tipo inteiro, inicializando com 0
int botaoLiberado = 0;  //Definindo variável 'botaoLiberado' do tipo inteiro, inicializando com 0

//Função que auxilia na troca do led
void trocaLed()
{
  if(digitalRead(led) == HIGH)
  { //Se a leitura do led estiver em nível lógico alto(5v), passará para o nível lógico baixo(0v)
    digitalWrite(led, LOW);
  }
  else
  { //Senão o led irá ligar
    digitalWrite(led, HIGH);
  }
}

//Função para controlar o estado do botão
void keyup()
{
  if((botaoClicado == 1) and (botaoLiberado == 1))
  { //Se os dois estados do botão forem verdadeiros, irão retornar para zero e trocar o estado do led
    botaoClicado = 0;
    botaoLiberado = 0;
    trocaLed();
  }
}

void setup()
{
  pinMode(led, OUTPUT);  // Configura o pino digital 4 como saída
  pinMode(botao, INPUT); // Configura o pino digital 3 como entrada
}

void loop()
{
  //Ao pressionar o botão, o led acende e permanece aceso e ao clicar novamente, ele será apagado.
  if (digitalRead(botao) == HIGH)
  { // Estou lendo o estado do botão, caso esteja pressionado irá ligar o led
    botaoClicado = 1;
    botaoLiberado = 0;
  }
  else
  { //Caso o botão não esteja pressionado, o led permanecerá desligado
    botaoLiberado = 1;
  }
  keyup(); //Chama a função declarada
}
