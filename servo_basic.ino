#include <SoftwareSerial.h>
#include <Servo.h>

Servo myServo; // Create a Servo Object


void setup() {
  Serial.begin(9600); // Start serial communication
  myServo.attach(9); // Attach Servo to pin 9
}

void loop() {
 
      myServo.write(0);
      delay(200);
      myServo.write(180); 
      delay(100);
       
}