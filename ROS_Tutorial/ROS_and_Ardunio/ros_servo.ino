//header files
#include <ros.h>
#include <Servo.h>
#include <std_msgs/UInt16.h>
#include <std_msgs/String.h>

//Initalize 
Servo servo;

//allows us to create publishers and subscribers
ros::NodeHandle nh;

//Initalize publisher
std_msgs::String str_msg;
ros::Publisher chatter("chatter", &str_msg);
char moveServo[13] = "Servo Moved!";

//call back function for our subscriber 
void servo_cb(const std_msgs::UInt16& cmd_msg ) {

  //perform servo operations
  servo.write(cmd_msg.data);
  
  //publish message
  str_msg.data = moveServo;
  chatter.publish( &str_msg);
    
}

//instanatiate a Subscriber with a topic 
ros::Subscriber<std_msgs::UInt16> sub("servo", servo_cb);


void setup() {
 
 //set up servo
 servo.attach(9);

 //initialize Node and subscribe any topics
 nh.initNode();
 nh.advertise(chatter);
 nh.subscribe(sub);

}

void loop() {

  // where all ros communication is handle
  nh.spinOnce();
  delay(1);

}