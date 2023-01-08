#include <fstream>
#include <sstream>
#include <iostream> 
#include <algorithm>

#include <SFML/Graphics.hpp>

#include "CircleDecorator.h"
#include "CircleCreator.h"
#include "RectangleDecorator.h"
#include "RectangleCreator.h"
#include "TriangleDecorator.h"
#include "TriangleCreator.h"
#include "ShapeSummaryPrintVisitor.h"

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

    string fileToWrite = (argc == 2) ? DEFAULT_OUTPUT_FILENAME : argv[2];
    ShapeSummaryPrintVisitor* printVisitor;
    try {
         printVisitor = new ShapeSummaryPrintVisitor(fileToWrite);
    }
    catch (const std::exception&) {
        return 1;
    }


    sf::RenderWindow window(sf::VideoMode(800, 600), WINDOW_TITLE);
    
    CircleCreator* circleCreator = CircleCreator::getInstance();
    RectangleCreator* rectangleCreator = RectangleCreator::getInstance();
    TriangleCreator* triangleCreator = TriangleCreator::getInstance();

    string line;
    while (getline(input, line)) {
        istringstream iss(line);
        string figureType;
        iss >> figureType;

        if (figureType == CIRCLE_PREFIX) {
            CircleDecorator circle(circleCreator->createShape(line));
            printVisitor->visit(circle);
            window.draw(circle);            
        }
        else if (figureType == RECTANGLE_PREFIX) {
            RectangleDecorator rectangle(rectangleCreator->createShape(line));
            printVisitor->visit(rectangle);
            window.draw(rectangle);
        }
        else if (figureType == TRIANGLE_PREFIX) {
            TriangleDecorator triangle(triangleCreator->createShape(line));
            printVisitor->visit(triangle);
            window.draw(triangle);
        }

    }
    window.display();

    input.close();

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }
    }

    return 0;
}