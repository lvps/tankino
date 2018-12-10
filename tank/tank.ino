#include <SoftwareSerial.h>

const int In1 = 5;
const int In2 = 6;
const int In3 = 3;
const int In4 = 11;

const int RX_PIN = 9;
const int TX_PIN = 8;

SoftwareSerial bluetooth(RX_PIN, TX_PIN);

void forward() {
  digitalWrite(In1, LOW);
  digitalWrite(In2, HIGH);
  digitalWrite(In3, LOW);
  digitalWrite(In4, HIGH);
}

void backward() {
  digitalWrite(In4, LOW);
  digitalWrite(In3, HIGH);
  digitalWrite(In2, LOW);
  digitalWrite(In1, HIGH);
}

void stop() {
  digitalWrite(In1, LOW);
  digitalWrite(In2, LOW);
  digitalWrite(In3, LOW);
  digitalWrite(In4, LOW);
}

void setup() {
  pinMode(In1, OUTPUT);
  pinMode(In2, OUTPUT);
  pinMode(In3, OUTPUT);
  pinMode(In4, OUTPUT);

  Serial.begin(9600);
  
  // https://arduino.stackexchange.com/a/47022
  bluetooth.begin(9600);
  // Serial.write("AT+BAUD4"); // Do not change baud rate. EVER.
  delay(1000);
  bluetooth.print("AT+NAMETankino");
  delay(1000);
  bluetooth.print("AT+PIN1337");
}

void loop() {
  if (bluetooth.available()) {
    Serial.write(bluetooth.read());
  }
  if (Serial.available()) {
    bluetooth.write(Serial.read());
  }
}

