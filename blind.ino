// Smart Blind Stick using Arduino Uno with 3 Ultrasonic Sensors in Proteus

// Define the pins for the first ultrasonic sensor
const int trigPin1 = 13;
const int echoPin1 = 12;

// Define the pins for the second ultrasonic sensor
const int trigPin2 = 11;
const int echoPin2 = 10;

// Define the pins for the third ultrasonic sensor
const int trigPin3 = 9;
const int echoPin3 = 8;

// Define the pins for the buzzer and LED
const int buzzerPin = 3;
const int ledPin = 7;

// Define variables
long duration1, duration2, duration3;
int distance1, distance2, distance3;
int threshold = 25; // The threshold distance in cm

void setup() {
  // Set the pins as inputs and outputs
  pinMode(trigPin1, OUTPUT);
  pinMode(echoPin1, INPUT);
  pinMode(trigPin2, OUTPUT);
  pinMode(echoPin2, INPUT);
  pinMode(trigPin3, OUTPUT);
  pinMode(echoPin3, INPUT);
  pinMode(buzzerPin, OUTPUT);
  pinMode(ledPin, OUTPUT);

  // Start the serial communication
  Serial.begin(9600);
}

void loop() {
  // Clear the trigger pin for the first ultrasonic sensor
  digitalWrite(trigPin1, LOW);
  delayMicroseconds(2);

  // Send a 10 microsecond pulse to the trigger pin for the first ultrasonic sensor
  digitalWrite(trigPin1, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin1, LOW);

  // Measure the duration of the pulse on the echo pin for the first ultrasonic sensor
  duration1 = pulseIn(echoPin1, HIGH);

  // Calculate the distance in cm for the first ultrasonic sensor
  distance1 = duration1 / 58.2;

  // Print the distance to the serial monitor for the first ultrasonic sensor
  Serial.print("Distance1: ");
  Serial.print(distance1);
  Serial.println(" cm");

  // Clear the trigger pin for the second ultrasonic sensor
  digitalWrite(trigPin2, LOW);
  delayMicroseconds(2);

  // Send a 10 microsecond pulse to the trigger pin for the second ultrasonic sensor
  digitalWrite(trigPin2, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin2, LOW);

  // Measure the duration of the pulse on the echo pin for the second ultrasonic sensor
  duration2 = pulseIn(echoPin2, HIGH);

  // Calculate the distance in cm for the second ultrasonic sensor
  distance2 = duration2 / 58.2;

  // Print the distance to the serial monitor for the second ultrasonic sensor
  Serial.print("Distance2: ");
  Serial.print(distance2);
  Serial.println(" cm");

  // Clear the trigger pin for the third ultrasonic sensor
  digitalWrite(trigPin3, LOW);
  delayMicroseconds(2);

  // Send a 10 microsecond pulse to the trigger pin for the third ultrasonic sensor
  digitalWrite(trigPin3, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin3, LOW);

  // Measure the duration of the pulse on the echo pin for the third ultrasonic sensor
  duration3 = pulseIn(echoPin3, HIGH);

  // Calculate the distance in cm for the third ultrasonic sensor
  distance3 = duration3 / 58.2;

// Print the distance to the serial monitor for the third ultrasonic sensor
  Serial.print("Distance3: ");
  Serial.print(distance3);
  Serial.println(" cm");


  // Check if the distance is less than the threshold 
  if (distance1 <= threshold || distance2 <= threshold || distance3 <= threshold ) 
  {
    // Turn on the buzzer and LED
    digitalWrite(buzzerPin, HIGH);
    digitalWrite(ledPin, HIGH);
  } 
  else 
  {
    // Turn off the buzzer and LED
    digitalWrite(buzzerPin, LOW);
    digitalWrite(ledPin, LOW);
  }

  // Wait for 100 milliseconds
  delay(100);
}  

