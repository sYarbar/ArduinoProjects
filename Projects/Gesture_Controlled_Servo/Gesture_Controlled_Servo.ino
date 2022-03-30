#include <Servo.h>
Servo myservo;//creates servo obj
int pos = 0; // initiate servo position
const int analoglnPin = A0; //Make a name for A0
int sensorValue = 0; //initiate sensor value 
int newPos = 0; //used for desired position using sensor data


void setup() {
  // put your setup code here, to run once:
  myservo.attach(9);//sets servo to pin 9
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
   sensorValue = analogRead(analoglnPin);
   newPos = (sensorValue - 30)/110 * 180; //Max read is 140, lowest is 130. subtract 30 and take as fraction of 180 degrees
   Serial.println(newPos);

  //moves servo towards desired position incrementally
   while(pos<newPos){
    pos++;
    myservo.write(pos);
    delay(5);
   }
   while(pos>newPos){
    pos--;
    myservo.write(pos);
    delay(5);
   } 
}
