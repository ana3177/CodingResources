#define mic A4
#define led A3
float value;
void setup() {
  // put your setup code here, to run once:
Serial.begin(115200);
pinMode(mic, INPUT);
pinMode(led, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
value = map(analogRead(mic), 800, 1000, 0, 255);
Serial.println(value);
analogWrite(led, value*2 );
}
