#include "CircleDecorator.h"
#include "CircleCreator.h"
#include "RectangleDecorator.h"
#include "RectangleCreator.h"
#include "TriangleDecorator.h"
#include "TriangleCreator.h"
#include <SFML/Graphics.hpp>
#include <fstream>
#include <sstream>
#include <iostream> 
#include <algorithm>

using namespace std;

const string DEFAULT_OUTPUT_FILENAME = "output.txt";
const string CIRCLE_PREFIX = "CIRCLE:";
const string RECTANGLE_PREFIX = "RECTANGLE:";
const string TRIANGLE_PREFIX = "TRIANGLE:";

const string ARGUMENT_COUNT_ERROR = "invalid argument count\nusage: <executable> <input_file> | uses default output.txt\n"
    "or : <executable> <input_file> <output_file> | uses default output.txt";

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

    ofstream output;
    string fileToOpen = (argc == 2)
        ? DEFAULT_OUTPUT_FILENAME 
        : argv[2];
    output.open(fileToOpen);
    if (!output.is_open()) {
        cout << OUTPUT_ERROR << fileToOpen << endl;
        return 1;
    }

    sf::RenderWindow window(sf::VideoMode(800, 600), WINDOW_TITLE);
    
    CircleCreator* circleCreator = CircleCreator::GetInstance();
    RectangleCreator* rectangleCreator = RectangleCreator::GetInstance();
    TriangleCreator* triangleCreator = TriangleCreator::GetInstance();

    string line;
    while (getline(input, line)) {
        istringstream iss(line);
        string figureType;
        iss >> figureType;
        replace_if(line.begin(), line.end(), [](unsigned char c) { return std::isalpha(c) || std::ispunct(c); }, ' ');

        if (figureType == CIRCLE_PREFIX) {
            CircleDecorator circle(circleCreator->CreateShape(line));

            window.draw(circle);            
            output << circle.ToString() << endl;
        }
        else if (figureType == RECTANGLE_PREFIX) {
            RectangleDecorator rectangle(rectangleCreator->CreateShape(line));

            window.draw(rectangle);
            output << rectangle.ToString() << endl;
        }
        else if (figureType == TRIANGLE_PREFIX) {
            TriangleDecorator triangle(triangleCreator->CreateShape(line));

            window.draw(triangle);
            output << triangle.ToString() << endl;
        }

    }
    window.display();

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
    }

    return 0;
}