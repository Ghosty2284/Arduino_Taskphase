#define motor1Pin 9  // Replace with the pin connected to motor 1
#define motor2Pin 10 // Replace with the pin connected to motor 2

unsigned long startTime;  // Variable to store the start time
const unsigned long runTime = 5000; // Run time in milliseconds (5 seconds)

void setup() {
  pinMode(motor1Pin, OUTPUT);
  pinMode(motor2Pin, OUTPUT);
  startTime = millis();  // Get the start time when setup is complete
}

void loop() {
  if (millis() - startTime >= runTime) {
    digitalWrite(motor1Pin, LOW);  // Stop motor 1
    digitalWrite(motor2Pin, LOW);  // Stop motor 2
  } else {
    digitalWrite(motor1Pin, HIGH);  // Run motor 1 forward
    digitalWrite(motor2Pin, HIGH);  // Run motor 2 forward
  }
}
