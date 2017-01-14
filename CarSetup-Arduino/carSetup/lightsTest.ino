//declare variables used by the LEDs
//the right side LEDs
int ledGreenRight = 6;
int ledYellowRight = 1;
int ledBlueRight = 9;
//the left side LEDs
int ledGreenLeft = 7;
int ledYellowLeft = 10;
int ledBlueLeft = 8;



void setup() {
 pinMode(ledGreenRight, OUTPUT);
 pinMode(ledYellowRight, OUTPUT);
 pinMode(ledBlueRight, OUTPUT);
 pinMode(ledGreenLeft, OUTPUT);
 pinMode(ledYellowLeft, OUTPUT);
 pinMode(ledBlueLeft, OUTPUT);
}

void loop() {
  digitalWrite(ledGreenRight, HIGH);
  digitalWrite(ledGreenLeft, HIGH);
  digitalWrite(ledYellowLeft, HIGH);
  digitalWrite(ledYellowRight, HIGH);
  digitalWrite(ledBlueRight, HIGH);
  digitalWrite(ledBlueLeft, HIGH);
  // put your main code here, to run repeatedly:

}
