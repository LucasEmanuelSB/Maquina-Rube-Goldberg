

#include <Servo.h>

static const int servoPin = 18;
bool ATIVA_MOTOR = false;
const int pushButton = 19;

#define LED_BUILTIN 2

Servo servo1;

void setup() {
    Serial.begin(115200);
    servo1.attach(servoPin);
    pinMode(pushButton, INPUT);
    pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  int push_button_state = digitalRead(pushButton);
  // if condition checks if push button is pressed
  // if pressed LED will turn on otherwise remain off 
  if ( push_button_state == HIGH ){
    digitalWrite(LED_BUILTIN, HIGH);
    delay(1000); 
    for(int posDegrees = 0; posDegrees <= 180; posDegrees++){
      servo1.write(posDegrees);
      Serial.println(posDegrees);
      delay(15);
    }
    digitalWrite(LED_BUILTIN, LOW);
    delay(3000);
  }
}
