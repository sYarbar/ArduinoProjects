const int analoglnPin = A0;
int sensorValue = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  
}

void loop() {
  // put your main code here, to run repeatedly:
  sensorValue = analogRead(analoglnPin);
  Serial.print("Analog sensor value = ");
  Serial.println(sensorValue);
  delay(1000);
}
