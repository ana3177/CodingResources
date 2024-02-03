//How to use the MCP23017 I/O Expander
//Pin indecies
/* NAME   id  #
 * GPA0   0   21
 * GPA1   1   22
 * GPA2   2   23
 * GPA3   3   24
 * GPA4   4   25
 * GPA5   5   26
 * GPA6   6   27
 * GPA7   7   28
 * GPB0   8   1
 * GPB1   9   2 
 * GPB2   10  3
 * GPB3   11  4
 * GPB4   12  5
 * GPB5   13  6
 * GPB6   14  7
 * GPB7   15  8
 */
#include <Adafruit_MCP23X17.h> //I/O Expander Library

Adafruit_MCP23X17 mcp; //instantiate the expander

void setup() {
  Serial.begin(115200); //begin serial monitor
   if(!mcp.begin_I2C(0x27)){       //if expander is not communicating via i2c at the address 0x27 (address found using i2c scanner) 
    Serial.println("not found");
    while(1);                      //don't continue until communication is established
  }

  //to declare a pin 
  mcp.pinMode(0, OUTPUT); //set GPA0 to be an output
  for(int i=1; i<16; i++){                //for all the other pins on the expander
    mcp.pinMode(i, INPUT_PULLUP);         //set all pins to be input pullups 
  }
}

void loop() {
   for(int i=1; i<16; i++){    //for all pins on the expander
    if(!mcp.digitalRead(i)){  //if they're low
      Serial.write(i);        //send their ID to serial
      mcp.digitalWrite(0, HIGH);
      delay(10);             //wait 10ms
    }
  }
}
