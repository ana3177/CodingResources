//How to use the MCP23018 I/O Expander

#include "MCP23008.h" //I/O Expander Library
#include "Wire.h"

MCP23008 MCP(0x20); //instantiate the expander

void setup() {
  Serial.begin(115200); //begin serial monitor
   if(!MCP.begin()){       //if expander is not communicating via i2c at the address 0x20 (address found using i2c scanner) 
    Serial.println("not found");
    while(1);                      //don't continue until communication is established
  }

  //to declare a pin 
  MCP.pinMode(0, OUTPUT); //set GPA0 to be an output
  for(int i=1; i<16; i++){                //for all the other pins on the expander
    MCP.pinMode(i, INPUT_PULLUP);         //set all pins to be input pullups 
  }
}

void loop() {
   //for(int i=1; i<8; i++){    //for all pins on the expander
    if(MCP.digitalRead(1)){  //if they're low (change 1 to i)
      Serial.println("pressed");        //send their ID to serial (change "pressed" to i)
      MCP.digitalWrite(0, HIGH);      //turn LED on
      delay(10);             //wait 10ms
    }
    else{
      MCP.digitalWrite(0, 0);   //turn LED off
    }
 // } //uncomment for for loop
}
