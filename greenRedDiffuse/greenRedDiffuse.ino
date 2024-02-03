#define pin1 2  //One side of LED is plugged into pin 2 on microcontroller
#define pin2 3  //Other side of LED is plugged into pin 3 on microcontroller

void setup() {
  // put your setup code here, to run once:
pinMode(pin1, OUTPUT);  //set pin 1 as output
pinMode(pin2, OUTPUT);  //set pin 2 as output
//sends a signal to one side and grounds the other side
digitalWrite(pin1,LOW); //grounds side connected to pin 1
digitalWrite(pin2, HIGH); //sends power to the side connected to pin 2
delay(1000); //wait 1s
//reverse the direction (should change color)
digitalWrite(pin2,LOW); 
digitalWrite(pin1, HIGH);


}

void loop() {
  // put your main code here, to run repeatedly:
digitalWrite(pin1,LOW);
digitalWrite(pin2, HIGH);
delay(1000);
digitalWrite(pin2,LOW);
digitalWrite(pin1, HIGH);
delay(1000);
}
