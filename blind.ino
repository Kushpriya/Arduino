/*
 * make a smart stick that helps the Blind
 */
 #define trigPin  2
 #define echoPin 3

 #define Buzzer1 10//active
 #define Buzzer2 11//passive
  #define Led1 6//Vibration

 
int sound = 250;


void setup() {
  Serial.begin (9600);
 pinMode(trigPin, OUTPUT);
 pinMode(echoPin, INPUT);
  pinMode(Buzzer1, OUTPUT);
 pinMode(Buzzer2, OUTPUT);
 pinMode(Led1, OUTPUT);
}

void  loop() {
  Serial.begin(9600);

  long duration, distance;
  digitalWrite(trigPin,  LOW);
  delay(2);
  digitalWrite(trigPin, HIGH);
  delay(10);
  digitalWrite(trigPin,  LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration/2) / 29.1;
  digitalWrite(Buzzer1, LOW);
  digitalWrite(Buzzer2, LOW);
  digitalWrite(Led1,  LOW);
  
  if (distance<40) {
    digitalWrite(Led1, HIGH);
    delay(2000);
  }
  if (distance<20) {
    digitalWrite(Led1, HIGH);
    delay(2000);
    digitalWrite(Buzzer1, HIGH);
    delay(2000);
  }
  if (distance<10)  {
    digitalWrite(Led1, HIGH);
    delay(2000);
    digitalWrite(Buzzer1,  HIGH);
    delay(2000);
    digitalWrite(Buzzer2, HIGH);
    delay(2000);
  }
  }

   

