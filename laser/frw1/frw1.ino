#include <Servo.h>

Servo alfam,betam;
void setup() {
// put your setup code here, to run once:
Serial.begin(115200);
Serial.println("A B controler");
alfam.attach(5);
betam.attach(6);
alfam.write(0);
betam.write(0);
}
String GMCode;

void loop() {
// put your main code here, to run repeatedly:
  if (Serial.available())
  {
    char c = Serial.read();
    if (c=='\n')
    {
      parseGMCode(GMCode);
      GMCode ="";
    }
    else
    {
      GMCode += c;
    }
  }
//  betam.write(120);
//  delay(1000);
//  betam.write(10);
//  delay(1000);
}
void parseGMCode(String com)
{
  String Part1;
  String Part2;
  Part1 = com.substring(0,com.indexOf(" "));
  Part2 = com.substring(com.indexOf(" ") + 1);
  
  
  alfam.write(Part1.toInt());
//  
  betam.write(Part2.toInt());
//  delay(15); 
  
  Serial.print("A= ");
  Serial.print(Part1);
  Serial.print(" B= ");
  Serial.println(Part2);
  
}
  
