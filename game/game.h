#pragma once

#include <iostream>
#include "SFML/Graphics.hpp"

using namespace sf;

struct State
{
    float ballposx;
    float ballposy;
    float xvel;
    float yvel;
};

struct General
{
    State state;
    float reward;
    float done;
};

class Game
{

private:
    RenderWindow window;
    int lives;
    CircleShape ball;
    RectangleShape paddle;
    Vector2f ballPosition;
    Vector2f paddlePosition;
    float xVelocity;
    float yVelocity;

public:
    float reward;
    float done;

    Game();
    void moveLeft();
    void moveRight();
    General step(int action);
    State reset();
    void ballPhysics();
    void detectCrash();
    int run();
};