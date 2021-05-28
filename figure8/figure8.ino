                          // right motor
const int dirPin1 = 5;
const int speedPin1 = 6;
                          // left motor
const int dirPin2 = 9;
const int speedPin2 = 10;

volatile int leftEncoderValue = 0;
volatile int rightEncoderValue = 0;

const int clockwiseLeftSpeed = 160; /* PLACEHOLDER */
const int clockwiseRightSpeed = 60; /* PLACEHOLDER */
const int clockwiseLoopDuration = 5000; /* PLACEHOLDER */

const int counterClockwiseLeftSpeed = 60; /* PLACEHOLDER */
const int counterClockwiseRightSpeed = 160; /* PLACEHOLDER */
const int counterClockwiseLoopDuration = 5000; /* PLACEHOLDER */

const int forwardLeftSpeed = 60; /* PLACEHOLDER */
const int forwardRightSpeed = 60; /* PLACEHOLDER */
const int forwardOffset = 10; /* PLACEHOLDER */

const int straightDistance1 = 500; /* PLACEHOLDER */
const int straightDistance2 = 500; /* PLACEHOLDER */

void goStraight(int distance) {
  leftEncoderValue = 0;
  rightEncoderValue = 0;
  digitalWrite(dirPin1, HIGH);
  digitalWrite(dirPin2, HIGH);
  while (leftEncoderValue < distance) {
    if (leftEncoderValue < rightEncoderValue) {
      analogWrite(speedPin1, forwardRightSpeed - forwardOffset);
      analogWrite(speedPin2, forwardLeftSpeed + forwardOffset);
    }
    else if (leftEncoderValue > rightEncoderValue) {
      analogWrite(speedPin1, forwardRightSpeed + forwardOffset);
      analogWrite(speedPin2, forwardLeftSpeed - forwardOffset);
    }
    else {
      analogWrite(speedPin1, forwardRightSpeed);
      analogWrite(speedPin2, forwardLeftSpeed);
    }
  }
}

void setup() {
  // put your setup code here, to run once:
  pinMode(dirPin1, OUTPUT);
  pinMode(speedPin1, OUTPUT);
  pinMode(dirPin2, OUTPUT);
  pinMode(speedPin2, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  
  // clockwise rotation
  
  leftEncoderValue = 0;
  rightEncoderValue = 0;
  
  digitalWrite(dirPin1, HIGH);
  digitalWrite(dirPin2, HIGH);
  
  while (leftEncoderValue < clockwiseLoopDuration) {
    analogWrite(speedPin1, clockwiseRightSpeed);
    analogWrite(speedPin2, clockwiseLeftSpeed);
  }
  
  // go straight
  
  goStraight(straightDistance1);
  
  // counter clockwise rotation
  
  leftEncoderValue = 0;
  rightEncoderValue = 0;
  
  digitalWrite(dirPin1, HIGH);
  digitalWrite(dirPin2, HIGH);
  
  while (rightEncoderValue < counterClockwiseLoopDuration) {
    analogWrite(speedPin1, counterClockwiseRightSpeed);
    analogWrite(speedPin2, counterClockwiseLeftSpeed);
  }
  
  // go straight
  
  goStraight(straightDistance2);
}
