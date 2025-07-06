#include <SoftwareSerial.h>
#include <Servo.h>

Servo myServo; // Create a Servo Object
SoftwareSerial mySerial(3, 2); // RX, TX

void setup() {
  Serial.begin(9600); // Start serial communication
  mySerial.begin(9600); // Set the baud rate for the SoftwareSerial communication
  myServo.attach(9); // Attach Servo to pin 9
}

void loop() {
  if (mySerial.available() > 0) {
    char command = mySerial.read(); // Read the command from Bluetooth Module
    if (command == '1') {
      myServo.write(0); // Rotate the servo to 0 degrees
    } else if (command == '2') {
      myServo.write(90); // Rotate the servo by 90 degrees
    } else if (command == '3') {
      myServo.write(180); // Rotate the servo to 180 degrees
    }
  }
}
