const int trigPin = 9;
const int echoPin = 10;
const int Buzzer1 = 5;
//#define Buzzer2 = 7;

int sound =20;

long duration;
int distanceCm, distanceInch;
void setup()
{ 

 Serial.begin(9600); 
 pinMode(trigPin, OUTPUT);
 pinMode(echoPin, INPUT);

 pinMode(6, OUTPUT); // Connect LED Pin D6
 pinMode(5, OUTPUT); // Connect Buzzer1 Pin D5
 //pinMode(7, OUTPUT); // Connect Buzzer2 Pin D7

}
void loop()
{


digitalWrite(trigPin, LOW);
delayMicroseconds(2);
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);
duration = pulseIn(echoPin, HIGH);
distanceCm= duration*0.034/2;
distanceInch = duration*0.0133/2;
Serial.println("Distance: ");
Serial.println(distanceCm);
delay (100);
// See the Ultrasonic Sensor Value in Serial Monitor



if(distanceCm < 25)  // You can Change the value 
{
  
  digitalWrite(5, HIGH);  // Buzzer1 ON
  // digitalWrite(7, HIGH); // Buzzer2 ON
  digitalWrite(6, HIGH);  // LED ON 
  
}

else
{
    digitalWrite(5,LOW);  // Buzzer1 OFF
    //digitalWrite(7,LOW);  // Buzzer2 OFF
    digitalWrite(6,LOW);  // LED OFF 
}
}