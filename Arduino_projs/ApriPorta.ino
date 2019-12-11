/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *                       Apriporta v.1.0Alpha                        *
 *                         by Giulio&Filippo                         *
 *                           04-mar-2014                             *
 *                     released under CC-BY-SA                       *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

// Costanti dei Pin collegati ad Arduino
const byte MOTORE_STEP = 9;
const byte MOTORE_DIR = 10;
const byte ULTRASUONI_TRIG = 11;
const byte ULTRASUONI_ECHO = 12;
const byte BOTTONE = 13;

// Costanti di valori per il programma
const int PASSI_APRIRE = 1024;
const int SOGLIA_ULTRASUONI = 30;
const byte DIREZIONE_APERTURA = ;
enum {APERTA, CHIUSA, APERTURA, CHIUSURA} stato = CHIUSA;

// Variabili globali
byte bottone_temp = LOW;
int passi_attuali = 0;

void setup() {
  // Inizializzazione I/O
  pinMode (MOTORE_STEP, OUTPUT);
  pinMode (MOTORE_DIR, OUTPUT);
  pinMode (ULTRASUONI_TRIG, OUTPUT);
  pinMode (ULTRASUONI_ECHO, INPUT);
  pinMode (BOTTONE, INPUT);
}

void loop() {
  long misura_sensore;
  byte bottone_letto = digitalRead(BOTTONE);
  
  // Macchina a stati
  switch (stato) {
    case APERTURA:
    if (passi_attuali >= PASSI_APRIRE) // Porta aperta
    {
      stato = APERTA;
      break;
    }
    
    // Fa un passo
    digitalWrite(MOTORE_STEP, LOW);  
    digitalWrite(MOTORE_STEP, HIGH);
    delayMicroseconds(500); 
    passi_attuali++;     
    
    // Bottone premuto? Fa chiudere la porta
    if (bottone_temp == LOW && bottone_letto == HIGH) {
      stato = CHIUSURA;
      digitalWrite(MOTORE_DIR, !DIREZIONE_APERTURA); // Inversione direzione
      bottone_temp = bottone_letto;
      break;
    }
    
    break;
    
    
    case APERTA:
    // Bottone premuto? Fa chiudere la porta
    if (bottone_temp == LOW && bottone_letto == HIGH) {
      stato = CHIUSURA;
      bottone_temp = bottone_letto;
      break;
    }
    
    /*
    // Gli ultrasuoni non rilevano nessuno? la porta si può chiudere
    if (leggiUltrasuoni() > SOGLIA_ULTRASUONI) {
      stato = CHIUSURA;
    }
    break;
    */
    
    case CHIUSURA:
    if (passi_attuali <= 0) // Porta chiusa
    {
      stato = CHIUSA;
      break;
    }
    
    // Fa un passo (indietro)
    digitalWrite(MOTORE_STEP, LOW);  
    digitalWrite(MOTORE_STEP, HIGH);
    delayMicroseconds(500); 
    passi_attuali--;     
    
    if (bottone_temp == LOW && bottone_letto == HIGH) {
      stato = APERTURA;
      digitalWrite(MOTORE_DIR, DIREZIONE_APERTURA); // Inversione direzione
      bottone_temp = bottone_letto;
      break;
    }
    
    // Gli ultrasuoni rilevano qualcuno? Si apre la porta
    if (leggiUltrasuoni() <= SOGLIA_ULTRASUONI) {
      stato = APERTURA;
    }
    
    break;
    
    case CHIUSA:
    // Bottone premuto? fa aprire la porta
    if (bottone_temp == LOW && bottone_letto == HIGH) {
      stato = APERTURA;
      bottone_temp = bottone_letto;
      break;
    }
    
    // Gli ultrasuoni vedono qualcuno? Si apre la porta
    if (leggiUltrasuoni() <= SOGLIA_ULTRASUONI) {
      stato = APERTURA;
    }
    break;
  }
  
  if (bottone_temp == HIGH && bottone_letto == LOW)
    bottone_temp = LOW;
  
}

long leggiUltrasuoni() {
  digitalWrite(ULTRASUONI_TRIG, LOW); 
  delayMicroseconds(2);
  digitalWrite(ULTRASUONI_TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(ULTRASUONI_TRIG, LOW);
  return pulseIn(ULTRASUONI_ECHO, HIGH);
  //~ distance = (duration/2) / 29.1;
}
