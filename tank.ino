const int In1 = 5;
const int In2 = 6;

int motor1 = 0;

unsigned long previousMillis = 0;
const long interval = 1000;

void setup() {
  pinMode(In1, OUTPUT);
  pinMode(In2, OUTPUT);
}

void loop()
{
  unsigned long currentMillis = millis();
 
  if(currentMillis - previousMillis >= interval) {
    // save the last time you blinked the LED 
    previousMillis = currentMillis;   

    // if the LED is off turn it on and vice-versa:
    switch(motor1) {
      case 0:
        motor1 = 1;
        digitalWrite(In1, HIGH);
        digitalWrite(In2, LOW);
        break;
      case 1:
        motor1 = -1;
        digitalWrite(In1, LOW);
        digitalWrite(In2, HIGH);
        break;
      default:
      case -1:
        motor1 = 0;
        digitalWrite(In1, LOW);
        digitalWrite(In2, LOW);
        break;
      }
  }
}

