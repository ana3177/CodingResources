#include <Adafruit_LIS3DH.h>
#include <Adafruit_Sensor.h>
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
  Serial.print("\t\tX: "); Serial.print(event.acceleration.x);
  Serial.print(" \tY: "); Serial.print(event.acceleration.y);
  Serial.print(" \tZ: "); Serial.print(event.acceleration.z);
  Serial.println(" m/s^2 ");

  Serial.println();

  delay(200);

}
