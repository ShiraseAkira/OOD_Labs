#include "CircleDecorator.h"
#include "RectangleDecorator.h"
#include "TriangleDecorator.h"
#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;

int main()
{
    sf::RenderWindow window(sf::VideoMode(400, 400), "SFML works!");

    CircleDecorator circle(make_unique<sf::CircleShape>(100.f));
    RectangleDecorator rect(make_unique<sf::RectangleShape>(sf::Vector2f(10, 20)));

    circle.setFillColor(sf::Color::Green);
    //circle.setPosition({ 0, 20 });

    TriangleDecorator triangle(make_unique<sf::ConvexShape>());
    triangle.setPointCount(3);
    triangle.setPoint(0, { 0, 0 });
    triangle.setPoint(1, { 100, 0 });
    triangle.setPoint(2, { 0, 100 });
    triangle.setFillColor(sf::Color::Red);
    triangle.setPosition({ 100, 100 });

    cout << circle.ToString() << endl << rect.ToString() << endl
        << triangle.ToString() << endl;

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
        window.draw(rect);
        window.draw(triangle);
        window.display();
    }

    return 0;
}