#define led 5
#define sens A1
float sensVal;
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(led, OUTPUT);
pinMode(sens, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(led, HIGH);
  delayMicroseconds(500);
  sensVal= analogRead(sens);
  Serial.println(sensVal);
}
