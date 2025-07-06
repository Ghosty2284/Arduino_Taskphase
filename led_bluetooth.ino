#include <SoftwareSerial.h>

SoftwareSerial mySerial(3, 2); // RX, TX
#define ledPin 13

void setup() {
  Serial.begin(9600);
  mySerial.begin(9600); // Set the baud rate for the SoftwareSerial communication
  pinMode(ledPin, OUTPUT);
}

void loop() {
  if (mySerial.available() > 0) {
    char command = mySerial.read();

    // Check the received command
    if (command == '1') {
      digitalWrite(ledPin, HIGH);  // Turn on the LED
      Serial.println("LED is ON");
    } else if (command == '0') {
      digitalWrite(ledPin, LOW);  // Turn off the LED
      Serial.println("LED is OFF");
    }
  }
}