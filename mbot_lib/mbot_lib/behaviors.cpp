/**
 * File: behaviors.cpp
 * 
 * Sources for high level functions that determine how the robot should move.
 */

#include <mbot_lib/behaviors.h>


std::vector<float> computeWallFollowerCommand(const std::vector<float>& ranges, const std::vector<float>& thetas)
{
    // *** Task: Implement this function according to the header file *** //
    
    return std::vector<float>();

    // *** End student code *** //
}

std::vector<float> computeDriveToPoseCommand(const std::vector<float>& goal, const std::vector<float>& pose)
{   
    // *** Task: Implement this function according to the header file *** //
    float error_pose_x = goal[0] - pose[0];
    float error_pose_y = goal[1] - pose[1];
    std::vector<float> error = {error_pose_x, error_pose_y};
    transformVector2D(error, pose[2]);
    float k_x = 0.2;
    float k_y = 0.2;
    float k_theta = 1;
    float v_x = k_x*pose[0];
    float v_y = k_y*pose[1];
    float theta = k_theta*pose[2];

    return {v_x, v_y, theta};

    // *** End student code *** //
}

bool isGoalAngleObstructed(const std::vector<float>& goal, const std::vector<float>& pose,
                           const std::vector<float>& ranges, const std::vector<float>& thetas)
{
    // *** Task: Implement this function according to the header file *** //

    return false;

    // *** End student code *** //
}