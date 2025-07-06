// Define ultrasonic sensor pins
#define trigPin 11
#define echoPin 10

// Define motor driver (L293D) pins
#define EnA 5
#define EnB 3

// Set the maximum and minimum distances for motor control
#define maxDistance 20 // in centimeters


void setup() {
  // Define ultrasonic sensor pins as input/output
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  // Define motor driver pins as output
  pinMode(EnA, OUTPUT);
  pinMode(EnB, OUTPUT);

  // Initialize serial communication
  Serial.begin(9600);
}

void loop() {
  // Measure the distance using the ultrasonic sensor
  long duration, distance;
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration / 2) / 29.1;

  // Print the distance to the serial monitor
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  // Control the motor based on distance
  if (distance > maxDistance) {
    // Move the motor forward
    digitalWrite(EnA, HIGH);
    digitalWrite(EnB, LOW);
  } else if (distance < maxDistance) {
    // Move the motors stop
    digitalWrite(EnA, LOW);
    digitalWrite(EnB, LOW);
  } 

  // Wait for a moment before the next measurement
  delay(1000);
}
