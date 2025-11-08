
#include <Wire.h>
#include <L3G.h>
#include <SoftwareSerial.h>

SoftwareSerial mySerial(0,1);
L3G gyro;

int xsend=0;
int ysend=0;
int zsend=0;

void setup() {
  Serial.begin(9600);
  
   mySerial.begin(9600);
   
   
  Wire.begin();

  if (!gyro.init())
  {
    Serial.println("Failed to autodetect gyro type!");
    while (1);
  }

  gyro.enableDefault();
}

void loop() {
  gyro.read();

  xsend=(int)gyro.g.x;
  ysend=(int)gyro.g.y;
  zsend=(int)gyro.g.z;

  Serial.print("G ");
  Serial.print("X: ");
  Serial.print(xsend);
  Serial.print(" Y: ");
  Serial.print(ysend);
  Serial.print(" Z: ");
  Serial.println(zsend);
  //Serial.println('X');
  //Serial.println('Y');
  //Serial.println('Z');

  delay(100);

  //Serial.println(mySerial.available());
  
  mySerial.print('X');
  delay(500);
  mySerial.print('Y');
  delay(500);
  mySerial.print('Z');
  delay(500);
}
