#include <Wire.h>;

int s;
void setup() {
  Wire.begin()
  Serial.begin(9600);

}

void loop() {

  while (Serial.available()) {
    delay(2);  
    s=Serial.read();
   Wire.beginTransmission(9);
  Wire.write(s); 
  Wire.endTransmission();
    
  }



  }

