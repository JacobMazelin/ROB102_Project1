#include <iostream>
#include <cmath>

#include <mbot_bridge/robot.h>

#include <mbot_lib/behaviors.h>
#include <mbot_lib/controllers.h>
#include <mbot_lib/utils.h>
#include <vector>

using namespace std;

bool ctrl_c_pressed;
void ctrlc(int)
{
    ctrl_c_pressed = true;
}


int main(){
    // Initialize the robot.
    mbot_bridge::MBot robot;
    // Reset the robot odometry to zero at the beginning of the run.
    robot.resetOdometry();

    // *** Task: Get the goal pose (x, y, theta) from the user *** //
    float goal_x, goal_y, goal_theta;

    cout << "Enter x: ";
    cin>>goal_x;
    cout << "Enter y: ";
    cin>>goal_y;
    cout << "Enter theta in degrees: ";
    cin>>goal_theta;
    goal_theta = goal_theta * (M_PI / 180); //Convert to radians
    vector<float> goal = {goal_x, goal_y, goal_theta};

    // *** End student code *** //
    
    while (true) {
        
        // *** Task: Implement hit the spot *** //
        
        vector<float> driveCommand = computeDriveToPoseCommand(goal, robot.readOdometry());
        if(goal[0] - robot.readOdometry()[0] < 0.05 && goal[1] - robot.readOdometry()[1] < 0.05){
            robot.stop();
            robot.drive(0,0,goal[2]-robot.readOdometry()[2]);
            if(goal[2] - robot.readOdometry()[2] < 0.2) break;
        }
        else {
        robot.drive(driveCommand[0], driveCommand[1], driveCommand[2]);
        }
        cout << "X: " << goal[0] - robot.readOdometry()[0] << "\n";
        cout << "Y: " << goal[1] - robot.readOdometry()[1] << "\n";
        cout << "Theta: " << goal[2] - robot.readOdometry()[2] << "\n";
        // *** End student code *** //
        
        if (ctrl_c_pressed) break;
    }
    

    // Stop the robot before exiting.
    robot.stop();

    // *** Task: Print out the robot's final odometry pose *** //
    
    // *** End student code *** //

    return 0;
}
