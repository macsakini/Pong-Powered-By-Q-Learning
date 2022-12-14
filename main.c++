#include <iostream>
#include "agent.h"

#define log(x) std::cout << x << std::endl;

using namespace std;

int main()
{
    Agent ag = Agent(5, 2);
    Trajectory t = {{0.1, 0.5}, 0.1, 0.1, {0.1, 0.5}, 0.9};
    ag.remember(t);
    ag.act();
    // log(ag.memory);
    return 0;
}
