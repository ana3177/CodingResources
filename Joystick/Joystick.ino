#define VCC 12
#define XOUT 11
#define YOUT 10
#define SEL 9
#define GND 8

void setup() {
  pinMode(VCC, OUTPUT);
  pinMode(GND, OUTPUT);
  pinMode(XOUT, INPUT);
  pinMode(YOUT, INPUT);
  pinMode(SEL, INPUT);

  digitalWrite(VCC, HIGH);
  digitalWrite(GND, LOW);
  Serial.begin(115200);
}

void loop() {
  Serial.print("X:  ");
  Serial.print(digitalRead(XOUT));
  Serial.print(" \tY:  ");
  Serial.print(digitalRead(YOUT));
  Serial.print(" \tSEL: ");
  Serial.print(digitalRead(SEL));
  Serial.println();
}
