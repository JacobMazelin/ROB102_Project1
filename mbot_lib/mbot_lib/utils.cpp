/**
 * File: utils.cpp
 * 
 * Sources for functions for handling common tasks like working with geometry and interpreting lidar data.
 */

#include <mbot_lib/utils.h>


std::vector<float> rayConversionCartesian(float dist, float angle) 
{
    // *** Task: Implement this function according to the header file *** //
    float vx = cos(angle) * dist;
    float vy = sin(angle) * dist;
    std::vector<float> vect = {vx,vy};
    return vect;

    // *** End student code *** //
}

std::vector<float> rayConversionVector(float angle) 
{
    // *** Task: Implement this function according to the header file *** //
    float x = cos(angle);
    float y = sin(angle);
    float z = 0;
    return {x, y, z};

    // *** End student code *** //
}

int findMinDist(const std::vector<float>& ranges)
{
    float minimum = HIGH;
    int min_idx = 0;
    // *** Task: Implement this function according to the header file *** //
    for(int i=0; i<ranges.size(); ++i){
        if(ranges[i] < minimum && ranges[i] >= 0){
            min_idx = i;
            minimum = ranges[i];
        }
    }
    return min_idx;

    // *** End student code *** //
}

int findMinNonzeroDist(const std::vector<float>& ranges)
{
    // *** Task: Implement this function according to the header file *** //
    float minimum = HIGH;
    int min_idx = 0;
    // *** Task: Implement this function according to the header file *** //
    for(int i=0; i<ranges.size(); ++i){
        if(ranges[i] < minimum && ranges[i] > 0){
            min_idx = i;
            minimum = ranges[i];
        }
    }
    return min_idx;
    
    // *** End student code *** //

}

std::vector<float> vectorAdd(const std::vector<float>& v1, const std::vector<float>& v2) 
{
    // *** Task: Implement this function according to the header file *** //
    std::vector<float> result;
    for(int i=0; i<v1.size(); i++){
        result.push_back(v1[i] + v2[i]);
    }

    return result;

    // *** End student code *** //
}

std::vector<float> crossProduct(const std::vector<float>& v1, const std::vector<float>& v2) 
{
    // *** Task: Implement this function according to the header file *** //
    return {v1[1]*v2[2]-v1[2]*v2[1], v1[2]*v2[0]-v1[0]*v2[2], v1[0]*v2[1]-v1[1]*v2[0]};

    // *** End student code *** //
}

void transformVector2D(std::vector<float>& xy, float theta) 
{
    // *** Task: Implement this function according to the header file *** //
    float vx_world = xy[0];
    float vy_world = xy[1];
    xy[0] = vx_world * cos(theta) + vy_world * sin(theta);
    xy[1] = -vx_world * sin(theta) + vy_world * cos(theta);
    // *** End student code *** //
}
