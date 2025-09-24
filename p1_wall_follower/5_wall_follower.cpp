/**
 * File: wall_follower.cpp
 *
 * Controls robot to follow a wall. 
 */

#include <iostream>
#include <cmath>

#include <signal.h>

#include <mbot_bridge/robot.h>

#include <mbot_lib/behaviors.h>
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
    // Create empty vectors to store the scan data.
    std::vector<float> ranges;
    std::vector<float> thetas;
    float setpoint = 0.325;  // The goal distance from the wall in meters
    float tolerance = 0.1;
    float scaling =  0.3; 
    float kP = -1;
    float maxVelocity = 0.4;

    while (true) {

        robot.readLidarScan(ranges, thetas);

        // Get the distance to the wall.
        float min_idx = findMinNonzeroDist(ranges);
        float dist_to_wall = ranges[min_idx];
        float angle_to_wall = thetas[min_idx];

        float velocity = pControl(dist_to_wall, setpoint, kP);
    
        if (velocity > maxVelocity) {
            velocity = maxVelocity;
        } else if (velocity < -maxVelocity){
            velocity = -maxVelocity;
        } else {
            velocity = velocity;
        }

        std::vector<float> v_to_wall = rayConversionCartisean(velocity, angle_to_wall);
        std::vector<float> v_up = {0,0,1};

        std::vector<float> v_forward = crossProduct(v_to_wall, v_up);
        std::vector<float>  correction_vector = //TODO
        std::vector<float> final_command = v_forward + correction_vector;
        robot.drive(v_forward[0], v_forward[1], 0);

        // *** End student code *** //

        if (ctrl_c_pressed) break;
    }

    // Stop the robot.
    robot.stop();
    return 0;
}
