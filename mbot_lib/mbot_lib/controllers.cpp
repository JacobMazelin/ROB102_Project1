/**
 * File: controllers.cpp
 *
 * Sources for feedback controllers.
 */

#include <mbot_lib/controllers.h>
#include <iostream>


float bangBangControl(float current, float setpoint, float scaling, float tolerance)
{
    // *** Task: Implement this function according to the header file *** //
    float error = setpoint - current;
    if (error > tolerance){
        std::cout<<"Error: Greater"<<error<<std::endl;
        return -scaling;
    } else if (error < -tolerance){
        std::cout<<"Error: Less Negative "<<error<<std::endl;
        return scaling;
    }

    return 0;

    // *** End student code *** //
}

float pControl(float current, float setpoint, float kp)
{
    // *** Task: Implement this function according to the header file *** //
    float error = setpoint - current;
    if (std::abs(error) > 0.01){
        return kp * error;
    }
    return 0;

    // *** End student code *** //
}