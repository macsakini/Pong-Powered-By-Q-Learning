#include <iostream>
#include "SFML/Graphics.hpp"

using namespace std;
using namespace sf;
#define log(x) std::cout << x << std::endl;

int main()
{
    RenderWindow window(VideoMode(800, 800), "Pong");

    // Ball
    CircleShape shape(20.f);
    shape.setFillColor(Color::Red);

    // Paddle
    RectangleShape rectangle(Vector2f(120.f, 50.f));
    rectangle.setFillColor(Color::White);
    rectangle.setPosition(360.f, 750.f);

    // Game loop
    while (window.isOpen())
    {
        Event event;

        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();

            if (event.type == Event::KeyPressed)
            {
                Vector2f pos = rectangle.getPosition();

                if (Keyboard::isKeyPressed(Keyboard::Left))

                    rectangle.move(1.f, 0.f);

                if (Keyboard::isKeyPressed(Keyboard::Right))

                    rectangle.move(0.f, 1.f);
            };
        }

        window.clear();

        window.draw(shape);

        window.draw(rectangle);

        window.display();
    }

    return 0;
}
