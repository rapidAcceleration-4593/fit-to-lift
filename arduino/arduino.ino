// pin connections
int loadCellAnalog = A1;
int motorControllerRightEnable = 7;
int motorControllerLeftEnable = 8;
int motorRPWM = 5;
int motorLPWM = 6; 
int magnetA = 12;
int magnetB = 13;
int encoderA = 3;
int encoderB = 4;

void setup() {
  pinMode(motorControllerRightEnable, OUTPUT);
  pinMode(motorControllerLeftEnable, OUTPUT);
  pinMode(motorRPWM, OUTPUT);
  pinMode(motorLPWM, OUTPUT);
  pinMode(magnetA, OUTPUT);
  pinMode(magnetB, OUTPUT);
  
  // encoder pin modes, in/out?

  digitalWrite(motorControllerRightEnable, LOW);
  digitalWrite(motorControllerLeftEnable, LOW);

  digitalWrite(magnetA, LOW);
  digitalWrite(magnetB, LOW);
}

void loop() {
  digitalWrite(magnetA, HIGH);
  digitalWrite(magnetB, HIGH);

  delay(1000);

  digitalWrite(magnetA, LOW);
  digitalWrite(magnetB, LOW);

  delay(1000);

}
