#include <SoftwareSerial.h>

#define rxPin 3
#define txPin 2


SoftwareSerial SerialSoft = SoftwareSerial(rxPin, txPin); // rx, tx

int i;

void setup() {

  pinMode(rxPin, INPUT);
  pinMode(txPin, OUTPUT);
   
  // put your setup code here, to run once:
  Serial1.begin(100000, SERIAL_8E2);
  Serial2.begin(115200, SERIAL_8N1);

//  SerialSoft.begin(115200);

  delay(2000);
}

void loop() {
  // put your main code here, to run repeatedly:

  unsigned char ch;

  if(Serial2.available() > 0) {
      ch = Serial2.read();
      Serial1.write(ch);
  } else {

  }
}
