/**
 * File: follow_2d.cpp
 *
 * Controls the robot to maintain a given distance to the nearest wall.
 *
 * This code finds the distance to the nearest wall in the Lidar scan. It
 * applies a control to the robot in the direction of the wall using the angle
 * to the scan.
 */

#include <cmath>
#include <iostream>

#include <signal.h>

#include <mbot_bridge/robot.h>

#include <mbot_lib/controllers.h>
#include <mbot_lib/utils.h>


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
    // We will store the Lidar scan data in these vectors.
    std::vector<float> ranges;
    std::vector<float> thetas;

    // *** Task 1: Adjust these values appropriately ***
    float setpoint = 0.325;  // The goal distance from the wall in meters
    float tolerance = 0.1;
    float scaling =  0.3; 
    float kP = -1;
    float maxVelocity = 0.4;

    // *** End student code *** //

    while (true) {
        // This function gets the Lidar scan data.
        robot.readLidarScan(ranges, thetas);

        // Get the distance to the wall.
        float min_idx = findMinNonzeroDist(ranges);
        float dist_to_wall = ranges[min_idx];
        float angle_to_wall = thetas[min_idx];

        std::cout << min_idx << ", Distance to wall: " << dist_to_wall << "\n";

        float velocity = pControl(dist_to_wall, setpoint, kP);
    
        if (velocity > maxVelocity) {
            velocity = maxVelocity;
        } else if (velocity < -maxVelocity){
            velocity = -maxVelocity;
        } else {
            velocity = velocity;
        }

        std::vector<float> velocities = rayConversionCartisean(velocity, angle_to_wall);

        robot.drive(velocities[0], velocities[1], 0);

        // *** End Student Code ***

        if (ctrl_c_pressed) break;
    }

    // Stop the robot.
    robot.stop();
    return 0;
}