#include <Servo.h>

#define LED_BUILTIN 2
const int ATIVA_MOTOR = 3700;
const int LDR = 27;
static const int servoPin = 18;
Servo servo1;
void setup()
{
  Serial.begin(115200);
  pinMode(LED_BUILTIN, OUTPUT);
  servo1.attach(servoPin);
}

void loop()
{
  Serial.println(analogRead(LDR));
  if(analogRead(LDR) >= ATIVA_MOTOR){
    digitalWrite(LED_BUILTIN, HIGH);
    for(int posDegrees = 0; posDegrees <= 180; posDegrees++) {
        servo1.write(posDegrees);
        //Serial.println(posDegrees);
        delay(15);
    }
    digitalWrite(LED_BUILTIN, LOW);
  }
}
