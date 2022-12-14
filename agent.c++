#include <iostream>
#include "agent.h"
#include "model.h"

#define log(x) std::cout << x << std::endl;
using namespace std;

Agent::Agent(int state_space, int action_space)
{
    state_space = state_space;
    action_space = action_space;
};

// Allows agent to take action
void Agent::act()
{
    runModel(state_space, action_space);
};

// Store Trajectory in Queue
void Agent::remember(struct Trajectory t)
{
    memory.push_back(t);
};

// Policy Gradient Method
int Agent::learn()
{
    return 0;
};
