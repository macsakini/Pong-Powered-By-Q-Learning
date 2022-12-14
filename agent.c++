#include <iostream>
#include "model.h"

#define log(x) std::cout << x << std::endl;
using namespace std;

class Agent
{
public:
    int state_space;
    int action_space;

    Agent(int state_space, int action_space)
    {
        state_space = state_space;
        action_space = action_space;
    };

    // Allows agent to take action
    void act()
    {
        runModel(state_space, action_space);
    };

    // Store Trajectory in Queue
    void remember()
    {
        Trajectory t = {};
    };

    // Policy Gradient Method
    void learn(){

    };
};