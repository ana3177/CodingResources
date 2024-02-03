#define echoPin 2
#define trigPin 3
#define led 4
void setup() {
  // put your setup code here, to run once:
Serial.begin (9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(led, OUTPUT);
 
}

void loop() {
  // put your main code here, to run repeatedly:
long duration, distance;
  digitalWrite(trigPin, LOW);  
  delayMicroseconds(2); 
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10); 
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration/2) / 29.1;
  if (distance < 20) {  // This is where the LED On/Off happens
    digitalWrite(led,HIGH); 
    }
  else {
    digitalWrite(led,LOW);
  }
  if (distance >= 200 || distance <= 0){
    Serial.println("Out of range");
  }
  else {
    Serial.print(distance);
    Serial.println(" cm");
  }
  delay(500);

}
