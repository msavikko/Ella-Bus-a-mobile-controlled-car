//author Group Ella

//Include the neccessary libraries
#include <Smartcar.h>
#include <OneWire.h>
#include <DallasTemperature.h>

//declaring the ultrasonic sensors and the used pins on the board
SR04 ultrasonicSensorFront;
SR04 ultrasonicSensorBack;
const int TRIGGER_PIN = 5; 
const int ECHO_PIN = 6; 
const int TRIGGER_PINb = A5;
const int ECHO_PINb = A4;

//declaring the pin for the buzzer
int buzzer = A3;

//Define the data wire that is plugged into the Arduino board on port A2
#define ONE_WIRE_BUS A2
//Setup a oneWire instance to communicate with any OneWire device
OneWire oneWire(ONE_WIRE_BUS);
//Pass the oneWire reference to the temperature sensor
DallasTemperature tempSens(&oneWire);

//declaring the components
Car car;
Odometer encoderLeft, encoderRight;
Gyroscope gyro;

//declaring the initial speeds and movements of the car
int actualSpeed; //70% of the full speed forward
char side = 'n';

//integers used to calculate the distance for the 2 ultrasonic sensors
int distanceFront;
int distanceBack;

//declare the LEDs
const int pinFrontLeft = A1;
const int pinFrontRight = A9;
const int pinBackRight= A8;
const int pinBackLeft = A7;

void setup() {
  //begin the bluetooth 
  Serial3.begin(9600);

  Serial.begin(9600);
  //initialize the car using the encoders and the gyro
    //attach the components
  gyro.attach();
  encoderLeft.attach(2);
  encoderRight.attach(3);
  ultrasonicSensorFront.attach(TRIGGER_PIN, ECHO_PIN);
  ultrasonicSensorBack.attach(TRIGGER_PINb, ECHO_PINb);

  //start the components
  gyro.begin();
  car.begin(encoderLeft, encoderRight, gyro);
  tempSens.begin();

  //initialise the distances used to 0
  distanceFront = 0;
  distanceBack = 0;

  //initialise buzzer;
  pinMode(buzzer, OUTPUT);

  //initialise the LEDs
  pinMode(pinFrontRight, OUTPUT);
  pinMode(pinFrontLeft, OUTPUT);
  pinMode(pinBackRight, OUTPUT);
  pinMode(pinBackLeft, OUTPUT);
}

void loop() {
 tempSens.requestTemperatures();
 //Serial.println(tempSens.getTempCByIndex(0));                                         //VALUE MUST GO TO ANDROID
 
 distanceFront = ultrasonicSensorFront.getDistance();
 distanceBack = ultrasonicSensorBack.getDistance();

 actualSpeed = car.getSpeed();                                                         //VALUE MUST GO TO ANDROID
 handleInput();
 
  if (actualSpeed == 0){
  side = 'n';
  }
 
 if ( IsClear(distanceFront) == false && side != 'n' && side != 'b'){  
   if (distanceFront > 20 && distanceFront == 0){
     car.setSpeed(actualSpeed);      
   }
   else{
    if (actualSpeed != 0){
     digitalWrite(buzzer, HIGH);
     car.setSpeed(0);
     delay(300);
     digitalWrite(buzzer, LOW);
     delay(100);
     digitalWrite(buzzer, HIGH);
     delay(300);
     digitalWrite(buzzer, LOW);
   }
   else {
    car.setSpeed(0);
   }
   }
 }

 actualSpeed = car.getSpeed();                                                         //VALUE MUST GO TO ANDROID
 if ( IsClear(distanceBack) == false && side =='b'){
   if (distanceBack > 20 && distanceBack == 0){
     car.setSpeed(actualSpeed);
    }
    else{     
      if (actualSpeed != 0){
       digitalWrite(buzzer, HIGH);
       delay(300);
       car.setSpeed(0);
       digitalWrite(buzzer, LOW);
       delay(100);
       digitalWrite(buzzer, HIGH);
       delay(300);
       digitalWrite(buzzer, LOW);
     } 
     else{
      car.setSpeed(0); 
     }
   }
  }   
}

void handleInput() { //handle serial input if there is any

  if (Serial.available()) {
    String empty = Serial.readStringUntil('P');

    String sPower = Serial.readStringUntil('A');
    int power = sPower.toInt();
    actualSpeed = power;
    car.setSpeed(power);

    String sAngle = Serial.readStringUntil('D');
    int angle = sAngle.toInt();
    car.setAngle(angle);
    
    //checks which ultrasonic should be triggered
    if (power < 0){
      side = 'b';
      }
    else side = 'f';   


    digitalWrite(pinBackRight, LOW);
    digitalWrite(pinBackLeft, LOW);
    digitalWrite(pinFrontLeft, LOW);
    digitalWrite(pinFrontRight, LOW);
    
    int speed = car.getSpeed();
    if (speed != 0){  
      if ( angle >= 0){
        digitalWrite(pinFrontRight, HIGH);
        digitalWrite(pinFrontLeft, LOW);
        digitalWrite(pinBackRight, HIGH);
        digitalWrite(pinBackLeft, LOW);
      }
      if ( angle < 0){
        digitalWrite(pinBackRight, LOW);
        digitalWrite(pinBackLeft, HIGH);
        digitalWrite(pinFrontRight, LOW);
        digitalWrite(pinFrontLeft, HIGH);
      }
    }
   }
 }

  boolean IsClear(int distance){
      if (distance > 20){
       return true;
      }
      if (distance == 0){
        return true;
       }
     else{
        return false;
     }
 }
