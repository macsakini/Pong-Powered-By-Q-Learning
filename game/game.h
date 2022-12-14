#pragma once

#include <iostream>

class Game
{
public:
    Game(int window_x, int window_y);
    void updateBall();
    void updatePaddle();
    void bounceBack();
    void detectCrash();
    void loop();
};