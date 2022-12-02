// C++ code
//
#include <Servo.h>

int echo = 0;

int trig = 0;

long readUltrasonicDistance(int triggerPin, int echoPin)
{
  pinMode(triggerPin, OUTPUT);  // Clear the trigger
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  // Sets the trigger pin to HIGH state for 10 microseconds
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  pinMode(echoPin, INPUT);
  // Reads the echo pin, and returns the sound wave travel time in microseconds
  return pulseIn(echoPin, HIGH);
}

Servo servo_6;

void setup()
{
  Serial.begin(9600);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  servo_6.attach(6, 500, 2500);
}

void loop()
{
  trig = 0.01723 * readUltrasonicDistance(2, 3);
  Serial.println(trig);
  delay(500); // Wait for 500 millisecond(s)
  if (trig < 100) {
    digitalWrite(4, HIGH);
    digitalWrite(5, LOW);
    servo_6.write(90);
  } else {
    digitalWrite(4, LOW);
    digitalWrite(5, HIGH);
    servo_6.write(0);
  }
  delay(500); // Wait for 500 millisecond(s)
}