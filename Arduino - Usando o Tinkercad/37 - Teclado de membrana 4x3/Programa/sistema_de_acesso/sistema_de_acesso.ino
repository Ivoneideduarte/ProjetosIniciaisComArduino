#include <Keypad.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <Servo.h>

Servo motor1;
const byte numRows = 4; // Número de linhas no teclado
const byte numCols = 3; // Número de colunas no teclado
const int buzzer = 9;
int Led_vermelho = 10;
int Led_verde = 11;
int fechadura = 13;
int contador = 0;
int estadoBotao = 0;

char senha[ ] = {'4', '5', '6', '7', '8', '9', '\0'};
char palavra[ ] = {'0', '0', '0', '0', '0', '0', '\0'};

//Keymap define a tecla pressionada de acordo com a linha e colunas tal como aparece no teclado

char keymap[numRows][numCols] =
{
  {'1', '2', '3', },

  {'4', '5', '6', },

  {'7', '8', '9', },

  {'*', '0', '#', }
};
//Código que mostra as conexões do teclado para os terminais arduino

byte rowPins[numRows] = {8, 7, 6, 5};
byte colPins[numCols] = {4, 3, 2};

LiquidCrystal_I2C lcd(0x27, 16, 2);
Keypad myKeypad = Keypad(makeKeymap(keymap), rowPins, colPins, numRows, numCols);

void setup()
{
  motor1.attach(12);
  digitalWrite(fechadura, HIGH);

  lcd.init();
  lcd.backlight();
  lcd.clear();
  lcd.print("Inicializando..");
  delay(5000); //2000
  lcd.clear();
  lcd.home();
  lcd.print("CHAVE DE ACESSO:");

  motor1.write(0);

  pinMode(13, OUTPUT);
  pinMode(12, INPUT_PULLUP);
  pinMode(Led_verde, OUTPUT);
  pinMode(Led_vermelho, OUTPUT);

  Serial.begin(9600);
}

void loop()
{
  char key = myKeypad.getKey();

  if (key)
  {
    lcd.home();
    lcd.print("CHAVE DE ACESSO:");
    lcd.setCursor(contador, 1);
    lcd.print(key);

    tone(buzzer, 2500);
    delay(10);
    noTone(buzzer);
    delay(100);

    palavra[contador] = key;
    contador++;

    if (contador == 6 )
    {
      palavra[contador] = '\0';

      if ((palavra[0] == senha[0]) && (palavra[1] == senha[1]) && (palavra[2] == senha[2]) && (palavra[3] == senha[3]) && (palavra[4] == senha[4]) && (palavra[5] == senha[5]) && (palavra[6] == senha[6]))
      {
        lcd.clear();
        lcd.print("CHAVE CORRETA!");
        delay (600);
        lcd.clear();

        tone(buzzer, 2500);
        delay(100);
        tone(buzzer, 900);
        delay(100);
        noTone(buzzer);

        digitalWrite(Led_verde, HIGH); //liga Led verde

        lcd.print("Porta Aberta");

        digitalWrite(fechadura, LOW);
        delay(6000);

        digitalWrite(Led_verde, LOW); //desliga Led verde

        lcd.clear();
        lcd.print("Porta Fechada");
        motor1.write(180);

        digitalWrite(fechadura, HIGH);
        delay(1000);

        contador = 0;

        lcd.clear();
        lcd.print ("CHAVE DE ACESSO:");
      }
      else
      {
        lcd.clear();
        lcd.print("CHAVE ERRADA!");

        digitalWrite(Led_vermelho, HIGH); //liga Led vermelho

        tone(buzzer, 300);
        delay(500);
        noTone(buzzer);
        delay(500);
        tone(buzzer, 300);
        delay(100);
        noTone(buzzer);
        delay(500);

        delay(2000);

        digitalWrite(Led_vermelho, LOW); //desliga Led vermelho

        contador = 0;

        lcd.clear();
        lcd.print("CHAVE DE ACESSO:");
      }
    }
  }
}
