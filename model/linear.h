#pragma once

#include <iostream>
#include "layer.h"

using namespace std;
using Eigen::MatrixXd;

class Linear
{
protected:
    MatrixXd weights;
    MatrixXd bias;

public:
    Linear(int hidden_dim, int data_size)
    {
        weights = MatrixXd::Random(hidden_dim, data_size);
        bias = MatrixXd::Random(hidden_dim, 1);
    };

public:
    void setWeights(MatrixXd w)
    {
        weights = w;
    };

    MatrixXd getWeights()
    {
        return weights;
    };

    void setBias(MatrixXd b)
    {
        bias = b;
    };

    MatrixXd getBias()
    {
        return bias;
    };

public:
    MatrixXd forward(MatrixXd x)
    {
        return (weights * x);
    };
};