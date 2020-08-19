// Programa: Relógio com módulo DS3231 e LCD 20x4
// Autora : Ivoneide Duarte
// Data: 19/08/20

#include <Wire.h>
#include <dht.h>
#include <LiquidCrystal_I2C.h>

#define DS1307_ADDRESS 0x68
#define pinoDHT11 4

// Inicializa o LCD
LiquidCrystal_I2C lcd(0x25, 20, 4);
dht sensorDHT11;

byte zero = 0x00;

byte sorriso[8] = {
  B00000,
  B01010,
  B01010,
  B00000,
  B10001,
  B01110,
  B00000,
  B00000
};
byte coracao[8] = {
  B00000,
  B01010,
  B11111,
  B11111,
  B11111,
  B01110,
  B00100,
  B00000
};

byte coracao_cheio[8] = {
  B11111,
  B10101,
  B00000,
  B00000,
  B00000,
  B10001,
  B11011,
  B11111
};

byte pontoElevado[8] = {
  B00111,
  B00101,
  B00111,
  B00000,
  B00000,
  B00000,
  B00000,
  B00000
};

byte temperatura[8] = {
  B00100,
  B01010,
  B01010,
  B01110,
  B01110,
  B11111,
  B11111,
  B01110
};

byte umidade[8] = {
  B00100,
  B00100,
  B01010,
  B01010,
  B10001,
  B10001,
  B10001,
  B01110
};

void setup()
{
  // Define o LCD com 20 colunas e 4 linhas
  Wire.begin();
  lcd.init();
  lcd.backlight(); //Inicia o visor LCD com a luz ligada
  Serial.begin(9600);
  lcd.createChar(0, coracao);
  lcd.createChar(1, sorriso);
  lcd.createChar(2, coracao_cheio);
  lcd.createChar(3, pontoElevado);
  lcd.createChar(4, temperatura);
  lcd.createChar(5, umidade);

  // A linha abaixo pode ser retirada apos setar a data e hora
  //SelecionaDataeHora();
}

void loop()
{
  Mostrarelogio();
  DHT11();
  delay(1000);
}

void SelecionaDataeHora() // Seta a data e a hora do DS1307
{
  byte segundos = 00;     // Valores de 0 a 59
  byte minutos = 03;      // Valores de 0 a 59
  byte horas = 15;        // Valores de 0 a 23
  byte diadasemana = 3;   // Valores de 0 a 6 (0=Domingo, 1 = Segunda...)
  byte diadomes = 03;     // Valores de 1 a 31
  byte mes = 06;          // Valores de 1 a 12
  byte ano = 20;          // Valores de 0 a 99
  Wire.beginTransmission(DS1307_ADDRESS);
  // Stop no CI para que o mesmo possa receber os dados
  Wire.write(zero);

  // As linhas abaixo escrevem no CI os valores de
  // data e hora que foram colocados nas variaveis acima
  Wire.write(ConverteParaBCD(segundos));
  Wire.write(ConverteParaBCD(minutos));
  Wire.write(ConverteParaBCD(horas));
  Wire.write(ConverteParaBCD(diadasemana));
  Wire.write(ConverteParaBCD(diadomes));
  Wire.write(ConverteParaBCD(mes));
  Wire.write(ConverteParaBCD(ano));
  Wire.write(zero); //Start no CI
  Wire.endTransmission();
}

byte ConverteParaBCD(byte val)
{
  // Converte o número de decimal para BCD
  return ( (val / 10 * 16) + (val % 10) );
}

byte ConverteparaDecimal(byte val)
{
  // Converte de BCD para decimal
  return ( (val / 16 * 10) + (val % 16) );
}

void Mostrarelogio()
{
  Wire.beginTransmission(DS1307_ADDRESS);
  Wire.write(zero);
  Wire.endTransmission();
  Wire.requestFrom(DS1307_ADDRESS, 7);
  int segundos = ConverteparaDecimal(Wire.read());
  int minutos = ConverteparaDecimal(Wire.read());
  int horas = ConverteparaDecimal(Wire.read() & 0b111111);
  int diadasemana = ConverteparaDecimal(Wire.read());
  int diadomes = ConverteparaDecimal(Wire.read());
  int mes = ConverteparaDecimal(Wire.read());
  int ano = ConverteparaDecimal(Wire.read());
  // Imprime mensagem na primeira linha do display
  lcd.setCursor(4, 0);
  lcd.print("MECATRONICA ");
  lcd.setCursor(0, 0);
  lcd.write(2);


  lcd.setCursor(19, 0);
  lcd.write(2);
  
  // Mostra a hora atual no display
  lcd.setCursor(6, 2);
  if (horas < 10)
  {
    lcd.print("0");
  }
  lcd.print(horas);
  lcd.print(":");
  if (minutos < 10)
  {
    lcd.print("0");
  }
  lcd.print(minutos);
  lcd.print(":");
  if (segundos < 10)
  {
    lcd.print("0");
  }
  lcd.print(segundos);

  // Mostra a data atual no display
  lcd.setCursor(0, 3);
  lcd.print("Data: ");
  lcd.setCursor(6, 3);
  if (diadomes < 10)
  {
    lcd.print("0");
  }
  lcd.print(diadomes);
  lcd.print(".");
  if (mes < 10)
  {
    lcd.print("0");
  }
  lcd.print(mes);
  lcd.print(".");
  lcd.print(ano);

  //Mostra o dia da semana no display
  lcd.setCursor(17, 3);
  switch (diadasemana)
  {
    case 0: lcd.print("Dom");
      break;
    case 1: lcd.print("Seg");
      break;
    case 2: lcd.print("Ter");
      break;
    case 3: lcd.print("Qua");
      break;
    case 4: lcd.print("Qui");
      break;
    case 5: lcd.print("Sex");
      break;
    case 6: lcd.print("Sab");
  }
}

void DHT11()
{
  sensorDHT11.read11(pinoDHT11);
  Serial.print("Umidade: ");
  lcd.setCursor(20, 0);
  lcd.write(5);
  lcd.setCursor(21, 0);
  lcd.print(sensorDHT11.humidity, 0);
  lcd.print("%");
  Serial.print(sensorDHT11.humidity, 0);
  Serial.println("%");
  Serial.print("Temperatura: ");
  lcd.setCursor(35, 0);
  lcd.write(4);
  lcd.setCursor(36, 0);
  lcd.print(sensorDHT11.temperature, 0);
  lcd.setCursor(38, 0);
  lcd.write(3);
  lcd.print("C");
  Serial.print(sensorDHT11.temperature, 0);
  Serial.println("ºC  ");
  Serial.println("-------------------------------------");
}
