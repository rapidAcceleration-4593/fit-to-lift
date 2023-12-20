// pin connections
int loadCellAnalog = A1;
int motorRightEnable = 7;
int motorLeftEnable = 8;
int motorRightPWM = 6;
int motorLeftPWM = 5; 
int magnetA = 12;
int magnetB = 13;
int encoderA = 3;
int encoderB = 4;

void setup() {
  pinMode(motorRightEnable, OUTPUT);
  pinMode(motorLeftEnable, OUTPUT);
  pinMode(motorRightPWM, OUTPUT);
  pinMode(motorLeftPWM, OUTPUT);
  pinMode(magnetA, OUTPUT);
  pinMode(magnetB, OUTPUT);
  
  // encoder pin modes, in/out?

  digitalWrite(motorRightEnable, HIGH);
  digitalWrite(motorLeftEnable, HIGH);

  analogWrite(motorLeftPWM, 0);
  analogWrite(motorRightPWM, 0);

  digitalWrite(magnetA, LOW);
  digitalWrite(magnetB, LOW);
}

void loop() {
  motorUp(100);

  delay(1000);

  motorStop();

  delay(1000);

  motorDown(100);

  delay(1000);

  motorStop();

  delay(1000);

}

void motorDown(int speed) {
  analogWrite(motorRightPWM, speed);
  analogWrite(motorLeftPWM, 0);
}

void motorUp(int speed) {
  analogWrite(motorRightPWM, 0);
  analogWrite(motorLeftPWM, speed);
}

void motorStop() {
  analogWrite(motorRightPWM, 0);
  analogWrite(motorLeftPWM, 0);
}
