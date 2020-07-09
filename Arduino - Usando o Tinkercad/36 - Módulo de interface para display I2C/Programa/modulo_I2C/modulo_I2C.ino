#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() 
{
  lcd.begin(16,2);
  lcd.backlight();
}

void loop() 
{
  lcd.home();
  lcd.print("IVONEIDE DUARTE");
  lcd.setCursor(0,1);
  lcd.print("Curso de Arduino");
  delay(1000);
  lcd.clear();
  delay(1000);

}
