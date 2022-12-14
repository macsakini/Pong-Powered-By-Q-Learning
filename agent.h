#pragma once

#include <iostream>
#include <list>

using namespace std;

struct Trajectory
{
    float state[2];
    float action;
    float reward;
    float next_state[2];
    float done;
};

class Agent
{
public:
    int state_space;
    int action_space;

    list<Trajectory> memory;

    Agent(int state_space, int action_space);
    // Allows agent to take action
    void act();
    // Store Trajectory in Queue
    void remember(struct Trajectory t);
    // Policy Gradient Method
    int learn();
};