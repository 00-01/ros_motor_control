#define NOTE_C4  262
#define NOTE_B6  1976
#define NOTE_C7  2093

#include <string.h>
#include <stdio.h>
#include <ros.h>
#include <std_msgs/UInt16MultiArray.h>

const int l_speed = 10;
const int l_motor = 12;
const int r_speed = 11;
const int r_motor = 13;
const int buzzer = 4;
//const int led = 5;


void Motor(char lm, int ls, char rm, int rs) {

//    Buzzer(0);
    digitalWrite(l_motor, lm);
    digitalWrite(r_motor, rm);
    analogWrite(l_speed, ls);
    analogWrite(r_speed, rs);
    delay(1);
}


void controller (const std_msgs::UInt16MultiArray keystroke) {
    int l = keystroke.data[0];
    int ls = keystroke.data[1];
    int r = keystroke.data[2];
    int rs = keystroke.data[3];

    char lm;
    char rm;
    if (l == 0) {
        lm = HIGH;
    } else {
        lm = LOW;
    }
    if (r == 0) {
        rm = HIGH;
    } else {
        rm = LOW;
    }

//    ROS_INFO("ls: %d, rs: %d", ls, rs);

    Motor(lm, ls, rm, rs);
    delay(1);
}


void Buzzer(int condition) {
    switch (condition) {
        default:
            //            tone(buzzer, NOTE_B0, 100);
        case 0:
            tone(buzzer, NOTE_C4, 100);
            delay(100);
//            tone(buzzer, NOTE_C7, 100);
//            delay(100);
        case 1:

            delay(250);

            delay(250);
        case 2:
            delay(250);
            delay(250);
    }
}


void Led() {
}

ros::NodeHandle nh;
ros::Subscriber <std_msgs::UInt16MultiArray> sub("controller", controller);


void setup() {
    pinMode(r_speed, OUTPUT);
    pinMode(r_motor, OUTPUT);
    pinMode(l_speed, OUTPUT);
    pinMode(l_motor, OUTPUT);
    pinMode(buzzer, OUTPUT);
//  pinMode(led, OUTPUT);

    nh.initNode();
    nh.subscribe(sub);
}


void loop() {
    nh.spinOnce();
    delay(1);
}
