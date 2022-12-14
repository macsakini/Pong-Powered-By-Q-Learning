#pragma once

#include <iostream>

using namespace std;

class Layer
{
protected:
    string name;

public:
    void setName(string name)
    {
        name = name;
    };

    string getName()
    {
        return name;
    }
};