/**
 * File: utils.cpp
 * 
 * Sources for functions for handling common tasks like working with geometry and interpreting lidar data.
 */

#include <mbot_lib/utils.h>


std::vector<float> rayConversionCartisean(float dist, float angle) 
{
    // *** Task: Implement this function according to the header file *** //
    float vx = cos(angle) * dist;
    float vy = sin(angle) * dist;

    return {vx, vy, 0};

    // *** End student code *** //
}

std::vector<float> rayConversionVector(float angle) 
{
    // *** Task: Implement this function according to the header file *** //

    return std::vector<float>(angle, angle, angle);

    // *** End student code *** //
}

int findMinDist(const std::vector<float>& ranges)
{
    // *** Task: Implement this function according to the header file *** //
    for(int i=0; i<ranges.size; i++){
        if (ranges[i] < ranges[i+1]){
            float minimum = i;
        }
    }
    return minimum;
    return -1;

    // *** End student code *** //
}

int findMinNonzeroDist(const std::vector<float>& ranges)
{
    // *** Task: Implement this function according to the header file *** //
    for(int i=0; i<ranges.size; i++){
        if(ranges[i] == 0){
            continue;
        } else if (ranges[i] < ranges[i+1]){
            float minimum = i;
        }
    }
    return minimum;
    
    // *** End student code *** //
}

std::vector<float> vectorAdd(const std::vector<float>& v1, const std::vector<float>& v2) 
{
    // *** Task: Implement this function according to the header file *** //

    return std::vector<float>();

    // *** End student code *** //
}

std::vector<float> crossProduct(const std::vector<float>& v1, const std::vector<float>& v2) 
{
    // *** Task: Implement this function according to the header file *** //

    return std::vector<float>();

    // *** End student code *** //
}

void transformVector2D(std::vector<float>& xy, float theta) 
{
    // *** Task: Implement this function according to the header file *** //

    // *** End student code *** //
}
