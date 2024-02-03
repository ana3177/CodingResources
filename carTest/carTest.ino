#include <Adafruit_LIS3DH.h>
#include <Adafruit_Sensor.h>

#define R A3
#define L A2

float RVal, LVal;
Adafruit_LIS3DH accel = Adafruit_LIS3DH(); //instantiate a new sensor named accel

void setup() {
  Serial.begin(115200);
  while(!Serial) delay(10); //wait until the serial port is open
  if(!accel.begin(0x18)){   //if the sensor is not found at the address 0x18 (may need to change address)
    Serial.print("not found");
    while(1); // don't go on until it's found
  }
  Serial.println("sensor found");
}

void loop() {
  accel.read(); //get X Y and Z data
  //Serial.print("X:  "); Serial.print(accel.x);
  //Serial.print("  \tY:  "); Serial.print(accel.y);
  //Serial.print("  \tZ:  "); Serial.print(accel.z);
  //Serial.println();
  sensors_event_t event;
  accel.getEvent(&event);

  /* Display the results (acceleration is measured in m/s^2) */
  //Serial.print("\t\tX: "); Serial.print(event.acceleration.x);
  //Serial.print(" \tY: "); Serial.print(event.acceleration.y);
  //Serial.print(" \tZ: "); Serial.print(event.acceleration.z);
  //Serial.println(" m/s^2 ");

  //Serial.println();
 
  RVal = (10-(event.acceleration.y+event.acceleration.x)); //leaning right results in negative x acceleration
  LVal = (10-(event.acceleration.y-event.acceleration.x)); //leaning left results in negative y acceleration
  
  //Serial.print("R:  "); Serial.print(RVal);
  //Serial.print(" \tL: "); Serial.print(LVal);
  //Serial.println();

  if(RVal > 0 ){
    RVal = map(RVal, 0, 11, 0, 255);
  }
  else{
    RVal = 0;
  }
  if(LVal > 0 ){
    LVal = map(LVal, 0, 11, 0, 255);
  }
  else{
    LVal = 0;
  }
  analogWrite(R, RVal);
  analogWrite(L, LVal);
  delay(100);

}
