#include <Servo.h>
const int servoPin=3;
const int echoPin=4;
const int trigPin=5;
long duration;
int distance;
Servo servo;
void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin (9600);
  servo.attach(servoPin);
  servo.write(0);
}
void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(5);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  duration = pulseIn(echoPin, HIGH);
  distance = duration*(0.034/2);
  Serial.print("Distance: ");
  Serial.print(distance);
  if (distance < 10) {
  servo.write(90);
  Serial.println("Activated");
  delay(2000);
  servo.write(0);
}
  
}
