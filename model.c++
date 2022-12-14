#include <iostream>
#include "Eigen/Dense"
#include "model/linear.h"

#define log(x) std::cout << x << std ::endl;
#define shape(x) std::cout << "(" << x.rows() << "," << x.cols() << ")" << std ::endl;

using namespace std;
using Eigen::exp;
using Eigen::MatrixXd;

void runModel(int state_space, int action_space)

{
    // Number and size
    MatrixXd x = MatrixXd::Random(state_space, 784);
    MatrixXd y = MatrixXd::Random(state_space, 1);
    MatrixXd data = x.transpose();

    // Hidden_DIM , DATA_SIZE
    Linear l1 = Linear(512, 784);
    MatrixXd l1_out = l1.forward(data);

    // Your hidden dimension for previous layer is your data size for new layer
    Linear l2 = Linear(72, 512);
    MatrixXd l2_out = l2.forward(l1_out.cwiseMax(0));

    Linear l3 = Linear(action_space, 72);
    MatrixXd l3_out = l3.forward(l2_out.cwiseMax(0));

    shape(l3_out);
    log(l3_out);

    // Baackprpagation

    // float dz2 = (pred - y.transpose()).sum();

    // float dw2 = 1 / 5 * (dz2 * l3_out.transpose()).sum();
    // float db2 = dz2;

    // float dz1 = (l3.getWeights().transpose() * dz2).sum();
    // float dw1 = 1.5 * (dz1 * data.transpose()).sum();
    // float db1 = dz1;

    // log(dw2);
    // log(dw2);

    // log(dz2);
    // log(dz1);

    // Update Weights

    // MatrixXd w1_n = l2.getWeights() - 0.95 * dw1;
    // MatrixXd b1_n = l2.getBias() - 0.95 * db1;

    // MatrixXd w2_n = l3.getWeights() - 0.95 * dw2;
    // MatrixXd b2_n = l3.getBias() - 0.95 * db2;
}

// int main()
// {
//     runModel(5, 3);
// }