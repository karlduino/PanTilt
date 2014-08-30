/**
 * PanTilt.ino
 * 
 * test out pan/tilt bracket and servos with joystick shield
 **/

#include <Servo.h>

const byte PIN_BUTTON_UP = 4;
const byte PIN_LASER = 8;

const byte PIN_ANALOG_X = 0; /* up = 1023, down = 0, center = 533*/
const byte PIN_ANALOG_Y = 1; /* right = 1023, left = 0, center = 512 */

const byte PIN_UD_SERVO = 9;
const byte PIN_RL_SERVO = 10;
Servo ud_servo, rl_servo;

int updown, rightleft;
const int UD_MIN = 55;
const int UD_MAX = 130;
const int LR_MIN = 25;
const int LR_MAX = 155;

void setup() {
  pinMode(PIN_BUTTON_UP, INPUT);  
  digitalWrite(PIN_BUTTON_UP, HIGH);
  
  pinMode(PIN_LASER, OUTPUT);

  ud_servo.attach(PIN_UD_SERVO);
  rl_servo.attach(PIN_RL_SERVO);

  pinMode(PIN_ANALOG_X, INPUT);
  pinMode(PIN_ANALOG_Y, INPUT);
  
  Serial.begin(9600);
}


void loop() {
  digitalWrite(PIN_LASER, 1 - digitalRead(PIN_BUTTON_UP));

  rightleft = map(analogRead(PIN_ANALOG_X), 0, 1023,
                  LR_MIN, LR_MAX);
  updown    = map(analogRead(PIN_ANALOG_Y), 1023, 0,
                  UD_MIN, UD_MAX);
                  
  Serial.print(rightleft);
  Serial.print("\t");
  Serial.println(updown);

  ud_servo.write(updown);
  rl_servo.write(rightleft);
  delay(10);
}

