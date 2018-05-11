/* 
  IR Breakbeam sensor demo!
*/
 
#define LEDPIN 13
  // Pin 13: Arduino has an LED connected on pin 13
  // Pin 11: Teensy 2.0 has the LED on pin 11
  // Pin  6: Teensy++ 2.0 has the LED on pin 6
  // Pin 13: Teensy 3.0 has the LED on pin 13
 
#define SENSORPIN1 4
#define SENSORPIN2 5
 
// variables will change:
int sensorState1 = 0, lastState1 = 0;         // variable for reading the pushbutton status
int sensorState2 = 0, lastState2 = 0;
 
void setup() {
  // initialize the LED pin as an output:
  pinMode(LEDPIN, OUTPUT);      
  // initialize the sensor pin as an input:
  pinMode(SENSORPIN1, INPUT);     
  digitalWrite(SENSORPIN1, HIGH);
  pinMode(SENSORPIN2, INPUT);     
  digitalWrite(SENSORPIN2, HIGH); // turn on the pullup
  
  Serial.begin(9600);
}
 
void loop(){
  // read the state of the pushbutton value:
  sensorState1 = digitalRead(SENSORPIN1);
  sensorState2 = digitalRead(SENSORPIN2);
 
  // check if the sensor beam is broken
  // if it is, the sensorState is LOW:
  if (sensorState1 == LOW) {     
    // turn LED on:
    digitalWrite(LEDPIN, HIGH);  
  } 
  else {
    // turn LED off:
    digitalWrite(LEDPIN, LOW); 
  }
  
  if (sensorState1 && !lastState1) {
    Serial.println("1 Unbroken");
  } 
  if (!sensorState1 && lastState1) {
    Serial.println("1 Broken");
  }
  lastState1 = sensorState1;

  if (sensorState2 == LOW) {     
    // turn LED on:
    digitalWrite(LEDPIN, HIGH);  
  } 
  else {
    // turn LED off:
    digitalWrite(LEDPIN, LOW); 
  }
  
  if (sensorState2 && !lastState2) {
    Serial.println("2 Unbroken");
  } 
  if (!sensorState2 && lastState2) {
    Serial.println("2 Broken");
  }
  lastState2 = sensorState2;
}
