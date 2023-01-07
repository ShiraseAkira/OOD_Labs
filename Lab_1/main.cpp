#include "CircleDecorator.h"
#include <SFML/Graphics.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode(400, 400), "SFML works!");

    CircleDecorator circle(make_unique<sf::CircleShape>(100.f));

    circle.setFillColor(sf::Color::Green);

    circle.setPosition({ 0, 20 });

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(circle);
        window.display();
    }

    return 0;
}