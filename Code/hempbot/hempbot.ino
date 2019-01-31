#include <MotorDriver.h>


MotorDriver m;
int joyYinput = A0; // Verticale  
int joyXinput = A1; // Orizontale
int MotorSpeed1 = 0;
int MotorSpeed2 = 0;
int joyY = 512;
int joyX = 512;


void setup()
{

}


void loop()
{ 
  joyX = analogRead(joyYinput); 
  joyY = analogRead(joyXinput);
  if (joyY < 460)
  {
    // This is Backward
 
    // Set Motor A backward
 
    m.motor(1,BACKWARD,MotorSpeed1);
 
    // Set Motor B backward
 
    m.motor(2,BACKWARD,MotorSpeed2);
 
    //Determine Motor Speeds
 
    // As we are going backwards we need to reverse readings
 
    joyY = joyY - 460; // This produces a negative number
    joyY = joyY * -1;  // Make the number positive
 
    MotorSpeed1 = map(joyY, 0, 460, 0, 255);
    MotorSpeed2 = map(joyY, 0, 460, 0, 255);
 
  }
  else if (joyY > 564)
  {
    // This is Forward
 
    // Set Motor A forward
 
    m.motor(1,FORWARD,MotorSpeed1);
 
    // Set Motor B forward
 
   m.motor(2,FORWARD,MotorSpeed2);
 
    //Determine Motor Speeds
 
    MotorSpeed1 = map(joyY, 564, 1023, 0, 255);
    MotorSpeed2 = map(joyY, 564, 1023, 0, 255); 
 
  }
  else
  {
    // This is Stopped
 
    MotorSpeed1 = 0;
    MotorSpeed2 = 0; 
 
  }
  
  // Now do the steering
  // The Horizontal position will "weigh" the motor speed
  // Values for each motor
 
  if (joyX < 460)
  {
    // Move Left
 
    // As we are going left we need to reverse readings
 
    joyX = joyX - 460; // This produces a negative number
    joyX = joyX * -1;  // Make the number positive
 
    // Map the number to a value of 255 maximum
 
    joyX = map(joyX, 0, 460, 0, 255);
        
 
    MotorSpeed1 = MotorSpeed1 - joyX;
    MotorSpeed2 = MotorSpeed2 + joyX;
 
    // Don't exceed range of 0-255 for motor speeds
 
    if (MotorSpeed1 < 0)MotorSpeed1 = 0;
    if (MotorSpeed2 > 255)MotorSpeed2 = 255;
 
  }
  else if (joyX > 564)
  {
    // Move Right
 
    // Map the number to a value of 255 maximum
 
    joyX = map(joyX, 564, 1023, 0, 255);
        
 
    MotorSpeed1 = MotorSpeed1 + joyX;
    MotorSpeed2 = MotorSpeed2 - joyX;
 
    // Don't exceed range of 0-255 for motor speeds
 
    if (MotorSpeed1 > 255)MotorSpeed1 = 255;
    if (MotorSpeed2 < 0)MotorSpeed2 = 0;      
 
  }
 
 
  // Adjust to prevent "buzzing" at very low speed
 
  if (MotorSpeed1 < 8)MotorSpeed1 = 0;
  if (MotorSpeed2 < 8)MotorSpeed2 = 0;
 
  // Set the motor speeds
 
  analogWrite(11, MotorSpeed1);
  analogWrite(3, MotorSpeed2); 
  

}
