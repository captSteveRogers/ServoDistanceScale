#include<Servo.h>                                           //imported servo library

int servoPin=9;                                             //servo to be attached to the pin 9 of arduino
int trigPin=13;                                             //trigger pin to pin 13
int echoPin=11;                                             //echo pin attached to pin 11
float pingTime;                                             //time taken by ping to strike and come back
float targetDist;                                           //distance of the target from the ultrasonic sensor
float speedOfSound=340.00;                                  //speed of sound in air at a normal temperature
float servoPos;                                             //position of the servo 

Servo object;                                               //object created for the servo

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);                                       //Start the serial monitor
  object.attach(servoPin);                                  //Servo hooked up to the arduino
  pinMode(trigPin,OUTPUT);                                  //trig Pin attached to pin 13 
  pinMode(echoPin,INPUT);                                   //echo pin attached to pin 11
  object.write(30);                                         //servo's initial position is 30 degrees

}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(trigPin,LOW);                                //intital low signal for the pulse
  delayMicroseconds(2000);                                  //For the signal to settle
  digitalWrite(trigPin,HIGH);                               //___---___ for the pulse
  delayMicroseconds(20);                                    //time in high state
  digitalWrite(trigPin,LOW);                                //Signal to go low, pulse generated
  delayMicroseconds(10);                                    //Signal to settle
  speedOfSound=340./25000. ;                                //speed of sound converted to inches/microsec

  pingTime=pulseIn(echoPin,HIGH);                           //the time for the ping to return

  targetDist = speedOfSound * pingTime ;                    //The target distance in inches
  servoPos=15.*targetDist + 30.;                            //servo position determined from target dist. and using 30 to 150 degrees scale

  Serial.print("The distance is ");
  Serial.print(targetDist);
  Serial.println(" inches");
  object.write(servoPos);                                   //Servo scale shows distance
  delay(1000);

}
