#pragma once

#include "iostream"
#include "Eigen/Dense"
#include "model/linear.h"

using Eigen::MatrixXd;

class Model
{

public:
    int state_space;
    int action_space;
    Model(int state_space, int action_space);
    MatrixXd forward(MatrixXd x);
    void backpropagation();
    void optimize();
    void loss();
};
