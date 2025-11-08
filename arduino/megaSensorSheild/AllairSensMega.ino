// Example testing sketch for various DHT humidity/temperature sensors
// Written by ladyada, public domain
#include "DHT.h"
#include <OneWire.h>

int DS18S20_Pin = 4; //DS18S20 Signal pin on digital 4 here

//Temperature chip i/o
OneWire ds(DS18S20_Pin);  // on digital pin 4

#define DHTPIN 3 // for teh dfr0067 DHT11

#define DHTTYPE DHT11   // DHT 11
// Connect pin 1 (on the left) of the sensor to +5V
// Connect pin 2 of the sensor to whatever your DHTPIN is
// Connect pin 4 (on the right) of the sensor to GROUND
// Connect a 10K resistor from pin 2 (data) to pin 1 (power) of the sensor DID NOT DO THIS !!!

#define         MG_PIN                       (A1)     //define which analog input channel you are going to use
#define         BOOL_PIN                     (2)
#define         DC_GAIN                      (8.5)   //define the DC gain of amplifier

/***********************Software Related Macros************************************/
#define         READ_SAMPLE_INTERVAL         (50)    //define how many samples you are going to take in normal operation
#define         READ_SAMPLE_TIMES            (5)     //define the time interval(in milisecond) between each samples in
                                                     //normal operation

/**********************Application Related Macros**********************************/
//These two values differ from sensor to sensor. user should derermine this value.
#define         ZERO_POINT_VOLTAGE           (0.220) //define the output of the sensor in volts when the concentration of CO2 is 400PPM
#define         REACTION_VOLTGAE             (0.030) //define the voltage drop of the sensor when move the sensor from air into 1000ppm CO2

/*****************************Globals***********************************************/
float           CO2Curve[3]  =  {2.602,ZERO_POINT_VOLTAGE,(REACTION_VOLTGAE/(2.602-3))};
                                                     //two points are taken from the curve.
                                                     //with these two points, a line is formed which is
                                                     //"approximately equivalent" to the original curve.
                                                     //data format:{ x, y, slope}; point1: (lg400, 0.324), point2: (lg4000, 0.280)
                                                     //slope = ( reaction voltage ) / (log400 –log1000)


DHT dht(DHTPIN, DHTTYPE);
int iteration_counter=1;

// Sensor pin connections
const int ledPin = 9; // Digital pin for the LED power (e.g., pin 9)
const int dustPin = A0; // Analog pin for the sensor's output (e.g., A0)

// Timing parameters (adjust based on datasheet)
const int samplingTime = 280; // Microseconds to keep the LED on
const int deltaTime = 40; // Microseconds to wait after LED on
const int sleepTime = 9680; // Microseconds to keep the LED off (to make a total of 10ms)

// Variables for calculation
int voMeasured = 0;
float calcVoltage = 0.0;
float dustDensity = 0.0;


void setup() {
  Serial.begin(9600); 
  Serial.println("Multiple sensor test - plug it all in and see what she does...");

   pinMode(ledPin, OUTPUT);
  Serial.println("GP2Y1010AU Dust Sensor");
  
  dht.begin();
    // DFR CO2
  pinMode(BOOL_PIN, INPUT);                        //set pin to input
  digitalWrite(BOOL_PIN, HIGH);                    //turn on pullup resistors

  Serial.print("MG-811 Demostration\n");

}

