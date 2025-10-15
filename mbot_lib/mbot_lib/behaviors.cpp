/**
 * File: behaviors.cpp
 * 
 * Sources for high level functions that determine how the robot should move.
 */

#include <mbot_lib/behaviors.h>


std::vector<float> computeWallFollowerCommand(const std::vector<float>& ranges, const std::vector<float>& thetas)
{
    // *** Task: Implement this function according to the header file *** //
    float setpoint = 0.325;  // The goal distance from the wall in meters
    float tolerance = 0.1;
    float scaling =  0.3; 
    float kP = -0.5;
    float maxVelocity = 0.4;

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

    std::vector<float> v_to_wall = rayConversionCartesian(0.5, angle_to_wall);
    std::vector<float> v_up = {0,0,1};

    std::vector<float> v_forward = crossProduct(v_to_wall, v_up);
    std::vector<float> correction_vector = rayConversionCartesian(velocity, angle_to_wall);
    std::vector<float> final_command = {v_forward[0] + correction_vector[0], v_forward[1] + correction_vector[1]};
    return final_command;
    // *** End student code *** //
}

std::vector<float> computeDriveToPoseCommand(const std::vector<float>& goal, const std::vector<float>& pose)
{   
    // *** Task: Implement this function according to the header file *** //
    float dx = goal[0] - pose[0];
    float dy = goal[1] - pose[1];
    float velocity = sqrt(dx*dx + dy*dy);
    dx = 0.5* (dx / velocity);
    dy = 0.5* (dy / velocity);
    float dtheta = normalizeAngle(pose[2]);
    std::vector<float> error = {dx, dy};
    transformVector2D(error, dtheta);
    // float k_x = 0.2;
    // float k_y = 0.2;
    // float k_theta = 1;

    if(sqrt(dtheta*dtheta) < M_PI /22) dtheta = 0;

    float v_x = error[0];
    float v_y = error[1];

    return {v_x, v_y, 1.5* dtheta};

    // *** End student code *** //
}

bool isGoalAngleObstructed(const std::vector<float>& goal, const std::vector<float>& pose,
                           const std::vector<float>& ranges, const std::vector<float>& thetas)
{
    // *** Task: Implement this function according to the header file *** //
    float min_dist = findMinNonzeroDistInSlice(ranges, thetas, goal[2], M_PI/4);
    if(min_dist > 0.05){
        return true;
    }else {
        return false;
    }
    //static int findMinNonzeroDistInSlice(const std::vector<float>& ranges, const std::vector<float>& thetas,
     //                                float target_angle, float slice_size)
    return false;

    // *** End student code *** //
}