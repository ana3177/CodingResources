
// Commenting code

// you can add comments to your code by using "//" 
//you can also comment large sections of code using "/*"
//Like this:
/*
  anything below this line will be commented out
  when something is commented out, that means the program doesn't read it
  comments can be useful to tell others (and remind our future selves) what we are doing
  to tell the program we are done commenting, we type /* backwards like this:
*/

//Arduino Variables
/*
 * Whenever we are working with information, we need to hold it in a variable
 * There are different types of variables depending on the information
 * Numbers:
 * int: int describes an integer. This is going to be the most common number type. These can be positive or negative 
 * unsigned int: just like an integer, except these can only be positive 
 * float: floating point numbers are numbers that have decimal points. If you're doing math with floats, you need to add a decimal point. (see below)
 * long: long variables are used when you have a really large number (in the billions)
 * byte: a byte stores an unsigned number from 0 to 255
 * Letters and Words:
 * char: char stores a character value. It is written in single quotes like this: 'A'
 * String: String can hold a word or many words. It is written using double quotes like this: "this is a string". Be sure to capitalize it
 * True/False:
 * bool: bool can hold true(1) or false (0) values
 * Arrays:
 * arrays store a collection of variables. We will talk more about these later
 */
 
 //declaring variables
 //start with the variable type, then the variable name (can be anything)
 int myNumber; //this will have a default value of 0
 int myNumber2 = 12; //you can give the varibale a starting value. This is called initializing
 char myLetter = 'a';
 String myName = "Ana";
 String mySentence = "Strings can have more than one word";
 bool areFeetStinky = true;
 
 

//Arduino Program Structure
/*
 * Arduino programs use two main void functions
 * A function is just a code block that does something
 * functions can be void, meaning they don't return anything
 * or they can return any variable type
 */
void setup() {
  // put your setup code here, to run once:
  //here is where you will want to assign your pins, start your serial monitor, and instantiate any elements
  Serial.begin(9600); //this starts your serial monitor. It is used to communicate with your Arduino. The number in () is the baud rate. 9600 and 115200 are the most common, usually you can use 9600 but some components may specify a baud rate
  pinMode(pinNumber, OUTPUT); //this is how to assign a pin. Output means it's connected to an effector. The Arduino is turning something on or off (light, motor, etc)
  pinMode(3, INPUT); //You can declare the pin name as a variable or just type the number of the pin. inputs are usually sensors. 
}

void loop() {
  // put your main code here, to run repeatedly:

}





//working with floats
void floats() {
  int x;
  int y;
  float z;

  x = 1;
  y = x / 2;          // y now contains 0, ints can't hold fractions
  z = (float)x / 2.0; // z now contains .5 (you have to use 2.0, not 2)

  //if you convert from a float to an int, you will lose whatever is after the decimal
  float a = 2.9;
  int b = a; //b is now equal to 2 (doesn't round)
  
  //if you want to round, you need to add 0.5:
  float a = 2.9;
  int b = a + 0.5; //b is now equal to 3 (if a was less than 2.5, we would still get 2 since a+0.5 would be less than 3)
  
  //you can also use the round() function:
  float a = 2.9;
  int b = round(a); //this will give us 3
}
