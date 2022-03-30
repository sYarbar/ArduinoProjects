const int pingPin = 7; // Trigger Pin of Ultrasonic Sensor
const int echoPin = 6; // Echo Pin of Ultrasonic Sensor
const int ledPin = 9;
#include <LiquidCrystal.h>
LiquidCrystal lcd(12,11,5,4,3,2);
// Connect Ultrasonic sensor VCC to 5 V, and Gnd to 0 V
int duration;
void setup() {
  lcd.begin(16, 2);
  lcd.print("Initializing...");
  pinMode(ledPin, OUTPUT);
 Serial.begin(9600); // Starting Serial Terminal
}
void loop() {
// Ultrasound sensor ping
 pinMode(pingPin, OUTPUT);
 digitalWrite(pingPin, LOW);
 delayMicroseconds(2);
 digitalWrite(pingPin, HIGH);
 delayMicroseconds(10);
 digitalWrite(pingPin, LOW);
// Ultrasound sensor echo catch
 pinMode(echoPin, INPUT);
 duration = pulseIn(echoPin, HIGH)/56; // dividing by 56 converts roughly to centimeters
// Send raw data to Serial port
 Serial.println(duration);
  lcd.print("Distance: ");
  lcd.print((int)duration);
  lcd.print("cm");

  if((int) duration < 20){
    digitalWrite(ledPin, HIGH);
  }
  else{
    digitalWrite(ledPin, LOW);
  }
// Wait before next ping
 delay(100);
}
