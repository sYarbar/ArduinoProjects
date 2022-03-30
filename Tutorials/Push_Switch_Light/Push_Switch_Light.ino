//Constants won't change they are here to set pin numbers:
const int buttonPin = 2;
const int ledPin = 13;
//variables will change
int buttonState = 0 ;

void setup() {
  // put your setup code here, to run once:
  //initialize the LED pin as output
  pinMode(ledPin, OUTPUT);
  //initialize the pushbutton pin as an input
  pinMode(buttonPin, INPUT);
  //pinMode(7, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  //read state of the pushbutton value
  buttonState = digitalRead(buttonPin);
  //digitalWrite(7, HIGH);

  //if button is pressed, turn on LED light.
  if (buttonState == HIGH){
    //turn LED on
    digitalWrite(ledPin, HIGH);
  }
  else{
    //turn LED off
    digitalWrite(ledPin, LOW);
  }
}
