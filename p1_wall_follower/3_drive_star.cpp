/**
 * File: drive_star.cpp
 *
 * Code to drive in a five-pointed star shape without turning. 
 */

#include <iostream>
#include <cmath>

#include <signal.h>

#include <mbot_bridge/robot.h>

#include <mbot_lib/utils.h>
using namespace std;

bool ctrl_c_pressed;
void ctrlc(int)
{
    ctrl_c_pressed = true;
}


int main(int argc, const char *argv[])
{
    signal(SIGINT, ctrlc);
    signal(SIGTERM, ctrlc);

    // Initialize the robot.
    mbot_bridge::MBot robot;

    // *** Task: Drive in a five pointed star *** //
    robot.drive(0.5, 0, 0);
    sleepFor(1.5);
    
    for(int i=1; i<=4; i++) {
    cout << "x: " << rayConversionCartisean(0.5, -144*M_PI/180)[0] << "y" << rayConversionCartisean(0.5, -144*M_PI/180)[1]<< "\n";
    robot.drive(rayConversionCartisean(0.5, -144*i*M_PI/180)[0],rayConversionCartisean(0.5, -144*i*M_PI/180)[1],0);
    sleepFor(1.5);
    
    // cout << "x: " << rayConversionCartisean(0.5, 144*M_PI/180)[0] << "y" << rayConversionCartisean(0.5, 144*M_PI/180)[1] << "\n";
    // robot.drive(rayConversionCartisean(0.5, -144*2*M_PI/180)[0],rayConversionCartisean(0.5, -144*2*M_PI/180)[1],0);
    // sleepFor(1.5);
    
    // robot.drive(rayConversionCartisean(0.5, -144*3*M_PI/180)[0],rayConversionCartisean(0.5, -144*3*M_PI/180)[1],0);
    // sleepFor(1.5);
    
    // robot.drive(rayConversionCartisean(0.7, -144*4*M_PI/180)[0],rayConversionCartisean(0.7, -144*4*M_PI/180)[1],0);
    // sleepFor(1.5);
    }
    

    // *** End student code *** //

    // Stop the robot.
    robot.stop();
    return 0;
}