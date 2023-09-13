#include <iostream>
#include "ros/ros.h"
#include "std_msgs/Float64.h"


std_msgs::Float64 HandleLeftArmControl();
std_msgs::Float64 HandleRightArmControl();
std_msgs::Float64 HandleHeadControl();

int main(int argc, char **argv) {
  std::cout << "Hello World!\n";
  
  ros::init(argc, argv, "robot_controller_node");
  
  ros::NodeHandle n;
  
  ros::Publisher leftArmPub = n.advertise<std_msgs::Float64>("/left_arm_controller/command", 1000);
  ros::Publisher rightArmPub = n.advertise<std_msgs::Float64>("/right_arm_controller/command", 1000);
  
  ros::Publisher headPub = n.advertise<std_msgs::Float64>("/head_controller/command", 1000);
  
  while (ros::ok())
 {
     char armChoice;
     std::cout << "Enter L/l for Left Arm \nEnter R/r for Right Arm \nEnter H/h for Head Control \nYour Choice : ";
     std::cin >> armChoice;
     std_msgs::Float64 speedMsg;
     switch(armChoice)
     {
      case 'L':
      case 'l':
        speedMsg = HandleLeftArmControl();
        leftArmPub.publish(speedMsg);
        break;
      case 'R':
      case 'r':
        speedMsg = HandleRightArmControl();
        rightArmPub.publish(speedMsg);
        break;
      case 'H':
      case 'h':
        speedMsg = HandleHeadControl();
        headPub.publish(speedMsg);
        break;
     }


 }

  
  return 0;
}



std_msgs::Float64 HandleLeftArmControl()
{
     char leftInput;
     std::cout << "Please enter a value for Left Arm Control: ";
     std::cin >> leftInput;
     std_msgs::Float64 speedMsg;
     switch(leftInput)
     {
      case 'a':
         speedMsg.data = 0.5f;
         break;
      case 's':
         speedMsg.data = 0.0f;
         break;
      case 'd':
         speedMsg.data = -0.5f;
         break;
     }
      
      return speedMsg;
     
}


std_msgs::Float64 HandleRightArmControl()
{
 char rightInput;
     std::cout << "Please enter a value for Right Arm Control: ";
     std::cin >> rightInput;
     std_msgs::Float64 speedMsg;
     switch(rightInput)
     {
      case 'a':
         speedMsg.data = 0.5f;
         break;
      case 's':
         speedMsg.data = 0.0f;
         break;
      case 'd':
         speedMsg.data = -0.5f;
         break;
     }
     
     return speedMsg;
      
}



std_msgs::Float64 HandleHeadControl()
{
 char headInput;
     std::cout << "Please enter a value for Head Control:  ";
     std::cin >> headInput;
     std_msgs::Float64 speedMsg;
     switch(headInput)
     {
      case 'a':
         speedMsg.data = 0.5f;
         break;
      case 's':
         speedMsg.data = 0.0f;
         break;
      case 'd':
         speedMsg.data = -0.5f;
         break;
     }
     
     return speedMsg;
      
 
}


