#include <SharpIR.h>

#define ir A0
#define model 1080


SharpIR sharp (0, 25, 93, 1080);
//0: the pin where your sensor is attached.
//25: the number of readings the library will make before calculating an average distance.
//93: the difference between two consecutive measurements to be taken as valid (in %)
//model: is an int that determines your sensor:  1080 for GP2Y0A21Y, 20150

int trigPin = 2;  //set the pins for the utrasonic sensor
int echoPin = 10;    

long duration, cm, inches;
   
void setup() {
  //Serial Port begin to recieve data in serial monitor
  Serial.begin (9600);
 
  //Define inputs and outputs

  //Ultrasonic sensor
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  //IR pins
  Serial.begin(9600);
  pinMode (ir, INPUT);
}
 
void loop()
{
  // val = analogRead(sensorpin);  // reads the value of the sharp sensor
  //Serial.println(val);  // prints the value of the sensor to the serial monitor
  //delay(100);  // wait for this much time before printing next value

  //IR Sensor code  
  int dis=sharp.distance();  // this returns the distance to the object you're measuring

  Serial.print("Mean distance: ");  // returns it to the serial monitor
  Serial.println(dis);

  //Ultrasonic Sensor code
  // The sensor is triggered by a HIGH pulse of 10 or more microseconds.
  // Give a short LOW pulse beforehand to ensure a clean HIGH pulse:
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
 
  // Read the signal from the sensor: a HIGH pulse whose
  // duration is the time (in microseconds) from the sending
  // of the ping to the reception of its echo off of an object.
  pinMode(echoPin, INPUT);
  duration = pulseIn(echoPin, HIGH);
 
  // convert the time into a distance from ultrasonic sensor readings
  cm = (duration/2) / 29.1;
  inches = (duration/2) / 74;
 
  Serial.print(inches);
  Serial.print("in, ");
  Serial.print(cm);
  Serial.print("cm");
  Serial.println();
 
  delay(250);

if (cm <15 )
  {
  //DO SOMETHING
  }
  else if (dis > 100)
  {
    
  //DO SOMETHING ELSE
  }
else  
  {
  //DO SOMETHING ELSE ELSE ;)
    //delay(1000);
  }
 
delay(50);
 
}

