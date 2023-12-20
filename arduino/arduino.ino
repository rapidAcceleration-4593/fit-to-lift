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
  //digitalWrite(magnetA, HIGH);
  //digitalWrite(magnetB, HIGH);

  motorUp();

  delay(1000);

  digitalWrite(magnetA, LOW);
  digitalWrite(magnetB, LOW);

  motorStop();

  motorDown();

  delay(1000);

}

void motorDown() {
  digitalWrite(motorRightEnable, HIGH);
  digitalWrite(motorLeftEnable, HIGH);
  analogWrite(motorRightPWM, 100);
  analogWrite(motorLeftPWM, 0);
}

void motorUp() {
  digitalWrite(motorRightEnable, HIGH);
  digitalWrite(motorLeftEnable, HIGH);
  analogWrite(motorRightPWM, 0);
  analogWrite(motorLeftPWM, 100);
}

void motorStop() {
  digitalWrite(motorRightEnable, LOW);
  digitalWrite(motorLeftEnable, LOW);
}
