#include <Servo.h>
#include <Servo.h>
Servo ser;
void setup() 
{
  Serial.begin(9600);
  ser.attach(9);
  Serial.println("connecting");
  while(!ser.attached())
  {
    Serial.print(".");
    delay(1000);// put your setup code here, to run once:
  }
  if(ser.attached())
  Serial.println("!connected");
  ser.write(90);
  

}

void loop() {
Serial.println("working");
  
  for(int i=0;i<=90;i++)
  {
    ser.write(i);
    delay(20);
  }
  for(int i = 0;i<=90;i++)
  {
    ser.write(i+90);
    delay(20);
  }
  
  //delay(1000);
  //ser.write();
  //delay(1000);
  // put your main code here, to run repeatedly:
}