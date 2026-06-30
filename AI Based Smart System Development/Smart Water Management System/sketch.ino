#include <ESP32Servo.h>;
const int pot=34;
const int r=23;
const int g=22;
const int b=21;
const int servo=2;
Servo myServo;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  Serial.println("Initializing Smart Water Tank Controller");
  delay(2000);
  Serial.println("System Initialized");
  myServo.attach(servo);
}



void loop() {
  int potValue=analogRead(pot);
  if(potValue<=1352){
    analogWrite(g,0);
    analogWrite(r,255);
    myServo.write(180);
    Serial.println("Low Level");
  }
  else if(potValue>1352 && potValue<=2704){
    analogWrite(r,255);
    analogWrite(g,255);
    myServo.write(90);
    Serial.println("Medium Level");
  }
  else{
    analogWrite(r,0);
    analogWrite(g,255);
    myServo.write(0);
    Serial.println("Full Tank");
  }
}
