/* Two motor DC pwm control on an adafruit v3 motor shield
    kill switch added, need to get object sensors and wifi/bte */


int directionPinA = 12;
int pwmPinA = 3;
int brakePinA = 9;

//uncomment if using channel B, and remove above definitions
int directionPinB = 13;
int pwmPinB = 11;
int brakePinB = 8;

//boolean to switch direction
bool directionStateA;
bool directionStateB;

//for the kill switch wired to d4
const int buttonPin = 4;
int buttonState = 0;
int armedState = 0;

void setup() {
Serial.begin(9600);
//define pins
pinMode(buttonPin, INPUT);
  
pinMode(directionPinA, OUTPUT);
pinMode(directionPinB, OUTPUT);
pinMode(pwmPinA, OUTPUT);
pinMode(pwmPinB, OUTPUT);
pinMode(brakePinA, OUTPUT);
pinMode(brakePinB, OUTPUT);

}


void loop() {
// get arm switch status
  Serial.println(digitalRead(buttonPin));
  buttonState = digitalRead(buttonPin);

  // read state and swap if button was pressed, arm or disarm depending...
  if (buttonState ==1){
    if (armedState == 0) {
      armedState =1;
      Serial.println("Armed");
    }
    else if (armedState == 1) {
      armedState=0;
      Serial.println("DisArmed");
      delay(50000); 
    }
  }
  else if (buttonState==LOW) delay(50);

if(armedState==1)
{
//change direction every loop()

directionStateA = !directionStateA;
directionStateB = !directionStateB;

//write a low state to the direction pin (13)
if(directionStateA == false){
  digitalWrite(directionPinA, LOW);
  digitalWrite(directionPinB, LOW);
}
//write a high state to the direction pin (13)
else{
  digitalWrite(directionPinA, HIGH);
  digitalWrite(directionPinB, HIGH);
}

//release brakes
digitalWrite(brakePinA, LOW);
digitalWrite(brakePinB, LOW);

//set work duty for the motors
analogWrite(pwmPinA, 170);
analogWrite(pwmPinB, 170);

//move
delay(60);

//activate brakes
digitalWrite(brakePinA, HIGH);
digitalWrite(brakePinB, HIGH);

//set work duty for the motor to 0 (off)
analogWrite(pwmPinA, 0);
analogWrite(pwmPinB, 0);

delay(20);

// turn in a circle ?
//directionStateA = !directionStateA;
//directionStateB = !directionStateB;
//write a low state to the direction pin (13)
if(directionStateA == false){
  digitalWrite(directionPinA, LOW);
  digitalWrite(directionPinB, HIGH);
}
//write a high state to the direction pin (13)
else{
  digitalWrite(directionPinA, HIGH);
  digitalWrite(directionPinB, LOW);
}

//release brakes
digitalWrite(brakePinA, LOW);
digitalWrite(brakePinB, LOW);

//set work duty for the motors
analogWrite(pwmPinA, 170);
analogWrite(pwmPinB, 170);

//loop time
delay(600);

//activate brakes
digitalWrite(brakePinA, HIGH);
digitalWrite(brakePinB, HIGH);

//set work duty for the motor to 0 (off)
analogWrite(pwmPinA, 0);
analogWrite(pwmPinB, 0);
delay(2000);
}
}
