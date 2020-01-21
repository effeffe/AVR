/*  Magnetometer sketch
 *  ¢ Filippo Falezza 2018-2020
 *  CC-BY-SA 4.0
 *
 *  Note: Arduino has 10bit resolution, hence 1:1024=x=5000mV
 *  This means that we can resolve up to 4.88mV=5mV
 *  
 *  Please adjust the Vcc and Vsens_1 according to your setup
 *  Here, Vcc=5.0V, and Vsens_1 = 100mV
 *  
 *  Vsens_1 depends on the chip used. Here, a TI DRV5055A1 has been used
 *  
 */
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#define analog0 A7 //Input Pin
#define Vcc 5.000 //Volts
#define Vsens_1 0.100 //Voltage sensitivity 1, ie drv5055
int a_0 = 0;
double val0 = 0;
double b0 = 0;
LiquidCrystal_I2C lcd(0x3F, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);

void setup() {
  lcd.begin(16, 2);
}

void loop() {
a_0 = analogRead(analog0);
val0 = (Vcc*a_0/1024);
b0 = ((val0-2.500)/Vsens_1);
delay(1);
lcd.setCursor(0,0);
lcd.print("A0   V0   B[mT]");
lcd.setCursor(0,1);
lcd.print(analogRead(analog0));
lcd.setCursor(5,1);
lcd.print(val0);
lcd.setCursor(10,1);
lcd.print(b0);
delay(100);
lcd.setCursor(0,1);
lcd.print("                ");
}
