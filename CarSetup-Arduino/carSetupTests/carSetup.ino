#include <Smartcar.h>

Car car;
SR04 ultrasonicSensorFront;
const int TRIGGER_PIN = 6; //D6
const int ECHO_PIN = 5; //D5
SR04 ultrasonicSensorBack;
const int TRIGGER_PIN_BACK = 10; //D10
const int ECHO_PIN_BACK = 9; //D9
int distanceFront, distanceBack;
Odometer encoderLeft, encoderRight;
Gyroscope gyro;
int frontSpeed = 70; //70% of the full speed forward
int backSpeed = -70; //70% of the full speed backward
int lDegrees = -75; //degrees to turn left
int rDegrees = 75; //degrees to turn right


void setup() {
  Serial3.begin(9600);
  gyro.attach();
  encoderLeft.attach(2);
  encoderRight.attach(3);
  gyro.begin();
  Serial.begin(9600);
  car.begin(encoderLeft, encoderRight, gyro); //initialize the car using the encoders and the gyro
  ultrasonicSensorFront.attach(6, 5);
  ultrasonicSensorBack.attach(10, 9);
  distanceFront = 0;
  distanceBack = 0;
}

void loop() {
  handleInput();
}

void handleInput() { //handle serial input if there is any

  if (Serial3.available()) {
    char input = Serial3.read(); //read everything that has been received so far and log down the last entry
    switch (input) {
      case 'l': //rotate counter-clockwise going forward
        car.setSpeed(frontSpeed);
        car.setAngle(lDegrees);
        break;
      case 'r': //turn clock-wise
        car.setSpeed(frontSpeed);
        car.setAngle(rDegrees);
        break;
      case 'f': //go ahead
        car.setSpeed(frontSpeed);
        car.setAngle(0);
        break;
      case 'b': //go back
        car.setSpeed(backSpeed);
        car.setAngle(0);
        break;
      case 's': //if you receive something that you don't know, just stop
        car.setSpeed(0);
        car.setAngle(0);
    }
  }
}

  boolean frontIsClear(){
   distanceFront = ultrasonicSensorFront.getDistance();
    if (distanceFront > 10)
      Serial.println(distanceFront); 
      return true;
    if (distanceFront == 0)
      return true;

    Serial.print(distanceFront);
    return false;
  }

  boolean backIsClear(){
   distanceBack = ultrasonicSensorBack.getDistance();
   if (distanceBack > 10)
      return true;
   if (distanceBack == 0)
      return true;

   return false;
}
