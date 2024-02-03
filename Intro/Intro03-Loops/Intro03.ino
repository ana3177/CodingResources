#define btn 13 //button connected to digital pin 13 on Arduino 
#define led 12 //led connected to digital pin 12 on Arduino

bool isMyBtnPressed;
int numberOfPresses;
int sumOfNumbers;

void setup() {
  // put your setup code here, to run once:
  pinMode(btn, INPUT); //button is declared as an input
  pinMode(led, OUTPUT); //led is declared as an output
}

void loop() {
 
}

void forLoops(){
  //for loops have the structure: for(variable, variable stopping condition, increment/decrement){}
  for(int i=0; i<5; i++){ //starts at 0, goes up to 4, adds one each time
    Serial.print(i); //this would print out 01234
  }
  
  for(int i=1; i<5; i++){ //starts at 1, goes up to 4, adds one each time
    Serial.print(i); //this would print out 1234
  }
 
  for(int i=1; i<5; i+=2){  //starts at 1, goes up to 4, adds two each time
    Serial.print(i); //this would print out 13
  }

  for(int i=4; i>0; i--){   //starts at 4, goes down to 1, subtracts one each time
    sumOfNumbers = sumOfNumbers + i;
    Serial.print(sumOfNumbers); //would print 47910
  }
  
   for(int i=4; i>=0; i--){ //starts at 4, goes down to 0, subtracts one each time
    sumOfNumbers = sumOfNumbers + i;
    Serial.print(sumOfNumbers); //would print 4791010
  }
  
}



void ifStatements(){
   isMyBtnPressed = digitalRead(btn); //reads btn pin, when button is pressed, will read 1 (true), otherwise will read false (0)
  /*
   * when the code first starts, and the button has not been touched, the LED will be turned on
   * When a person presses the button for the first time, the LED will stay on as long as the button is held down 
   * When the button is released, the LED will turn off
   * As soon as the button is pressed 5 times, the LED will stay on no matter what
   */
  if(isMyBtnPressed == 1){  //if my button is pressed (remember to use two ==)
    digitalWrite(led, HIGH);   // turn the LED on. Can also write as digitalWrite(led, 1);
    numberOfPresses ++;
    delay(250);
  }
  if(!isMyBtnPressed){      //if my button is not pressed
    digitalWrite(led, 0);   //turn the led off. Can also write as digitalWrite(led, LOW);
  }
  
  digitalWrite(led, isMyBtnPressed); // this turns on the light when the button is pressed and off when its not

  if(numberOfPresses >= 5){       //if my button has been pressed 5 or more times 
    digitalWrite(led, 1);         // turn LED on
  }
  else if(numberOfPresses == 0){ // my button has not been pressed yet
    digitalWrite(led, HIGH);    //turn the light on 
  }
  else{                           //if my button has been pressed at least once but less than 5 times                
    digitalWrite(led, 0);         // turn the LED off
  }

}
