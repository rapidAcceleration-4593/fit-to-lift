// pin connections
int loadCellAnalog = A5;
int motorRightEnable = 7;
int motorLeftEnable = 8;
int motorRightPWM = 6;
int motorLeftPWM = 5; 
int magnetA = 12;
int magnetB = 13;
int encoderA = 2;
int encoderB = 3;

bool magnetEngaged = false;
int analogVal = 0;

void setup() {
  Serial.begin(9600);
  Serial.setTimeout(1);

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

  magnetDisengage();
}

void loop() {
  while (!Serial.available()) {
    // analogVal = analogRead(loadCellAnalog);
    // Serial.println(analogVal);
  }
  String command = Serial.readString();
  
  if (command == "u") {
    motorUp(100);
    delay(500);
    motorStop();
  } else if (command == "d") {
    motorDown(100);
    delay(500);
    motorStop();
  } else if (command == "e") {
    magnetEngage();
  } else if (command == "r") {
    magnetDisengage();
  }
}

void motorDown(int speed) {
  if (!magnetEngaged) 
  {
  analogWrite(motorRightPWM, speed);
  analogWrite(motorLeftPWM, 0);
  }
}

void motorUp(int speed) {
  if (!magnetEngaged)
  {
  analogWrite(motorRightPWM, 0);
  analogWrite(motorLeftPWM, speed);
  }
}

void motorStop() {
  analogWrite(motorRightPWM, 0);
  analogWrite(motorLeftPWM, 0);
}

void magnetEngage() {
  digitalWrite(magnetA, HIGH);
  digitalWrite(magnetB, HIGH);

  magnetEngaged = true;
}

void magnetDisengage() {
  digitalWrite(magnetA, LOW);
  digitalWrite(magnetB, LOW);

  magnetEngaged = false;
}
