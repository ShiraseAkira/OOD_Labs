#include <fstream>
#include <sstream>
#include <iostream> 
#include <algorithm>
#include <list>

#include <SFML/Graphics.hpp>

#include "CircleDecorator.h"
#include "RectangleDecorator.h"
#include "TriangleDecorator.h"
#include "Composite.h"

using namespace std;

const string DEFAULT_OUTPUT_FILENAME = "output.txt";
const string CIRCLE_PREFIX = "CIRCLE:";
const string RECTANGLE_PREFIX = "RECTANGLE:";
const string TRIANGLE_PREFIX = "TRIANGLE:";

const string ARGUMENT_COUNT_ERROR = "invalid argument count\nusage: <executable>"
                                    " <input_file> | uses default output.txt\n"
                                    "or : <executable> <input_file> <output_file>"
                                    " | uses default output.txt";

const string INPUT_ERROR = "Input Error: could not open ";
const string OUTPUT_ERROR = "Output Error: could not open ";
const string WINDOW_TITLE = "Figures visualisation";


int main(int argc, char* argv[])
{
    if (argc < 2 || argc > 3) {
        cout << ARGUMENT_COUNT_ERROR << endl;
        return 1;
    }

    ifstream input;
    input.open(argv[1]);
    if (!input.is_open()) {
        cout << INPUT_ERROR << argv[1] << endl;
        return 1;
    }

    string fileToOpen = (argc == 2) ? DEFAULT_OUTPUT_FILENAME : argv[2];    
    ofstream output;
    output.open(fileToOpen);
    if (!output.is_open()) {
        cout << OUTPUT_ERROR << fileToOpen << endl;
        return 1;
    }

    sf::RenderWindow window(sf::VideoMode(800, 600), WINDOW_TITLE);

    Composite shapes;

    string line;
    while (getline(input, line)) {
        istringstream iss(line);
        string figureType;
        iss >> figureType;
        replace_if(line.begin(), 
            line.end(),
            [](unsigned char c) { return std::isalpha(c) || std::ispunct(c); },
            ' ');

        if (figureType == CIRCLE_PREFIX) {
            istringstream iss(line);
            float x, y, r;
            iss >> x >> y >> r;

            CircleDecorator* circle = new CircleDecorator(make_unique<sf::CircleShape>());
            circle->setPosition(x - r, y - r);
            circle->setRadius(r);
            circle->setFillColor(sf::Color::Blue);

            shapes.add(circle);
            output << circle->toString() << endl;
        }
        else if (figureType == RECTANGLE_PREFIX) {
            istringstream iss(line);
            float x1, y1, x2, y2, skip;
            iss >> skip >> x1 >> y1 
                >> skip >> x2 >> y2;

            RectangleDecorator* rectangle = new RectangleDecorator(make_unique<sf::RectangleShape>());
            rectangle->setPosition(x1, y1);
            rectangle->setSize(sf::Vector2f(x2 - x1, y2 - y1));
            rectangle->setFillColor(sf::Color::Magenta);

            shapes.add(rectangle);
            output << rectangle->toString() << endl;
        }
        else if (figureType == TRIANGLE_PREFIX) {
            istringstream iss(line);
            float skip;
            sf::Vector2f p1, p2, p3;
            iss >> skip >> p1.x >> p1.y 
                >> skip >> p2.x >> p2.y 
                >> skip >> p3.x >> p3.y;

            TriangleDecorator* triangle = new TriangleDecorator(make_unique<sf::ConvexShape>());
            triangle->setPointCount(3);
            triangle->setPoint(0, p1);
            triangle->setPoint(1, p2);
            triangle->setPoint(2, p3);
            triangle->setFillColor(sf::Color::Cyan);

            shapes.add(triangle);
            output << triangle->toString() << endl;
        }

    }

    bool isLmbPressedOnShape = false;
    list<ShapeDecorator*> selectedShapes;
    sf::Vector2i mousePressPosition(0, 0);
    while (window.isOpen()) {
        sf::Vector2i mousePosition = sf::Mouse::getPosition(window);

        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();

        
            if (event.type == sf::Event::MouseButtonPressed
                && event.key.code == sf::Mouse::Left) {
                for (auto shape : shapes.getShapes()) {
                    if (shape->getGlobalBounds().contains((float)mousePosition.x, (float)mousePosition.y)) {
                        isLmbPressedOnShape = true;
                        mousePressPosition = sf::Mouse::getPosition(window);

                        if (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift)) {
                            if (!shape->isSelected()) {
                                shape->setSelected(true);
                                selectedShapes.push_back(shape);
                            }
                        }
                        else {
                            if (!shape->isSelected()) {
                                shape->setSelected(true);
                                selectedShapes.clear();
                                selectedShapes.push_back(shape);
                                for (auto shapeToRemoveSelection : shapes.getShapes()) {
                                    if (shapeToRemoveSelection != shape)
                                        shapeToRemoveSelection->setSelected(false);
                                }
                            }
                        }
                    }
                }

                if (!isLmbPressedOnShape) {
                    for (auto shape : shapes.getShapes()) {
                        shape->setSelected(false);
                    }
                }
            }

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::LControl))
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::G)) {
                    if (!selectedShapes.empty()) {
                        Composite* compoundFigure = new Composite();
                        for (auto shape : selectedShapes) {
                            compoundFigure->add(shape);
                            shape->setSelected(false);
                            shapes.remove(shape);
                        }
                        selectedShapes.clear();
                        compoundFigure->setSelected(true);
                        shapes.add(compoundFigure);
                    }

                }

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::LControl))
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::U)) {
                    if (selectedShapes.size() == 1 && static_cast<Composite*>(selectedShapes.front())) {
                        Composite* compoundFigure = dynamic_cast<Composite*>(selectedShapes.front());
                        list<ShapeDecorator*> shapesCompound = compoundFigure->getShapes();
                        shapes.remove(compoundFigure);
                        for (auto shape : shapesCompound) {
                            shapes.add(shape);
                        }
                    }
                }


            if (event.type == sf::Event::MouseButtonReleased
                && event.key.code == sf::Mouse::Left) {
                isLmbPressedOnShape = false;
            }
        }

        if (isLmbPressedOnShape) {
            sf::Vector2i mouseCurrentPosition = sf::Mouse::getPosition(window);
            for (auto shape : shapes.getShapes()) {
                if (shape->isSelected()) {
                    shape->move(mouseCurrentPosition.x - mousePressPosition.x,
                        mouseCurrentPosition.y - mousePressPosition.y);
                }
            }
            mousePressPosition = mouseCurrentPosition;
        }

        window.clear();
        for (auto shape : shapes.getShapes()) {
            window.draw(*shape);
        }
        window.display();
    }

    input.close();
    output.close();

    return 0;
}