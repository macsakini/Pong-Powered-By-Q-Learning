#pragma once

#include "iostream"
#include "Eigen/Dense"

struct Trajectory
{
    float state[5];
    float action;
    float reward;
    float next_state[5];
    float done;
};

void runModel(int state_space, int action_space);