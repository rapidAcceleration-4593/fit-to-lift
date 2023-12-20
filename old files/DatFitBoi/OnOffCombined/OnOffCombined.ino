// Motor A connections
int enA = 9;
int in1 = 8;
int in2 = 7;
// Motor B connections
int enB = 4;
int in3 = 6;
int in4 = 5;
//loop variables
int a;
//pin defs
#define MAG_PIN 11
//Button Pin variable
const int buttonPin = 10;
int buttonState = 0;

void setup() {
  Serial.begin(9600);
  pinMode(MAG_PIN, OUTPUT);

	// Set all the motor control pins to outputs
	pinMode(enA, OUTPUT);
	pinMode(enB, OUTPUT);
	pinMode(in1, OUTPUT);
	pinMode(in2, OUTPUT);
	pinMode(in3, OUTPUT);
	pinMode(in4, OUTPUT);
  a = 0;
	
	// Turn off motors - Initial state
	digitalWrite(in1, LOW);
	digitalWrite(in2, LOW);
	digitalWrite(in3, LOW);
	digitalWrite(in4, LOW);

  // initialize the pushbutton pin as an input:
  pinMode(buttonPin, INPUT);
}

void loop() {
  // read the state of the pushbutton value:
  
	speedControl();
  digitalWrite(MAG_PIN, LOW);//turns pin on (confusingly)
  delay(9000);//delays
  digitalWrite(MAG_PIN, HIGH);//turns pin on (also confusingly)
  delay(1000);// delays
}

// This function runs the mutur
void speedControl() {
	// Turn on motors
	digitalWrite(in1, LOW);
	digitalWrite(in2, HIGH);
	digitalWrite(in3, LOW);
	digitalWrite(in4, HIGH);
	
	// make motor go brrrrrrrrrrrrrrrrrrrrrrrrrr
	while (a == 0) {
    int i = 255;//makes it go max speed
		analogWrite(enA, i);//bro idk
		analogWrite(enB, i);//same here
		delay(4593); //runs for 4.593 secs
    a = 1;// exits
	}

  // Turn off motors
	digitalWrite(in1, LOW);
	digitalWrite(in2, LOW);
	digitalWrite(in3, LOW);
	digitalWrite(in4, LOW);
  a = 0;//reset loop
}