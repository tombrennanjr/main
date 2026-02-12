 // AFMotor R4 with 4 1.2 amp motors
#include "AFMotor_R4.h"

AF_DCMotor motor1(1);  // Create motor on M1
AF_DCMotor motor2(2);  // Create motor on M2
AF_DCMotor motor3(3);  // Create motor on M3
AF_DCMotor motor4(4);  // Create motor on M4

const byte IRpin=2;
volatile bool obstacleDetected = false;

void setup() {
  Serial.begin(9600);   

  pinMode(IRpin,INPUT_PULLUP);
          
  Serial.println("Basic Motor Test!");

  // Set initial speed and release motors
  motor1.setSpeed(200);
  motor1.run(RELEASE);
  motor2.setSpeed(200);
  motor2.run(RELEASE);
  motor3.setSpeed(200);
  motor3.run(RELEASE);
  motor4.setSpeed(200);
  motor4.run(RELEASE);

//IR sensor

  // Attach the interrupt to the pin.
  // digitalPinToInterrupt(interruptPin) gets the correct interrupt number for the pin.
  // The 'FALLING' mode triggers the ISR when the pin goes from HIGH to LOW (common for
  // obstacle sensors when an object is present).
  attachInterrupt(digitalPinToInterrupt(IRpin), obstacleStop, FALLING);


}

void loop() {
  uint8_t i;

if(obstacleDetected){
  Serial.println("Stop Stop Stop");
  obstacleDetected=false;
  delay(15000);
}
  
  Serial.println("Running forward...");
  motor1.run(FORWARD);
  motor2.run(FORWARD);
  motor3.run(FORWARD);
  motor4.run(FORWARD);
  for (i = 0; i < 255; i++) {
    motor1.setSpeed(i);
    motor2.setSpeed(i);
    motor3.setSpeed(i);
    motor4.setSpeed(i);
  
    delay(10);
  }
 
  for (i = 255; i != 0; i--) {
    motor1.setSpeed(i);
    motor2.setSpeed(i);
    motor3.setSpeed(i);
    motor4.setSpeed(i); 
    delay(10);
  }

Serial.println("Braking...");
  motor1.run(BRAKE);
  motor2.run(BRAKE);
  motor3.run(BRAKE);
  motor4.run(BRAKE);
  delay(100);
  
  Serial.println("Releasing...");
  motor1.run(RELEASE);
  motor2.run(RELEASE);
  motor3.run(RELEASE);
  motor4.run(RELEASE);
  delay(100);
 
if(obstacleDetected){
  Serial.println("Stop Stop Stop");
  obstacleDetected=false;
  delay(15000);
}
  Serial.println("Running in circles..."); 
  motor1.run(BACKWARD);
  motor2.run(FORWARD);
  motor3.run(FORWARD);
  motor4.run(BACKWARD);
  for (i = 0; i < 255; i++) {
    motor1.setSpeed(i);
    motor2.setSpeed(i);
    motor3.setSpeed(i);
    motor4.setSpeed(i);
    delay(10);
  }
 
  for (i = 255; i != 0; i--) {
    motor1.setSpeed(i);
    motor2.setSpeed(i);
    motor3.setSpeed(i);
    motor4.setSpeed(i); 
    delay(10);
  }

  Serial.println("Braking...");
  motor1.run(BRAKE);
  motor2.run(BRAKE);
  motor3.run(BRAKE);
  motor4.run(BRAKE);
  delay(100);
  
  Serial.println("Releasing...");
  motor1.run(RELEASE);
  motor2.run(RELEASE);
  motor3.run(RELEASE);
  motor4.run(RELEASE);
  delay(100);
  
  if(obstacleDetected){
  Serial.println("Stop Stop Stop");
  obstacleDetected=false;
  delay(15000);
  }
  Serial.println("Running backward...");
  motor1.run(BACKWARD);
  motor2.run(BACKWARD);
  motor3.run(BACKWARD);
  motor4.run(BACKWARD); 
  
  for (i = 0; i < 255; i++) {
    motor1.setSpeed(i);
    motor2.setSpeed(i);
    motor3.setSpeed(i);
    motor4.setSpeed(i);  
    delay(10);
  }
 
  for (i = 255; i != 0; i--) {
    motor1.setSpeed(i);
    motor2.setSpeed(i);
    motor3.setSpeed(i);
    motor4.setSpeed(i);  
    delay(10);
  }

  Serial.println("Braking...");
  motor1.run(BRAKE);
  motor2.run(BRAKE);
  motor3.run(BRAKE);
  motor4.run(BRAKE);
  delay(100);
  
  Serial.println("Releasing...");
  motor1.run(RELEASE);
  motor2.run(RELEASE);
  motor3.run(RELEASE);
  motor4.run(RELEASE);
  delay(100);
  
  if(obstacleDetected){
  Serial.println("Stop Stop Stop");
  obstacleDetected=false;
  delay(15000);
  }
  Serial.println("Running in circles again...");  
  motor1.run(FORWARD);
  motor2.run(BACKWARD);
  motor3.run(BACKWARD);
  motor4.run(FORWARD);
  for (i = 0; i < 255; i++) {
    motor1.setSpeed(i);
    motor2.setSpeed(i);
    motor3.setSpeed(i);
    motor4.setSpeed(i);
    delay(10);
  }
 
  for (i = 255; i != 0; i--) {
    motor1.setSpeed(i);
    motor2.setSpeed(i);
    motor3.setSpeed(i);
    motor4.setSpeed(i); 
    delay(10);
  }
 
  Serial.println("Braking...");
  motor1.run(BRAKE);
  motor2.run(BRAKE);
  motor3.run(BRAKE);
  motor4.run(BRAKE);
  delay(1000);
  
  Serial.println("Releasing...");
  motor1.run(RELEASE);
  motor2.run(RELEASE);
  motor3.run(RELEASE);
  motor4.run(RELEASE);
  delay(1000);
}

void obstacleStop(void)
{
  obstacleDetected=true;
}
