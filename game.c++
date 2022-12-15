#include <iostream>
#include "game.h"
#include "SFML/Graphics.hpp"

using namespace std;
using namespace sf;
#define log(x) std::cout << x << std::endl;

Game::Game()
{
    lives = 0;
    window.create(VideoMode(800, 800), "My SFML Game" /* ... */);
    window.setFramerateLimit(60);

    // Ball
    ballPosition = Vector2f(260.f, 500.f);
    ball.setRadius(25.f);
    ball.setFillColor(Color::Red);
    ball.setPosition(ballPosition);

    // Paddle
    paddlePosition = Vector2f(360.f, 750.f);
    paddle.setSize(Vector2f(200.f, 70.f));
    paddle.setFillColor(Color::White);
    paddle.setPosition(paddlePosition);

    // Ball Velocity
    xVelocity = 3;
    yVelocity = 4;
};

// // Moves the paddle as instructured
void Game::moveLeft()
{
    paddle.move(5.f, 0.f);
    reward -= 0.1;
};

void Game::moveRight()
{
    paddle.move(-5.f, 0.f);
    reward -= 0.1;
};

// -----------------------------------AI CONTROL----------------------------------------------------
State Game::reset()
{

    ball.setPosition(Vector2f(260.f, 500.f));
    paddle.setPosition(Vector2f(360.f, 750.f));
    struct State s = {ball.getPosition().x, ball.getPosition().y, xVelocity, yVelocity};
    return s;
}

// Returns State and Ends Round
General Game::step(int action)
{
    reward = 0;
    done = 0;

    if (action == 0)
    {
        moveLeft();
    }
    if (action == 2)
    {
        moveRight();
    }

    run();

    struct State state = {ball.getPosition().x, ball.getPosition().y, xVelocity, yVelocity};
    struct General gen = {state, reward, done};
    return gen;
};

void Game::ballPhysics()
{
    // Ball Physics
    if (ballPosition.x < 0 || ballPosition.x > 800 - 40)
        xVelocity *= -1;
    if (ballPosition.y < 0 || ballPosition.y > 800 - 40)
        yVelocity *= -1;

    ballPosition.x += xVelocity;
    ballPosition.y += yVelocity;
    ball.setPosition(ballPosition);
}

void Game::detectCrash()
{
    // Detect Crash

    if (ball.getGlobalBounds().intersects(paddle.getGlobalBounds()))
    {
        xVelocity *= -1;
        yVelocity *= -1;
        reward += 3;
    }
    else
    {
        reward -= 3;
        done = 1;
    }

    ballPosition.x += xVelocity;
    ballPosition.y += yVelocity;
    ball.setPosition(ballPosition);
}

int Game::run()
{
    // Game loop
    window.isOpen();

    Event event;

    while (window.pollEvent(event))
    {
        if (event.type == Event::Closed)
            window.close();
    }

    ballPhysics();
    detectCrash();

    window.clear();
    window.draw(ball);
    window.draw(paddle);
    window.display();

    return 0;
};