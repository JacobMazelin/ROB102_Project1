#include <cmath>
#include <iostream>
#include <signal.h>

#include <mbot_bridge/robot.h>

#include <mbot_lib/behaviors.h>
#include <mbot_lib/controllers.h>
#include <mbot_lib/utils.h>
using namespace std;

bool ctrl_c_pressed;
void ctrlc(int) {
    ctrl_c_pressed = true;
}


int main() {
    signal(SIGINT, ctrlc);
    signal(SIGTERM, ctrlc);

    // Initialize the robot.
    mbot_bridge::MBot robot;
    // Reset the robot odometry to zero.
    robot.resetOdometry();

    float goal_x, goal_y, goal_theta;

    cout << "Enter x: ";
    cin>>goal_x;
    cout << "Enter y: ";
    cin>>goal_y;
    cout << "Enter theta in degrees: ";
    cin>>goal_theta;
    goal_theta = goal_theta * (M_PI / 180); //Convert to radians
    vector<float> goal = {goal_x, goal_y, goal_theta};

    vector<float> ranges;
    vector<float> thetas;
    vector<float> pose;
    vector<float> wall_follower;
    vector<float> drive_to_pose;

    pose = {0, 0, 0};

    // *** Task: Get the goal pose (x, y, theta) from the user *** //

    // *** End student code *** //

    // *** Task: Implement bug navigation finite state machine *** //

    
    // NOTE: You may want to change the condition in this loop.
    while (true) {

        robot.readLidarScan(ranges, thetas);
        pose = robot.readOdometry();

        if(isGoalAngleObstructed(goal, pose, ranges, thetas)){
            wall_follower = computeWallFollowerCommand(ranges, thetas);
            robot.drive(wall_follower[0], wall_follower[1], 0);
            cout << "Wall Follower Enabled\n";
        }
        else {
            drive_to_pose = computeDriveToPoseCommand(goal, robot.readOdometry());
            robot.drive(drive_to_pose[0], drive_to_pose[1], 0); //TODO
            cout << "Drive to Pose Enabled\n";
        }
        if(goal[0] - pose[0] < 0.05 && goal[1] - pose[1] < 1){
            cout << "Done\n";
            break;
        }
        if(ctrl_c_pressed) break;
        cout << "\nX: " << pose[0] << " Y: " << pose[1] << " Theta: " << pose[2];
    }

    // *** End student code *** //
    cout << "\nFinal X: " << pose[0] << " Final Y: " << pose[1] << " Final Theta: " << pose[2];
    // Stop the robot.
    robot.stop();

    // *** Task: Print out the robot's final odometry pose *** //
    
    // *** End student code *** //
}
