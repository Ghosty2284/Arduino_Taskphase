int IRSensor = 9; // connect IR sensor module to Arduino pin D9
int LED = 13; // connect LED to Arduino pin 13
void setup() {
Serial.begin(9400); // Init Serial at 115200 Baud Rate.
  
  pinMode(IRSensor, INPUT); // IR Sensor pin INPUT
  pinMode(LED, OUTPUT); // LED Pin Output  // put your setup code here, to run once:
}
void loop() {
int sensorStatus = digitalRead(IRSensor); // Set the GPIO as Input
  if (sensorStatus == 1) // Check if the pin high or not
  {
    // if the pin is high turn off the onboard Led
    digitalWrite(LED, HIGH); // LED LOW
    Serial.println("Motion Detected!"); // print Motion Detected! on the serial monitor window
  }
  else  {
    //else turn on the onboard LED
    digitalWrite(LED, LOW); // LED High
    Serial.println("Motion Ended!"); // print Motion Ended! on the serial monitor window
  }
}  

