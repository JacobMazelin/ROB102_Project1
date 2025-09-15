/**
 * File: drive_square.cpp
 *
 * Code to drive in a square N times.
 */

#include <iostream>
#include <cmath>

#include <mbot_bridge/robot.h>

#include <mbot_lib/utils.h>


int main(int argc, const char *argv[])
{
    // Initialize the robot.
    mbot_bridge::MBot robot;

    // Variables to be tuned.
    float vel = 0.5;
    float dt = 3.0;
    int num_square = 3;
    // bool ctrl_c_pressed;
    // void ctrlc(int){
    //     ctrl_c_pressed = true;
    // }

    // *** Task: Write code to drive in a square three times *** //
    
    for (int i = 0; i<num_square; i++){
        robot.drive(vel, 0, 0);
        sleepFor(dt);
        robot.drive(0, vel, 0);
        sleepFor(dt);
        robot.drive(-vel, 0, 0);
        sleepFor(dt);
        robot.drive(0, -vel, 0);
        sleepFor(dt);
        std::cout << "Completed square " << i+1 << std::endl;
    //     if (ctrl_c_pressed){
    //         break;
    // }
    
}

    // *** End student code *** //

    // Stop the robot.
    std::cout << "Stopping the robot!!" << std::endl;
    robot.stop();
    return 0;
}
