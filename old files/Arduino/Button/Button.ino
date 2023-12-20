/*
  LimitSwitch

  Turns a motor on if the Limit Switch is pressed, otherwise the motor will turn off.

*/

int limitSwitch = 10;  

void setup() {
  pinMode(limitSwitch, INPUT_PULLUP);
  Serial.begin(9800);
}

void loop() {
  if(digitalRead(limitSwitch) == 1){
    Serial.println("Button Go no brr");
  }
  else{
    Serial.println("Button Go brr");    // turn the motor on (in the opposite direction)
  }
}
