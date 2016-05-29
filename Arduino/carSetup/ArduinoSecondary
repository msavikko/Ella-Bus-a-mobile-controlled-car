//author Group Ella
//This Arduino has been used as a secondary board for the "The Magic School Bus" inspired project.
//This board is used in order to display the car's plate number, on the propeller and the 
//alternating lights.


#include <LiquidCrystal.h>
#include <Servo.h>

//declare the components
Servo myServo;
LiquidCrystal lcd(12,11,5,4,3,2);

//declare variables used for the LCD
const int switchPin = 6;
int pos = 0;

//declare variables used by the LEDs
//the right side LEDs
int ledGreenRight = 6;
int ledYellowRight = 1;
int ledBlueRight = 9;
//the left side LEDs
int ledGreenLeft = 7;
int ledYellowLeft = 10;
int ledBlueLeft = 8;

//create the smile on the LCD
byte smile[8] = {
  B00000,
  B10001,
  B00000,
  B00000,
  B10001,
  B01110,
  B00000,
};

//create the hearts on the LCD
byte heart[8] = 
              {
                0b00000,
                0b01010,
                0b11111,
                0b11111,
                0b11111,
                0b01110,
                0b00100,
                0b00000
              };

void setup() {
 //start the LED
 lcd.begin(16,2);
 lcd.createChar(1, heart);
 lcd.createChar(2, smile);
 pinMode (switchPin, INPUT);

 //start the servo
 myServo.attach(A5);

 //initialise LEDs
 pinMode(ledGreenRight, OUTPUT);
 pinMode(ledYellowRight, OUTPUT);
 pinMode(ledBlueRight, OUTPUT);
 pinMode(ledGreenLeft, OUTPUT);
 pinMode(ledYellowLeft, OUTPUT);
 pinMode(ledBlueLeft, OUTPUT);
}

void loop() { 
  //set cursor at position 0,0 on the LCD
  lcd.setCursor(0,0);
  lcd.print("Team ELLA");

  //set cursor at position 0, second row on the LCD
  lcd.setCursor(0, 1);
  //start writing a character with delay
  lcd.write(1);
  myServo.write(0);
  //start the first LED set
  digitalWrite(ledGreenRight, HIGH);
  digitalWrite(ledGreenLeft, HIGH);
  //delay
  delay(500);
  

  //continue changing the LED that will light, the direction of the servo and add a new character to the LCD
  myServo.write(180);
  digitalWrite(ledGreenRight, LOW);
  digitalWrite(ledGreenLeft, LOW);
  digitalWrite(ledYellowRight, HIGH);
  digitalWrite(ledYellowLeft, HIGH);
  lcd.write(2);
  delay(500);
 
  myServo.write(0);
  digitalWrite(ledYellowRight, LOW);
  digitalWrite(ledYellowLeft, LOW);
  digitalWrite(ledBlueRight, HIGH);
  digitalWrite(ledBlueLeft, HIGH);
  lcd.write(1);
  delay(500);
  
  myServo.write(180);
  digitalWrite(ledGreenRight, HIGH);
  digitalWrite(ledGreenLeft, HIGH);
  digitalWrite(ledYellowLeft, HIGH);
  digitalWrite(ledYellowRight, HIGH);
  digitalWrite(ledBlueRight, HIGH);
  digitalWrite(ledBlueLeft, HIGH);
  lcd.write(2);
  delay(500);
  
  myServo.write(0);
  digitalWrite(ledGreenRight, LOW);
  digitalWrite(ledGreenLeft, LOW);
  digitalWrite(ledYellowLeft, LOW);
  digitalWrite(ledYellowRight, LOW);
  digitalWrite(ledBlueRight, LOW);
  digitalWrite(ledBlueLeft, LOW);
  lcd.write(1);
  delay(500);
  
  myServo.write(180);
  digitalWrite(ledGreenRight, HIGH);
  digitalWrite(ledGreenLeft, HIGH);
  lcd.write(2);
  delay(500);
  
  myServo.write(0);
  lcd.write(1);
  digitalWrite(ledGreenRight, LOW);
  digitalWrite(ledGreenLeft, LOW);
  digitalWrite(ledYellowRight, HIGH);
  digitalWrite(ledYellowLeft, HIGH);
  delay(500);
  
  myServo.write(180);
  digitalWrite(ledGreenRight, LOW);
  digitalWrite(ledGreenLeft, LOW);
  digitalWrite(ledYellowRight, HIGH);
  digitalWrite(ledYellowLeft, HIGH);
  lcd.write(2);
  delay(500);
  
  myServo.write(0);  
  digitalWrite(ledYellowRight, LOW);
  digitalWrite(ledYellowLeft, LOW);
  digitalWrite(ledBlueRight, HIGH);
  digitalWrite(ledBlueLeft, HIGH);
  lcd.write(1);
  delay(500);
  
  myServo.write(180);
  digitalWrite(ledGreenRight, HIGH);
  digitalWrite(ledGreenLeft, HIGH);
  digitalWrite(ledYellowLeft, HIGH);
  digitalWrite(ledYellowRight, HIGH);
  digitalWrite(ledBlueRight, HIGH);
  digitalWrite(ledBlueLeft, HIGH);
  lcd.write(2);
  delay(500);
  
  myServo.write(0);
  digitalWrite(ledGreenRight, LOW);
  digitalWrite(ledGreenLeft, LOW);
  digitalWrite(ledYellowLeft, LOW);
  digitalWrite(ledYellowRight, LOW);
  digitalWrite(ledBlueRight, LOW);
  digitalWrite(ledBlueLeft, LOW);
  lcd.write(1);
  delay(500);
  
  myServo.write(180);
  lcd.write(2);
  digitalWrite(ledGreenRight, HIGH);
  digitalWrite(ledGreenLeft, HIGH);
  delay(500);
  
  myServo.write(0);
  lcd.write(1);
  digitalWrite(ledGreenRight, LOW);
  digitalWrite(ledGreenLeft, LOW);
  digitalWrite(ledYellowRight, HIGH);
  digitalWrite(ledYellowLeft, HIGH);
  delay(500);
  
  myServo.write(180);
  digitalWrite(ledGreenRight, LOW);
  digitalWrite(ledGreenLeft, LOW);
  digitalWrite(ledYellowRight, HIGH);
  digitalWrite(ledYellowLeft, HIGH);
  lcd.write(2);
  delay(500);
  
  myServo.write(0);
  digitalWrite(ledYellowRight, LOW);
  digitalWrite(ledYellowLeft, LOW);
  digitalWrite(ledBlueRight, HIGH);
  digitalWrite(ledBlueLeft, HIGH);
  lcd.write(1);
  delay(500);
  
  myServo.write(180);
  digitalWrite(ledGreenRight, HIGH);
  digitalWrite(ledGreenLeft, HIGH);
  digitalWrite(ledYellowLeft, HIGH);
  digitalWrite(ledYellowRight, HIGH);
  digitalWrite(ledBlueRight, HIGH);
  digitalWrite(ledBlueLeft, HIGH);
  delay (500);
  
  myServo.write(0);
  digitalWrite(ledGreenRight, LOW);
  digitalWrite(ledGreenLeft, LOW);
  digitalWrite(ledYellowLeft, LOW);
  digitalWrite(ledYellowRight, LOW);
  digitalWrite(ledBlueRight, LOW);
  digitalWrite(ledBlueLeft, LOW);
  lcd.clear();
  delay(500);
  
  myServo.write(180);
  }
