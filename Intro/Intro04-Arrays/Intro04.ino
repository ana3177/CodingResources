//Arrays are a collection of variables of the same type
//they can be declared in many ways
//least defined
int myArray[26]; //this array can have 26 values. All are default 0
float myFloats[] = {0.1, 0.2}; //I didn't specify the size of this array, so it can grow
char alphabet[26] = {"abcdefghijklmnopqrstuvwxyz"};

String input;
const int limit = 100;
char letter[limit];
int f=0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  Serial.println("type your message");
  while (f==0){
    while(Serial.available()){        //while the Serial Monitor is communicating
      input = Serial.readString();    //read whatever was typed into Serial Monitor and store it as a string
      input.toLowerCase();            //make everything a lowecase letter
      if(input.length()>= limit){     //if the message is too long
        Serial.println("too long");   //print too long to the serial monitor
        delay(1000);                  //wait 1s
      }
    input.toCharArray(letter,input.length()+1);     //cast the input string to a character array (letter)
    for(int i=0; i<input.length(); i++){          //starting at 0 going to the last letter
      Serial.println(letter[i]);
    }
    }
  }
}
