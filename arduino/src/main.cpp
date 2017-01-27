//
// Created by matthew on 26/01/17.
//

#include <Arduino.h>
#include "Servo.h"
#include "ros.h"
#include "geometry_msgs/Twist.h"


ros::NodeHandle nh;
Servo theServo;

const int deadZoneThreshold = 93;

int rawSpeedFromX(float x) {
    if (x < 0) {
        return (int) (deadZoneThreshold - (-x * deadZoneThreshold));
    }
    else {
        return ((int) (93 + (x * deadZoneThreshold)));
    }
}

void callback(const geometry_msgs::Twist& msg) {
    int speed = rawSpeedFromX(msg.linear.x);
    theServo.write(speed);
}

ros::Subscriber<geometry_msgs::Twist> sub("cmd_vel", callback);

void setup() {
    theServo.attach(9);
    nh.initNode();
    nh.subscribe(sub);
    theServo.write(93);
}

void loop() {
    nh.spinOnce();
}