void loop() {
  // for the DFR CO2
  int percentage;
  float volts;
  
  // Reading temperature or humidity takes about 250 milliseconds!
  // Sensor readings may also be up to 2 seconds 'old' (its a very slow sensor)
  float h = dht.readHumidity();
  float t = dht.readTemperature();
  float temperatureDFR0024 = getTemp();

  Serial.println("*****************************");

  // check if returns are valid, if they are NaN (not a number) then something went wrong!
  if (isnan(t) || isnan(h)) {
    Serial.println("Failed to read from DHT");
  } else {
    Serial.print("      Humidity                      : "); 
    Serial.print(h);
    Serial.println(" %\t");
    Serial.print("      Temperature                   : "); 
    Serial.print(t);
    Serial.println(" *C");
  }
  
  Serial.print("DFR0024 DS1820 temp sensor          : ");
  Serial.println(temperatureDFR0024);
  
  float vol3;
  int sensorValue3 = analogRead(A3);
  vol3=(float)sensorValue3/1024*5.0;
  Serial.print("MQ2 LPG iButPropMethAlcoHydroSmoke  : "); 
  Serial.println(vol3,1);
  // Dont have an mq6 ?
  //    float vol4;
  //int sensorValue4 = analogRead(A4);
  //vol4=(float)sensorValue4/1024*5.0;
  //Serial.print("MQ6           LPG                   : "); 
  //Serial.println(vol4,1);
      float vol5;
  int sensorValue5 = analogRead(A5);
  vol5=(float)sensorValue5/1024*5.0;
  Serial.print("MQ7            CO                   : "); 
  Serial.println(vol5,1);
      float vol6;
  int sensorValue6 = analogRead(A6);
  vol6=(float)sensorValue6/1024*5.0;
  Serial.print("MQ8         Hydrogen                : "); 
  Serial.println(vol6,1);
      float vol7;
  int sensorValue7 = analogRead(A7);
  vol7=(float)sensorValue7/1024*5.0;
  Serial.print("MQ9 CO Methane LPG Combustibles     : "); 
  Serial.println(vol7,1);

// Turn LED on for sampling
  digitalWrite(ledPin, LOW); // Make sure the LED is powered
  delayMicroseconds(samplingTime);

  // Read the analog value from the sensor
  voMeasured = analogRead(dustPin);

  // Wait for the sensor to stabilize
  delayMicroseconds(deltaTime);

  // Turn LED off
  digitalWrite(ledPin, HIGH);
  delayMicroseconds(sleepTime);

  // Calculate the voltage from the ADC value (5.0V reference)
  // The formula is: Voltage = (ADC_Value * 5.0) / 1024.0
  calcVoltage = (float)voMeasured * (5.0 / 1024.0);

  // Calculate dust density using a linear equation from the datasheet
  // Dust Density (ug/m3) = 170 * Voltage - 0.1  (This is an example formula, verify for your specific sensor)
  dustDensity = 170.0 * calcVoltage - 0.1;

  // Prevent negative dust density readings
  if (dustDensity < 0.0) {
    dustDensity = 0.0;
  }

  Serial.print("ADC Value: ");
  Serial.print(voMeasured);
  Serial.print(", Voltage: ");
  Serial.print(calcVoltage);
  Serial.print(", Dust Density (ug/m3): ");
  Serial.println(dustDensity);

  // hitting the DFRCO2 sensor
  volts = MGRead(MG_PIN);
    Serial.print( "SEN0159:" );
    Serial.print(volts);
    Serial.print( "V           " );

    percentage = MGGetPercentage(volts,CO2Curve);
    Serial.print("CO2:");
    if (percentage == -1) {
        Serial.print( "<400" );
    } else {
        Serial.print(percentage);
    }

    Serial.print( "ppm" );
    Serial.print("\n");

    //if (digitalRead(BOOL_PIN) ){
    //    Serial.print( "=====BOOL is HIGH======" );
    //} else {
    //    Serial.print( "=====BOOL is LOW======" );
    //}

    Serial.print("\n");

  Serial.print("*******Loop Counter**********       : ");
  Serial.println(iteration_counter++);
  
  delay(10000); // Wait for X000 seconds before the next reading
  //delay(2000);
}
float getTemp(){
  //returns the temperature from one DS18S20 in DEG Celsius

  byte data[12];
  byte addr[8];

  if ( !ds.search(addr)) {
      //no more sensors on chain, reset search
      ds.reset_search();
      return -1000;
  }

  if ( OneWire::crc8( addr, 7) != addr[7]) {
      Serial.println("CRC is not valid!");
      return -1000;
  }

  if ( addr[0] != 0x10 && addr[0] != 0x28) {
      Serial.print("Device is not recognized");
      return -1000;
  }

  ds.reset();
  ds.select(addr);
  ds.write(0x44,1); // start conversion, with parasite power on at the end

  byte present = ds.reset();
  ds.select(addr);    
  ds.write(0xBE); // Read Scratchpad

  
  for (int i = 0; i < 9; i++) { // we need 9 bytes
    data[i] = ds.read();
  }
  
  ds.reset_search();
  
  byte MSB = data[1];
  byte LSB = data[0];

  float tempRead = ((MSB << 8) | LSB); //using two's compliment
  float TemperatureSum = tempRead / 16;
  
  return TemperatureSum;
  
}

/*****************************  MGRead *********************************************
Input:   mg_pin - analog channel
Output:  output of SEN-000007
Remarks: This function reads the output of SEN-000007
************************************************************************************/
float MGRead(int mg_pin)
{
    int i;
    float v=0;

    for (i=0;i<READ_SAMPLE_TIMES;i++) {
        v += analogRead(mg_pin);
        delay(READ_SAMPLE_INTERVAL);
    }
    v = (v/READ_SAMPLE_TIMES) *5/1024 ;
    return v;
}

/*****************************  MQGetPercentage **********************************
Input:   volts   - SEN-000007 output measured in volts
         pcurve  - pointer to the curve of the target gas
Output:  ppm of the target gas
Remarks: By using the slope and a point of the line. The x(logarithmic value of ppm)
         of the line could be derived if y(MG-811 output) is provided. As it is a
         logarithmic coordinate, power of 10 is used to convert the result to non-logarithmic
         value.
************************************************************************************/
int  MGGetPercentage(float volts, float *pcurve)
{
   if ((volts/DC_GAIN )>=ZERO_POINT_VOLTAGE) {
      return -1;
   } else {
      return pow(10, ((volts/DC_GAIN)-pcurve[1])/pcurve[2]+pcurve[0]);
   }
}
