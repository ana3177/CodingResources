#include <Wire.h>
#include <VL53L0X.h>
VL53L0X sensor;

byte val =0;
void setup() {
  Wire.begin();
  Serial.begin(9600);
  sensor.setTimeout(500);
  if(!sensor.init()){
    Serial.println("sensor not found");
    while(1){}
  }
  sensor.startContinuous();
  
}

void loop() {
 Serial.print(sensor.readRangeContinuousMillimeters());
 if(sensor.timeoutOccurred()){Serial.print("timeout");}
 Serial.println();
  
}
