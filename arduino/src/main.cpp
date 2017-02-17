//
// Created by matthew on 26/01/17.
//

#include <Arduino.h>
#include "ros.h"
#include "sensor_msgs/JointState.h"
#include <control_msgs/JointTrajectoryActionGoal.h>
#include <trajectory_msgs/JointTrajectory.h>
#include <trajectory_msgs/JointTrajectoryPoint.h>

ros::NodeHandle nh;


// void jt_callback(const trajectory_msgs::JointTrajectoryConstPtr &msg) {
void jt_callback(const trajectory_msgs::JointTrajectory &msg) {
  nh.loginfo("msg received");

  // Print msg.points_length
  char log_msg[80];
  sprintf(log_msg,"msg.points = %i",msg.points_length);
  nh.loginfo(log_msg);

  //Print msg.joint_names[0]
  sprintf(log_msg,"msg.joint_names[0] = %s",msg.joint_names[0]);
  nh.loginfo(log_msg);

  trajectory_msgs::JointTrajectoryPoint *points = msg.points;


  // Print msg.points[0].positions_length
  sprintf(log_msg,"msg.points[0].positions_length = %d",points[0].positions_length);
  nh.loginfo(log_msg);

  // Print points.positions[0]
  char result[8]; // Buffer big enough for 7-character float
  dtostrf(points[0].positions[0], 6, 2, result); // Leave room for too large numbers!
  sprintf(log_msg,"points[0].positions[0] =%s", result);
  nh.loginfo(log_msg);

  // Print points.positions[1]
  dtostrf(points[0].positions[1], 6, 2, result); // Leave room for too large numbers!
  sprintf(log_msg,"points[0].positions[1] =%s", result);
  nh.loginfo(log_msg);

  // Print points.positions[2]
  dtostrf(points[0].positions[2], 6, 2, result); // Leave room for too large numbers!
  sprintf(log_msg,"points[0].positions[2] =%s", result);
  nh.loginfo(log_msg);

  // Print points.positions[3]
  dtostrf(points[0].positions[3], 6, 2, result); // Leave room for too large numbers!
  sprintf(log_msg,"points[0].positions[3] =%s", result);
  nh.loginfo(log_msg);

}

ros::Subscriber<trajectory_msgs::JointTrajectory> jt_sub_("arm_controller/command", jt_callback);

void setup() {
    nh.initNode();
    nh.subscribe(jt_sub_);
    nh.spinOnce();
}

void loop() {
    nh.spinOnce();
    // nh.loginfo("Program loop");
}