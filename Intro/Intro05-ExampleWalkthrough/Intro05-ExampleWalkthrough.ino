//header
//1. Add any libraries that you need. These let us call special functions. You need to add libraries before you can use them (tools > manage libraries)
//It usually takes the form: #include <name.h>
#include <math.h>

//2. define all of your pins. You should have one #define statement for every connected pin.  
//It should take the following form: #define nameOfThing (#pin)

#define led 3 //There is an LED connected to pin 3 on microcontroller
#define button 4 //There is a button connected to pin 4 on microcontroller

//3. Create global variables. This is anything you want to keep track of; It can be numbers, words, or true/false
//It should take the following form: variableType variableName; OR variableType variableName = value;

bool lightOn = false; //create a true/false variable that tracks whether the light is on. Set it to start as false
int numberOfpresses; //create an integer variable to track how many times the button is pressed. Default value is 0. 



void setup() {
  // this code runs only one time

  //1. set your pins! For all of the pins you #defined, you must declare them as either INPUT or OUTPUT
  //INPUT -> (sensors) things that collect information from the environment and send it to the computer, buttons, etc
  //OUTPUT -> (effectors) things that recieve a signal from the computer and perform an action, motors, lights, etc. 
  //It should take the following form: pinMode(name, PINMODE);

  pinMode(led, OUTPUT);
  pinMode(btn, INPUT);

  //2. Start your serial port. The serial port is how you communicate with your microcontroller while it'r running
  //You have to send it things to display, but first you have to start it and declare it's baud rate
  //9600 and 115200 are the most common, but sometimes you may have a chip that communicates at a specific rate
  //It should take the following form: Serial.begin(baudrate);
  Serial.begin(9600);

  //3. Send a command to Serial
  //This is helpful to know if our code has started running
  //These take the form Serial.print(thingToPrint) or Serial.println(thingToPrint) if you want a new line
  Serial.println("Start");

}

void loop() {
  // put your main code here, to run repeatedly:
  // Here is where the meat and potatoes goes. 
}
