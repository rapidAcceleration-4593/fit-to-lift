// Motor A connections
int enA = 9;
int in1 = 8;
int in2 = 7;
// Motor B connections
int enB = 4;
int in3 = 5;
int in4 = 6;
//loop variables
int a;

volatile unsigned int temp, counter = 0;

int limitSwitch = 10; 

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

  pinMode(2, INPUT_PULLUP); // internal pullup input pin 2 
  
  pinMode(3, INPUT_PULLUP); // internalเป็น pullup input pin 3
//Setting up interrupt
  //A rising pulse from encodenren activated ai0(). AttachInterrupt 0 is DigitalPin nr 2 on moust Arduino.
  attachInterrupt(0, ai0, RISING);
   
  //B rising pulse from encodenren activated ai1(). AttachInterrupt 1 is DigitalPin nr 3 on moust Arduino.
  attachInterrupt(1, ai1, RISING);

  pinMode(limitSwitch, INPUT_PULLUP);
}

void loop() {
  // read the state of the pushbutton value:
  
	speedControl();
  digitalWrite(MAG_PIN, LOW);//turns pin on (confusingly)
  delay(9000);//delays
  digitalWrite(MAG_PIN, HIGH);//turns pin on (also confusingly)
  delay(1000);// delays
  // Send the value of counter
  if( counter != temp ){
  Serial.println (counter);
  temp = counter;
  }

  if(digitalRead(limitSwitch) == 1){
    Serial.println("Button Go no brr");
  }
  else{
    Serial.println("Button Go brr");    // turn the motor on (in the opposite direction)
  }
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

  void ai0() {
  // ai0 is activated if DigitalPin nr 2 is going from LOW to HIGH
  // Check pin 3 to determine the direction
  if(digitalRead(3)==LOW) {
  counter++;
  }else{
  counter--;
  }
  }
   
  void ai1() {
  // ai0 is activated if DigitalPin nr 3 is going from LOW to HIGH
  // Check with pin 2 to determine the direction
  if(digitalRead(2)==LOW) {
  counter--;
  }else{
  counter++;
  }
  }