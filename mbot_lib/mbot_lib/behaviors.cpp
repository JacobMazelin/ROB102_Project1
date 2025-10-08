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
    float dx = goal[0] - pose[0];
    float dy = goal[1] - pose[1];
    float velocity = sqrt(dx*dx + dy*dy);
    dx = dx / velocity;
    dy = dy / velocity;
    float dtheta = normalizeAngle(pose[2]);
    std::vector<float> error = {dx, dy};
    transformVector2D(error, dtheta);
    // float k_x = 0.2;
    // float k_y = 0.2;
    // float k_theta = 1;
    float v_x = error[0];
    float v_y = error[1];
    float theta = error[2];

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