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


void setup() {

  

//define pins

pinMode(directionPinA, OUTPUT);
pinMode(directionPinB, OUTPUT);
pinMode(pwmPinA, OUTPUT);
pinMode(pwmPinB, OUTPUT);
pinMode(brakePinA, OUTPUT);
pinMode(brakePinB, OUTPUT);

}


void loop() {
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
delay(6000);

//activate brakes
digitalWrite(brakePinA, HIGH);
digitalWrite(brakePinB, HIGH);

//set work duty for the motor to 0 (off)
analogWrite(pwmPinA, 0);
analogWrite(pwmPinB, 0);

delay(2000);

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
delay(6700);

//activate brakes
digitalWrite(brakePinA, HIGH);
digitalWrite(brakePinB, HIGH);

//set work duty for the motor to 0 (off)
analogWrite(pwmPinA, 0);
analogWrite(pwmPinB, 0);
delay(2000);

}
