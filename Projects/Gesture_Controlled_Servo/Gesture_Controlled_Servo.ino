/*
-------------------------------------------------------------------------------
Gesture_Controlled_Servo
The hardware for this code is a photoresistor connected to a0 and 
a servo attached to pin 9. 

The light sensor data should change in response to someone's hand approaching
the sensor. The motor will rotate between 0 and 180 degrees, based on how 
close the hand is.
-------------------------------------------------------------------------------
*/

#include <Servo.h>
Servo myservo;
int pos = 0; 
const int analoglnPin = A0; //Make a name for A0
int sensorValue = 0; 
int newPos = 0; //used for desired position using sensor data


void setup() {
  // put your setup code here, to run once:
  myservo.attach(9);//sets servo to pin 9
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
   sensorValue = analogRead(analoglnPin);
   newPos = (sensorValue - 30)/110 * 180; //Max read is 140, lowest is 130. subtract 30 and take as fraction of 180 degrees.
                                          //Converts sensor data to a 180 degree scale
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
