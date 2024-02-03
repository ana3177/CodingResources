
//Arduino Functions
/*
 * Functions always have the structure function(). Sometimes, there will be information in the parentheses 
 * Here, we will outline some of the most common functions and how to call them
 */

//Digital and analog pins
 /*
   * digitalRead(pin): will read the value of a digital pin. This will either be HIGH (1) or LOw (0)
   * digitalWrite(pin, value): will write the value to a digital pin. You can only write values of HIGH(1) or LOW(0)
   * analogRead(pin): will read the value of an anaog pin. It will map input voltages to integer values between 0 and 1023
   * analogWrite(pin, value): will write the value as a PWM wave to a digital pin. Value is the duty cycle and should be between 0 and 255
   */
//Time-based functions
/*
 * delay(valueMs): will pause the program for the amount of time in the parentheses. This is in milliseconds so to delay 1s we need delay(1000);
 * delayMicroseconds(us): will pause the program for the amount of time given. The time here is in microseconds to to pause for 1s we need delayMircoseconds(1000000);
 * millis(): will give you how much time has elapsed since the program started. (see functions below)
 * micros(): same as millis() but with microseconds
 */
//Math Functions
/* 
 *  abs(number): returns the absolute value of the number
 *  constrain(x, a, b): constrains x to a value between a and b (see below)
 *  map(value, fromLow, fromHigh, toLow, toHigh): will map the value from range fromLow-fromHigh to toLow-toHigh (see below)
 *  max(x,y): will give you the larger of the two between x and y
 *  min(x,y): will give you the smaller of the two between x and y
 *  pow(a,b): will give you the value of a raised to the power of b
 *  sqrt(x): will give you the value of the square root of x
 *  random(max): will give you a random number between 0 and max
 *  random(min, max): will give you a random number between min and max
 */

//Arithmetic
/*
 * % : remainder
 * * : multiplication
 * + : addition
 * - : subtraction
 * / : division
 * = : assign value
 * ++ : go up by one
 * -- : go down by one
 * += x : go up by x
 * -= x : go down by x
 * /= x : divide by x
 * *= x : multiply by x
 */

//logic
/*
 * != : does not equal
 * < : less than 
 * <= : less than or equal to
 * == : is equal to
 * > : greater than
 * >= : greater than or equal to
 * ! : logical not
 * && : logical and
 * || : logical or
 */

 
#define btn 12 //button pin connected to pin 12 on Arduino 
unsigned long lastBtnPress; //here is where we will store the time the last button was pressed at
int timeBetweenButtonPresses = 250; //we want 1/4 of a second to pass before we can press the button again
int numberOfPresses; //keeps track of how many times we pressed the button

void setup() {
  // put your setup code here, to run once:
  pinMode(pin, mode); // mode can be OUTPUT, INPUT, or INPUT_PULLUP 
  pinMode(btn, INPUT);
  pinMode(A0, INPUT_PULLUP); //pins can be set to analog pins also. INPUT_PULLUP inverts the functionality of the pin, so HIGH when the sensor is off and LOW means the sensor is on
  //when connecting a sensor to an INPUT_PULLUP pin, the other end should be connected to ground

  
}

void loop() {
  // put your main code here, to run repeatedly:

}

void timing(){
  if(btn == 1){ //if the button is pressed
    if(millis() - lastBtnPress >= timeBetweenButtonPresses){ //if 1/4 of a second has passed since the last time the button was pressed
      numberOfPresses ++; //count it as a new button press
      lastBtnPress = millis(); //store the time the button was pressed 
    }
  }
}

void constrainingAndMapping(){
  constrain(sensorValue, 0, 255); //will constrain sensor values to values between 0 and 255
  map(sensorValue, 0, 1023, 0, 255); //will map sensor values coming in with range 0-1023 to values between 0 and 255
}
