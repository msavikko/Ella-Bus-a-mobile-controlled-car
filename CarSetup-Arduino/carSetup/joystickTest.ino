void setup() {
  Serial.begin(9600);
  // put your setup code here, to run once:

}

void loop() {
  char buffer[] ={' ',' ',' ',' ',' ', ' ',' '};
  if (Serial.available()){
    String sPower = Serial.readStringUntil('A');
    int power = sPower.toInt();
    
    String sAngle =Serial.readStringUntil('D');
    int angle = sAngle.toInt();
    
    String sDir = Serial.readStringUntil('E');
    int dir = sDir.toInt();

    Serial.println(power);
    Serial.println(angle);
    Serial.println(dir);
    }
    
}
