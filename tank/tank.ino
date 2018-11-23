#include <SoftwareSerial.h>

const int In1 = 5;
const int In2 = 6;
const int In3 = 3;
const int In4 = 11;

const int RX_PIN = 10;
const int TX_PIN = 9;

void turn_motor(int pin);

SoftwareSerial bluetooth(RX_PIN, TX_PIN);

void setup() {
  pinMode(In1, OUTPUT);
  pinMode(In2, OUTPUT);
  pinMode(In3, OUTPUT);
  pinMode(In4, OUTPUT);

  Serial.begin(38400);
  bluetooth.begin(9600);

  // https://arduino.stackexchange.com/a/47022
}

void loop() {
  if (bluetooth.available()) {
    Serial.write(bluetooth.read());
  }
  if (Serial.available()) {
    bluetooth.write(Serial.read());
  }
}

void turn_motor(int pin, int InA, int InB, int do_this_thing) {
  switch(do_this_thing) {
  case 0:
    digitalWrite(InA, HIGH);
    digitalWrite(InB, LOW);
    break;
  case 1:
    digitalWrite(InA, LOW);
    digitalWrite(InB, HIGH);
    break;
  default:
  case -1:
    digitalWrite(InA, LOW);
    digitalWrite(InB, LOW);
    break;
  }
  //return do_this_thing;
}


