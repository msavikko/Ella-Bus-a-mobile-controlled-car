const int buzzer = A3;

void setup() {
  pinMode(buzzer, OUTPUT);
  // put your setup code here, to run once:

}

void loop() {

  digitalWrite(buzzer, HIGH);
  delay(500);
  digitalWrite(buzzer, LOW);
  delay(100);
  digitalWrite(buzzer, HIGH);
  // put your main code here, to run repeatedly:

}
