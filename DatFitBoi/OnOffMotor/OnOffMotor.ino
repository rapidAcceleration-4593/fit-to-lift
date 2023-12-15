// Motor A connections
int enA = 9;
int in1 = 8;
int in2 = 7;
// Motor B connections
int enB = 3;
int in3 = 5;
int in4 = 6;
int in11 = 12;
int in12 = 13;
int analogPin = A3;
int analogVal = 0;

void setup() {
  Serial.begin(9600);

	// Set all the motor control pins to outputs
	pinMode(enA, OUTPUT);
	pinMode(enB, OUTPUT);
	pinMode(in1, OUTPUT);
	pinMode(in2, OUTPUT);
	pinMode(in3, OUTPUT);
	pinMode(in4, OUTPUT);
  pinMode(in11, OUTPUT);
  pinMode(in12, OUTPUT);  
  // a = 0;
	
	// Turn off motors - Initial state
	digitalWrite(in1, LOW);
	digitalWrite(in2, LOW);
	digitalWrite(in3, LOW);
	digitalWrite(in4, HIGH);
  digitalWrite(in11, LOW);
  digitalWrite(in12, LOW);
}

void loop() {
	speedControl();

  analogVal = analogRead(analogPin);
  Serial.println(analogVal);
}

// This function lets you control speed of the muturs
void speedControl() {
	// Turn on motors
	digitalWrite(in1, LOW);
	digitalWrite(in2, LOW);
	digitalWrite(in3, LOW);
	digitalWrite(in4, HIGH);
  digitalWrite(in11, HIGH);
  digitalWrite(in12, HIGH);
  delay(2000);


  int i = 255;
  analogWrite(enA, i);
  analogWrite(enB, i);
  digitalWrite(in11, HIGH);
  digitalWrite(in12, HIGH);
  delay(4593);

  // Turn off motors
	digitalWrite(in1, HIGH);
	digitalWrite(in2, HIGH);
	digitalWrite(in3, HIGH);
	digitalWrite(in4, LOW);
  digitalWrite(in11, LOW);
  digitalWrite(in12, LOW);

  
  delay(2100);
  // a = 0;
}