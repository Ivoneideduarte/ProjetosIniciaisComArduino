#include <LiquidCrystal_I2C.h> //Inclusão da biblioteca do Display

//Variáveis globais
#define btCima 8
#define btBaixo 9
#define btTiro 10

LiquidCrystal_I2C lcd(0x27, 16, 2);

int vel = 100;
int pxnave, pynave, pxaste, pyaste, pxenergia, pyenergia, pxtiro, pytiro; //Posições x e y dos elementos
bool game, verTiro, verPilha;
int pontos;
double verEnergia;
int verTela;
int maxPontos=10;

byte nave[8] = {B11000, B01100, B01110, B01111, B01111, B01110, B01100, B11000};
byte asteroide[8] = {B00000, B00100, B01110, B10111, B11101, B01110, B00100, B00000};
byte explosao[8] = {B10001, B10101, B01010, B10100, B00101, B01010, B10101, B10001};
byte energia[8] = {B01110, B11011, B10001, B10101, B10101, B10101, B10001, B11111};
byte tiro[8] = {B00000, B00000, B00000, B00111, B00111, B00000, B00000, B00000};

void setup()
{
  //Inicialização das variáveis
  pxnave = pynave = pxaste = pyaste = pxenergia = pyenergia = pxtiro = pytiro = 0;
  pxtiro = -1; //Fora da tela
  pxaste = 12;
  verEnergia = 100; //bateria carregada
  verTela = 0;

  lcd.createChar(1, nave);
  lcd.createChar(2, asteroide);
  lcd.createChar(3, explosao);
  lcd.createChar(4, energia);
  lcd.createChar(5, tiro);

  lcd.init();
  lcd.backlight();
  lcd.clear();

  game = false;
  verTiro = verPilha = false; //Não irá inicializar com esses careacteres na tela
}

void loop()
{
  //Controles iniciais de posicionamento
  if (game)
  {
    verEnergia -= 0.25; //Diminuir a energia
    lcd.clear();
    if(verEnergia<=0)
    {
      game = 0;
      desenhaExplosaoNave(pxnave, pyaste);
      verTela = 2; //Perdeu
    }
    painel(13);
    if (digitalRead((btCima) == 1))
    {
      pynave = 0;
    }
    if (digitalRead((btBaixo) == 1))
    {
      pynave = 1;
    }
    if (digitalRead((btTiro) == 1))
    {
      pxtiro = 1;
      verTiro = true;
      pytiro = pynave;
    }
    pxaste -= 1;
    desenhaNave(pxnave, pynave);
    desenhaAsteroide(pxaste, pyaste);
    if (verTiro)
    {
      desenhaTiro(pxtiro, pytiro);
      pxtiro += 1; //Andar para a direita
    }
    if (pxaste < 0) //Ultrapassou a tela pela esquerda
    {
      pxaste = 12;
      pyaste = random(0, 2);
    }
    if (pxtiro > 16) //Saiu pela direita
    {
      verTiro = false;
      pxtiro = -1;
    }
    //Verificação do tiro com o asteroide
    if ((pxtiro == pxaste + 1) && (pytiro == pyaste) || (pxtiro == pxaste) && (pytiro == pyaste))
    { //Acrescenta a pontuação e continua o game
      verTiro = false;
      pxtiro = -1;
      desenhaExplosaoAsteroide(pxaste, pyaste);
      pyaste = random(0, 2);
      pxaste = 12;
      pontos += 2;
      if(pontos>=maxPontos)
      {
        game = 0;
        desenhaExplosaoNave(pxnave, pyaste);
        verTela = 1; //Ganhou
      }
    }
    if ((pxnave == pxaste) && (pynave == pyaste))
    { //Houve colisão do asteroide com a nave
      game = 0;
      desenhaExplosaoNave(pxnave, pyaste);
      verTela = 2; //Perdeu
    }
    if (!verPilha) //Se mão tiver pilha
    {
      if (random(0, 60) > 58)
      {
        pxenergia = 12;
        verPilha = true;
        pyenergia = random(0, 2);
      }
      else
      {
        pxenergia -= 1;
        desenhaEnergia(pxenergia, pyenergia);
        if ((pxnave == pxenergia + 1) && (pynave == pyenergia) || (pxnave == pxenergia) && (pynave == pyenergia))
        { //Colisao da pilha com o jogador
          verPilha = false;
          pxenergia = -1;
          verEnergia = 100;
        }
      }
    }
    delay(vel); //Controla a velocidade
  }
  else
  {
    tela(verTela);
    if (digitalRead(btTiro) == 1)
    {
      reset();
    }
  }

}

//Sessão de funções
void desenhaNave(int px, int py)
{
  lcd.setCursor(px, py);
  lcd.write(1);
}
void desenhaAsteroide(int px, int py)
{
  lcd.setCursor(px, py);
  lcd.write(2);
}
void desenhaEnergia(int px, int py)
{
  lcd.setCursor(px, py);
  lcd.write(4);
}
void desenhaTiro(int px, int py)
{
  lcd.setCursor(px, py);
  lcd.write(5);
}

void desenhaExplosaoNave(int px, int py)
{
  lcd.clear();
  lcd.setCursor(px, py);
  lcd.write(3);
  delay(1000);
  lcd.clear();
}

void desenhaExplosaoAsteroide(int px, int py)
{
  lcd.setCursor(px, py);
  lcd.write(3);
  delay(1000);
  lcd.clear();
}

void reset()
{ //Reiniciar o game
  pontos = 0;
  verEnergia = 100;
  game = true;
  verTela = 0;
}

void painel(int px)
{
  lcd.setCursor(px, 0);
  lcd.print(pontos);
  lcd.setCursor(px, 1);
  lcd.print(verEnergia);
}
void tela(int condicao)
{ // 0 = Tela inicial | 1 = ganhou | 2 = perdeu
  if (condicao < 1)
  {
    lcd.setCursor(3, 0); //posição fixa
    lcd.print("NAVE");
    //Iniciar o game
    lcd.setCursor(1, 0); //posição fixa
    lcd.print("Pressione tiro");
  } else
  {
    String txt = {(condicao > 1 ? "PERDEU" : "GANHOU")}; //operador ternário
    lcd.setCursor(9, 0); //posição fixa
    lcd.print("pts:");
    lcd.setCursor(13, 0); //posição fixa
    lcd.print(pontos);
    lcd.setCursor(1, 0); //posição fixa
    lcd.print(txt);
    lcd.setCursor(1, 0); //posição fixa
    lcd.print("Pressione tiro");
  }


}
