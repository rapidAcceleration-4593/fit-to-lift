#define enA 7
#define in1 6
#define in2 5

int rotDirection = 0;

void setup() {
  pinMode(enA, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  // Set initial rotation direction
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
}

void loop() {
  int pwmOutput = 1;
  digitalWrite(enA, HIGH); // Send PWM signal to L298N Enable pin
   // Map the potentiometer value from 0 to 255
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
 
}
