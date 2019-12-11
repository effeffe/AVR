#include <LiquidCrystal.h>
int  Analog = 0;
float volt = 0;
float a = 0;
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() { 
  lcd.begin(16, 2);
}

void loop(){
  lcd.clear();
  Analog = analogRead(5);
  volt = ((Analog*4.610)/1024.00);
  a = ((volt-0.500)*100)+8.00;
  lcd.setCursor(0,0);
  lcd.print("Ana mV   *C");
  lcd.setCursor(0, 1);
  lcd.print(Analog);
  lcd.setCursor(4,1);
  lcd.print(volt);
  lcd.setCursor(9,1);
  lcd.print(a);
  delay (2000);
}
