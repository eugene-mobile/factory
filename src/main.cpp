#include <Servo.h>
#include <Arduino.h>

Servo horizontalServo;  // create servo object to control a servo
Servo verticalServo;  // create servo object to control a servo
Servo fingerServo;  // create servo object to control a servo

int pos = 0;    // variable to store the servo position
int pos2 = 0;
int servoDelayMs = 20;
int stepDelayMs = 300;

int horizontalPinNumber = 9;
int horizontalPosRight = 40;
int horizontalPosLeft = 100;

int verticalPinNumber = 8;
int verticalPosLow = 60;
int verticalPosHigh = 100;

int fingerPinNumber = 11;
int fingerPosLow = 40;
int fingerPosHigh = 80;

void setup() {
  //horizontalServo.attach(9);
  //verticalServo.attach(10);
  //fingerServo.attach(11);
}

void loopFinger() {
  fingerServo.attach(11);
  int min = fingerPosLow;
  int max = fingerPosHigh;
  for (pos = min; pos <=max; pos +=1) {
    fingerServo.write(pos);
    delay(servoDelayMs);
  }
  fingerServo.detach();
  delay(stepDelayMs);
  fingerServo.attach(11);
  for (pos = max; pos >=min; pos -=1) {
    fingerServo.write(pos);
    delay(servoDelayMs);
  }
  fingerServo.detach();
  delay(stepDelayMs);
}

void loopVertical() {
  int pin = verticalPinNumber;
  verticalServo.attach(pin);
  int min = verticalPosLow;
  int max = verticalPosHigh;
  for (pos = min; pos <=max; pos +=1) {
    verticalServo.write(pos);
    delay(servoDelayMs);
  }
  verticalServo.detach();
  delay(stepDelayMs);
  verticalServo.attach(pin);
  for (pos = max; pos >=min; pos -=1) {
    verticalServo.write(pos);
    delay(servoDelayMs);
  }
  verticalServo.detach();
  delay(stepDelayMs);
}


void loopHorizontal() {
  int pin = horizontalPinNumber;
  horizontalServo.attach(pin);
  int min = horizontalPosRight;
  int max = horizontalPosLeft;
  for (pos = min; pos <=max; pos +=1) {
    horizontalServo.write(pos);
    delay(servoDelayMs);
  }
  horizontalServo.detach();
  delay(stepDelayMs);
  horizontalServo.attach(pin);
  for (pos = max; pos >=min; pos -=1) {
    horizontalServo.write(pos);
    delay(servoDelayMs);
  }
  horizontalServo.detach();
  delay(stepDelayMs);
  /* 
  for (pos = 40; pos <= 120; pos += 20) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    horizontalServo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(50);                       // waits 15 ms for the servo to reach the position
    for (pos2 = 140; pos2 >=70; pos2 -= 10) {
      //verticalServo.write(pos2);
      delay(50);
    }
    verticalServo.write(100);
    delay(200);
  }
  */
  /*
  for (pos = 180; pos <= 0; pos -= 20) { // goes from 180 degrees to 0 degrees
    horizontalServo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15 ms for the servo to reach the position
  }
  */
}

void loop() {
  loopHorizontal();
  delay(stepDelayMs);
  loopVertical();
  delay(stepDelayMs);
  loopFinger();
  delay(stepDelayMs);
}