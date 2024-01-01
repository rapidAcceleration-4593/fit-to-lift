volatile unsigned int temp, counter = 0; //This variable will increase or decrease depending on the rotation of encoder
    
void setup() {
  Serial.begin (9600);

  pinMode(2, INPUT_PULLUP); // internal pullup input pin 2 
  
  pinMode(3, INPUT_PULLUP); // internalเป็น pullup input pin 3
//Setting up interrupt
  //A rising pulse from encodenren activated ai0(). AttachInterrupt 0 is DigitalPin nr 2 on moust Arduino.
  attachInterrupt(0, ai0, RISING);
   
  //B rising pulse from encodenren activated ai1(). AttachInterrupt 1 is DigitalPin nr 3 on moust Arduino.
  attachInterrupt(1, ai1, RISING);
  }
   
  void loop() {
    Serial.println(counter);
  // Send the value of counter
  if( counter != temp ){
  Serial.println (counter);
  temp = counter;
  }
  }
   
  void ai0() {
  // ai0 is activated if DigitalPin nr 2 is going from LOW to HIGH
  // Check pin 3 to determine the direction
  if(digitalRead(3)==HIGH) {
  counter++;
  }else{
  counter--;
  }
  }
   
  void ai1() {
  // ai0 is activated if DigitalPin nr 3 is going from LOW to HIGH
  // Check with pin 2 to determine the direction
  if(digitalRead(2)==HIGH) {
  counter--;
  }else{
  counter++;
  }
  }


// /*     Arduino Rotary Encoder Tutorial
//  *      
//  *  by Dejan Nedelkovski, www.HowToMechatronics.com
//  *  
//  */
 
//  #define outputA 2
//  #define outputB 3

//  int counter = 0; 
//  int aState;
//  int aLastState;  

//  void setup() { 
//    pinMode (outputA,INPUT);
//    pinMode (outputB,INPUT);
   
//    Serial.begin (9600);
//    // Reads the initial state of the outputA
//    aLastState = digitalRead(outputA);   
//  } 

//  void loop() { 
//        Serial.print("Position: ");
//      Serial.println(counter);
//    aState = digitalRead(outputA); // Reads the "current" state of the outputA
//    // If the previous and the current state of the outputA are different, that means a Pulse has occured
//    if (aState != aLastState){     
//      // If the outputB state is different to the outputA state, that means the encoder is rotating clockwise
//      if (digitalRead(outputB) != aState) { 
//        counter ++;
//      } else {
//        counter --;
//      }

//    } 
//    aLastState = aState; // Updates the previous state of the outputA with the current state
//  }