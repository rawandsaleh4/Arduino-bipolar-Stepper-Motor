
/*
 Stepper Motor Control - speed control

 This program drives a unipolar or bipolar stepper motor.
 The motor is attached to digital pins 8 - 11 of the Arduino.
 A potentiometer is connected to analog input 0.

 The motor will rotate in a clockwise direction. The higher the potentiometer value,
 the faster the motor speed. Because setSpeed() sets the delay between steps,
 you may notice the motor is less responsive to changes in the sensor value at
 low speeds.

 Created 30 Nov. 2009
 Modified 28 Oct 2010
 by Tom Igoe

 */

#include <Stepper.h>

const int stepsPerRevolution = 200;  // change this to fit the number of steps per revolution
// for your motor

int in1=7;
int in2=6;
int in3=5;
int in4=4;
#define pot A0
#define PB 9
int direction_=1;
// initialize the stepper library on pins 4 through 7:
Stepper myStepper(stepsPerRevolution, in1, in2, in3, in4);

int stepCount = 0;  // number of steps the motor has taken

void setup() {
pinMode(in1,OUTPUT);
pinMode(in2,OUTPUT);
pinMode(in3,OUTPUT);
pinMode(in4,OUTPUT);
pinMode(pot,INPUT);
pinMode(PB,INPUT);
}

void loop() {
  // read the sensor value:
  int potReading = analogRead(pot);
  // map it to a range from 0 to 100:
  int motorSpeed = map(potReading, 0, 1023, 5, 100);
  // set the motor speed:
 
    myStepper.setSpeed(motorSpeed);
    if(digitalRead(PB)==0)
    myStepper.step(direction_);
    else
    myStepper.step(-direction_);
  
}


