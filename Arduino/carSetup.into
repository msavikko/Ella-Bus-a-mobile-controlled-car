#include <Smartcar.h>

Car car;
SR04 ultrasonicSensorFront;
const int TRIGGER_PINf = 6; //D6
const int ECHO_PINf = 5; //D5
SR04 ultrasonicSensorBack;
const int TRIGGER_PINb = 10; //D10
const int ECHO_PINb = 9; //D9

int frontSpeed = 70; //70% of the full speed forward
int backSpeed = -70; //70% of the full speed backward
int lDegrees = -75; //degrees to turn left
int rDegrees = 75; //degrees to turn right


void setup() {
  Serial3.begin(9600);
  car.begin(); //initialize the car using the encoders and the gyro
  ultrasonicSensorFront.attach(TRIGGER_PINf, ECHO_PINf);
  ultrasonicSensorBack.attach(TRIGGER_PINb, ECHO_PINb);
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
   int distanceFront = ultrasonicSensorFront.getDistance();
    if (distanceFront != 0 && distanceFront < 30){
      car.setSpeed(0);
      return true;
    }
    return false;
  }

  boolean backIsClear(){
   int distanceBack = ultrasonicSensorBack.getDistance();
   if (distanceBack != 0 && distanceBack < 30)
    {
      car.setSpeed(0);
      return true;
    }
   return false;
}
