#include <Adafruit_NeoPixel.h> //this is the included library
#define s1 A1  //this is how we tell it which pin the sensor/button is connected to
#define s2 A2  //these are the sensors. For ours it would just be one button 
#define s3 A3
#define s4 A4
#define s5 A5
#define s6 A6

#define led1 13 //using two strips, one is connected to pin 12, the other 13 and they both have 37 LEDs
#define led2 12
#define ledCount 37

int sig1, sig2, sig3, sig4, sig5, sig6; //these are just variables that I'll use later
float c1, c2, c3, c4, c5, c6;

Adafruit_NeoPixel strip1(ledCount, led1, NEO_GRB + NEO_KHZ800); //this is where you instantiate objects, basically tell the computer that something exists and what it is
Adafruit_NeoPixel strip2(ledCount, led2, NEO_GRB + NEO_KHZ800); //(number of LEDs in strip, pin connected to LED, dont change the third part)

void setup() {          // this part just runs once
  Serial.begin(115200); // use 9600 instead of 115200
  pinMode(s1, INPUT);  //button is input, don't have to declare strips as output
  pinMode(s2, INPUT);
  pinMode(s3, INPUT);
  pinMode(s4, INPUT);
  pinMode(s5, INPUT);
  pinMode(s6, INPUT);
  strip1.begin();    //function that also declares it an output
  strip1.show();
  strip1.setBrightness(75);
  strip2.begin();
  strip2.show();
  strip2.setBrightness(75);
}

void loop() {
  readSensors();
//  Serial.print("sig1: ");
//  Serial.println(sig1);
//  Serial.print("sig2: ");
//  Serial.println(sig2);
//  Serial.print("sig3: ");
//  Serial.println(sig3);
//  Serial.print("sig4: ");
//  Serial.println(sig4);
//  Serial.print("sig5: ");
//  Serial.println(sig5);
//  Serial.print("sig6: ");
//  Serial.println(sig6);
  lightStrips();
}

void readSensors(){
  sig1 = analogRead(s1);         //read the signal of s1 and call it sig 1. for ours digitalRead(button)
  if(sig1<100) c1=getColor(sig1); // if <100, convert to color value
  else c1=0;
  sig2 = analogRead(s2);
  if(sig2<100) c2=getColor(sig2);
  else c2=0;
  sig3 = analogRead(s3);
  if(sig3<100) c3=getColor(sig3);
  else c3=0;
  sig4 = analogRead(s4);
  if(sig4<100) c4=getColor(sig4);
  else c4=0;
  sig5 = analogRead(s5);
  if(sig5<100) c5=getColor(sig5);
  else c5=0;
  sig6 = analogRead(s6);
  if(sig6<100) c6=getColor(sig6);
  else c6=0;
}

int getColor(int value){
  int colorValue = value*255/100;  
  return colorValue;
}

void lightStrips(){
  for(int i=0; i<strip1.numPixels(); i++){ //start at 0, go up to the number of pixels in the strip - 1
    strip1.setPixelColor(i, strip1.Color(c1, c2, c3));  //sets the color of each pizel one by one 
    strip2.setPixelColor(strip2.numPixels()-i, strip2.Color(c4, c5, c6));
    strip1.show();
    strip2.show();
    delay(10);
  }
}
