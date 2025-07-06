#include <SoftwareSerial.h>

const int trigPin = 9;  // Trigger pin for HC-SR04
const int echoPin = 10; // Echo pin for HC-SR04
SoftwareSerial bluetooth(2, 3);  // RX, TX for Bluetooth module

void setup() {
  Serial.begin(9600);
  bluetooth.begin(9600);

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void loop() {
  // Trigger the ultrasonic sensor
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Measure the echo duration
  unsigned long duration = pulseIn(echoPin, HIGH);

  // Calculate distance in centimeters
  int distance = duration * 0.034 / 2;

  // Send distance over Bluetooth
  bluetooth.print("Distance: ");
  bluetooth.print(distance);
  bluetooth.println(" cm");

  delay(1000);  // Adjust delay as needed
}