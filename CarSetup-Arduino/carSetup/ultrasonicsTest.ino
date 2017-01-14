//@author Group Ella

//importation of the Smartcar library
#include <Smartcar.h>
//definition of the trigger, echo pins for the 2 ultrasonics
#define trigPin1 5
#define echoPin1 6
#define trigPin2 9
#define echoPin2 10

//declarations used for calculating the distances for the 2 ultrasonic sensors
//in order to implement the collision check feature
long duration, distance,BackSensor,FrontSensor;

//declaration of the components of the car
Car car;
Odometer encoderLeft, encoderRight;
Gyroscope gyro;

//variables used for the movement of the car
int frontSpeed = 40;
int backSpeed = -40;
int lDegrees = -70;
int rDegrees = -70;

//declaration of the buzzer's pin
int buzzer = 0;

void setup()
{
Serial.begin (9600);
pinMode(trigPin1, OUTPUT);
pinMode(echoPin1, INPUT);
pinMode(trigPin2, OUTPUT);
pinMode(echoPin2, INPUT);
encoderLeft.attach(2);
encoderRight.attach(3);
gyro.begin();
car.begin(encoderLeft, encoderRight, gyro);
pinMode(buzzer, 0);
}

void loop() {
  
SonarSensor(trigPin1, echoPin1);
FrontSensor = distance;
Serial.print(FrontSensor);
delay(500);
Serial.print('-');

distance = 0;
duration = 0;
SonarSensor(trigPin2, echoPin2);
BackSensor = distance;
Serial.print(BackSensor);
delay(500);
Serial.println(' ');
distance = 0;
duration = 0;
}

void SonarSensor(int trigPin,int echoPin)
{
digitalWrite(trigPin, LOW);
delayMicroseconds(2);
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);
duration = pulseIn(echoPin, HIGH);
distance = (duration/2) / 29.1;
}
