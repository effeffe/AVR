#include <Button.h>
const int ledR =7;
const int ledL = 8;
Button bR = Button (11,LOW);
Button bL = Button (12,LOW);
int bRstate = 0;
int bLstate = 0;
void setup(){
  pinMode(ledR, OUTPUT);
  pinMode(ledL, OUTPUT);
  pinMode(11, INPUT);
  pinMode(12, INPUT);
}
void loop(){  
RIGHT();
LEFT();
}
void RIGHT(){
  bRstate = digitalRead(11);
  if (bRstate == HIGH) {
  digitalWrite(ledR, HIGH);
  delay(333);
  digitalWrite(ledR, LOW);
  delay(333);
 }
  else {
  digitalWrite(7, LOW);
  delay(300);
  }
}
void LEFT(){
  bLstate = digitalRead(12);
  if(bLstate = HIGH) {
  digitalWrite(ledL, HIGH);
  delay(333);
  digitalWrite(ledL, LOW);
  delay(333);
  }
  else {
  digitalWrite(8, LOW);
  delay(300);
  }
}
