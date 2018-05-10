#include <SoftwareSerial.h>

#define rxPin 3
#define txPin 2


SoftwareSerial SerialSoft = SoftwareSerial(rxPin, txPin); // rx, tx

int i;

void setup() {

  pinMode(rxPin, INPUT);
  pinMode(txPin, OUTPUT);
   
  // put your setup code here, to run once:
  Serial.begin(100000, SERIAL_8E2);
  SerialSoft.begin(57600);

  pinMode(13, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:

  unsigned char ch;
#if 1
  if(Serial.available() > 0) {
      ch = Serial.read();
      digitalWrite(13, 1);
      SerialSoft.write(ch);
  } else {
#ifdef DEBUG_NK
    digitalWrite(13, 0);
//    SerialSoft.println(".");
#endif
  }
#else
  for( i = 0; i < 1; i++) {
    SerialSoft.write("abcdefghijklmnopqrstuvwxyz");
  }
  SerialSoft.println("");
#endif
}
