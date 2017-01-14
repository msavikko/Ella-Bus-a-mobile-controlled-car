//declare the LEDs
const int pinFrontLeft = A1;
const int pinFrontRight = A0;
const int pinBackRight= A8;
const int pinBackLeft = A7;


void setup() {

  //initialise the LEDs
  pinMode(pinFrontRight, OUTPUT);
  pinMode(pinFrontLeft, OUTPUT);
  pinMode(pinBackRight, OUTPUT);
  pinMode(pinBackLeft, OUTPUT);
}

void loop() {

  digitalWrite(pinFrontRight, HIGH);
  digitalWrite(pinBackRight, HIGH);
  digitalWrite(pinBackLeft, HIGH);
  digitalWrite(pinFrontLeft, HIGH);
}
