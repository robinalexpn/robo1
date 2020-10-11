#include <AFMotor.h>
#include <Arduino.h>
#include <Servo.h>

Servo myservo; // create servo object to control a servo
// twelve servo objects can be created on most boards

AF_DCMotor motor(4);

int pos = 0; // variable to store the servo position

void setup()
{

  Serial.begin(9600); // set up Serial library at 9600 bps
  Serial.println("Motor test!");
  myservo.attach(9); // attaches the servo on pin 9 to the servo object

  // turn on motor
  motor.setSpeed(200);
  motor.run(RELEASE);
}

/**
 * Use ultrasonic to check obstacles
 * return 0 if there is a problem
 * return 1 if there is enough way
 */
int checkObstacles()
{
  return 1;
}

/**
 * Move forwards
 */
void moveforward()
{

  motor.run(FORWARD);
  for (int i = 0; i < 255; i++)
  {
    motor.setSpeed(i);
    delay(10);
  }
}

/**
 * Move backwards
 */
void move_backwards()
{
  Serial.print("tock");

  motor.run(BACKWARD);
  for (int i = 0; i < 255; i++)
  {
    motor.setSpeed(i);
    delay(10);
  }
}

/**
 * Stop the motor
 */

void stop()
{
  Serial.print("tech");
  motor.run(RELEASE);
  delay(1000);
}
void look_left()
{

  for (pos = 0; pos <= 180; pos += 1)
  { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    myservo.write(pos); // tell servo to go to position in variable 'pos'
    delay(8);           // waits 15ms for the servo to reach the position
  }
  for (pos = 180; pos >= 0; pos -= 1)
  {                     // goes from 180 degrees to 0 degrees
    myservo.write(pos); // tell servo to go to position in variable 'pos'
    delay(8);           // waits 15ms for the servo to reach the position
  }
}

const int RUNNING = 11;
const int STOP = 12;
const int LOOK_LEFT = 13;
const int LOOK_RIGHT = 14;

int STATE = RUNNING;
void loop()
{
  switch (STATE)
  {
  case RUNNING:
    /* code */
    break;

  default:
    break;
  }
  Serial.print("tick");
}
