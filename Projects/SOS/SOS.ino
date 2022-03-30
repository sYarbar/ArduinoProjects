/*
 SOS
*/

// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(7, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
  // S (3 dots at 200 on and 300 symbol to symbol delay off)
  digitalWrite(7, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(200);                       
  digitalWrite(7, LOW);    // turn the LED off by making the voltage LOW
  delay(300);
  digitalWrite(7, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(200);                       
  digitalWrite(7, LOW);    // turn the LED off by making the voltage LOW
  delay(300);
  digitalWrite(7, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(200);                       
  digitalWrite(7, LOW);    // turn the LED off by making the voltage LOW

  //Letter to Letter Gap
  delay(1000);


  //O (3 dash 600ms on with 300ms delay symbol to symbol)
  digitalWrite(7, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(600);                       
  digitalWrite(7, LOW);    // turn the LED off by making the voltage LOW
  delay(300);
  digitalWrite(7, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(600);                       
  digitalWrite(7, LOW);    // turn the LED off by making the voltage LOW
  delay(300);
  digitalWrite(7, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(600);                       
  digitalWrite(7, LOW);    // turn the LED off by making the voltage LOW
  delay(300);  
  
 
  //Letter to Letter Gap
  delay(1000);


  //S
  digitalWrite(7, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(200);                       
  digitalWrite(7, LOW);    // turn the LED off by making the voltage LOW
  delay(300);
  digitalWrite(7, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(200);                       
  digitalWrite(7, LOW);    // turn the LED off by making the voltage LOW
  delay(300);
  digitalWrite(7, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(200);                       
  digitalWrite(7, LOW);    // turn the LED off by making the voltage LOW

  //Word gap
  delay(3000);

  
}
