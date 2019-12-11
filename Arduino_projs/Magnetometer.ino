/*  Magnetometer sketch
 *  ¢ Filippo Falezza
 *  CC-BY-SA 4.0
 */
int analog0 = A0;
int analog1 = A1;
int aa0 = 0;
double val0 = 0;
float val1 = 0;
double b0 = 0;
void setup() {
  Serial.begin(9600);
}

void loop() {
aa0 = analogRead(analog0);
val0 = (3.300*analogRead(analog0))/688;
b0 = (1-val0)/0.023;
delay(1);
//val0 = analogRead(analog0);
//val1 = analogRead(analog1);
  //Serial.write(45);
  Serial.println(aa0);
  Serial.println(val0,4);
  Serial.println(b0,4);
  //Serial.println(A0);
  delay(500);
}
