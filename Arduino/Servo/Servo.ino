#include <Servo.h>

Servo servo_3;
void setup()
{
  //pinMode(A0, INPUT);
  servo_3.attach(3,1000, 2500);
}

void loop()
{
   
  for(int i = 0; i<=180;++i){
    servo_3.write(i);
    delay(20); // Delay a little bit to improve simulation performance
  }
  delay(100); // Delay a little bit to improve simulation performance
  for(int i = 180; i>=0;--i){
    servo_3.write(i);  
    delay(20); // Delay a little bit to improve simulation performance
  } 
   
}
