#include <iostream>
#include "agent.h"
#include "game.h"
#include "model.h"
#include "Eigen/Dense"

#define log(x) std::cout << x << std::endl;

#define shape(x) std::cout << "(" << x.rows() << "," << x.cols() << ")" << std ::endl;

using Eigen::exp;
using Eigen::Matrix;
using Eigen::MatrixXd;
using Eigen::MatrixXf;

using namespace std;

void train_dqn()
{
    Game game;
    Model model = Model(4, 1);

    int episodes = 10;
    int max_steps = 1000;

    for (int i = 1; i <= episodes; i++)
    {
        State st = game.reset();

        for (int j; j <= max_steps; j++)
        {
            // // int lb = 0, ub = 2;
            double ballposx = static_cast<double>(st.ballposx);
            double ballposy = static_cast<double>(st.ballposy);
            double xvel = static_cast<double>(st.xvel);
            double yvel = static_cast<double>(st.yvel);

            Matrix<double, 1, 4> m;

            m << ballposx, ballposy, xvel, yvel;

            MatrixXd action = model.forward(m);

            log(action);

            game.step(1);

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
