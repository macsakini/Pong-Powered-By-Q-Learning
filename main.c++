#include <iostream>
#include "agent.h"
#include "game.h"

#define log(x) std::cout << x << std::endl;

using namespace std;

void train_dqn()
{
    Game game;

    int episodes = 10;
    int max_steps = 1000;

    for (int i = 1; i <= episodes; i++)
    {
        State st = game.reset();
        for (int j; j <= max_steps; j++)
        {
            int lb = 0, ub = 2;
            General gen = game.step(rand() % (ub - lb + 1));
            if (gen.done == 1)
            {
                log("done");
                break;
            }
        }
    }
}
int main()
{
    train_dqn();
    return 0;
}
