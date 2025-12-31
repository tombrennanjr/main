// Modified 4 motor code for small autonomous robot on an uno
// l293d wont do more than 1.2 amp permotor so we are small

 // AFMotor R4 Compatible Library - Basic Motor Test
// Hardware Setup: DC Motor connected to M1


#include "AFMotor_R4.h"

AF_DCMotor motor1(1);  // Create motor on M1
AF_DCMotor motor2(2);  // Create motor on M1
AF_DCMotor motor3(3);  // Create motor on M1
AF_DCMotor motor4(4);  // Create motor on M1



void setup() {
  Serial.begin(9600);           
  Serial.println("Basic Motor Test!");

  // Set initial speed and release motor
  motor1.setSpeed(200);
  motor1.run(RELEASE);
  motor2.setSpeed(200);
  motor2.run(RELEASE);
  motor3.setSpeed(200);
  motor3.run(RELEASE);
  motor4.setSpeed(200);
  motor4.run(RELEASE);
}

void loop() {
  uint8_t i;
  
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
  
  Serial.println("Running in circles...");
  
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
