#include <Servo.h>

const int trigPin = 5;   // Trigger pin of the ultrasonic sensor
const int echoPin = 6;  // Echo pin of the ultrasonic sensor
const int servoPin = 7;  // Servo control pin

Servo myservo;  // Create a servo object

void setup() {
  pinMode(trigPin, OUTPUT);
  
  pinMode(echoPin, INPUT);
  myservo.attach(servoPin);  // Attaches the servo to the servoPin
  Serial.begin(9600);
}

void loop() {
  long duration, distance;

  // Send a pulse to the ultrasonic sensor to trigger a measurement
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2); 
  digitalWrite(trigPin, HIGH);

  // Measure the time it takes for the echo to return
  duration = pulseIn(echoPin, HIGH);

  // Calculate the distance in centimeters
  distance = (duration / 2) / 29.1;

  // Print the distance to the Serial Monitor
  Serial.print("Distance: ");
    Serial.print(distance);
  Serial.println(" cm");

  // If an object is detected within a certain range, move the servo 90 degrees
  if (distance <= 5) {  // You can adjust the distance threshold as needed00
    myservo.write(90);  // Rotate the servo to 90 degrees
    delay(200);  // Wait for the servo to reach the desired position
  } else {
    myservo.write(0);  // Rotate the servo back to 0 degrees
    delay(500);  // Wait for the servo to reach the desired position
  }
}