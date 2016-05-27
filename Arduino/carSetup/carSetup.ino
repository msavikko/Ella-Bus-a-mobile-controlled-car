#include <Smartcar.h>

Car car;
SR04 ultrasonicSensorFront;
const int TRIGGER_PIN = 6; //D6
const int ECHO_PIN = 5; //D5
int distanceFront;
Odometer encoderLeft, encoderRight;
Gyroscope gyro;
int frontSpeed = 40; //70% of the full speed forward
int backSpeed = -40; //70% of the full speed backward
int lDegrees = -75; //degrees to turn left
int rDegrees = 75; //degrees to turn right
boolean side = false;

int buzzer = 8;


void setup() {
  Serial3.begin(9600);
  gyro.attach();
  encoderLeft.attach(2);
  encoderRight.attach(3);
  gyro.begin();
  Serial.begin(9600);
  car.begin(encoderLeft, encoderRight, gyro); //initialize the car using the encoders and the gyro
  ultrasonicSensorFront.attach(TRIGGER_PIN, ECHO_PIN);
  distanceFront = 0;
  pinMode(buzzer, 0);
}

void loop() {
  distanceFront = ultrasonicSensorFront.getDistance();
  handleInput();
  if ( frontIsClear() == false  && side == true){  
        if (distanceFront > 15 && distanceFront == 0){
           car.setSpeed(frontSpeed);      
        }
        else{
           pinMode(buzzer, OUTPUT);
           car.setSpeed(frontSpeed - 20);
           delay(500);
           pinMode(buzzer, 0);
           car.setSpeed(frontSpeed - 40);          
           digitalWrite(buzzer, LOW);
           delay(100);
           pinMode(buzzer, OUTPUT);
           delay(500);
           car.setSpeed(0);
           pinMode(buzzer, 0);
           side = false;    
        }
    }; 
}

void handleInput() { //handle serial input if there is any

  if (Serial3.available()) {
    char input = Serial3.read(); //read everything that has been received so far and log down the last entry
    switch (input) {
      case 'l': //rotate counter-clockwise going forward
        Serial.print('l');
        car.setSpeed(frontSpeed);
        car.setAngle(lDegrees);        break;
      case 'r': //turn clock-wise
         Serial.print('r');
         car.setSpeed(frontSpeed);
         car.setAngle(rDegrees);
         break;
      case 'f': //go ahead
        Serial.print('f');
        side = true;
        car.setAngle(0); 
        car.setSpeed(frontSpeed);
        break;
      case 'b': //go back
        Serial.print('b');
        side = false;
        car.setSpeed(backSpeed);
        car.setAngle(0);
        break;
      case 's': //if you receive something that you don't know, just stop
        Serial.print('s');
        car.setSpeed(0);
        car.setAngle(0);
    }
  }
}

  boolean frontIsClear(){
   distanceFront = ultrasonicSensorFront.getDistance();
    if (distanceFront > 10){
      Serial.print(distanceFront); 
      return true;
      }
     if (distanceFront == 0){
      return true;
     }
     else{
        return false;
  }
  }
