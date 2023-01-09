#include "CCircleDecorator.h"
#include "CRectangleDecorator.h"
#include "CTriangleDecorator.h"
#include "CFigureCompound.h"
#include "CFigureMovementDecorator.h"
#include <fstream>
#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>
using namespace std;

const string triangle = "TRIANGLE";
const string circle = "CIRCLE";
const string rectangle = "RECTANGLE";
const string outputFileName = "output.txt";

int main(int argc, char* argv[])
{
	ifstream input(argv[1]);
	if (!input.is_open()) {
		cout << "errorInput" << endl;
		return 1;
	}
	ofstream output(outputFileName);
	string figure;

	RenderWindow window(sf::VideoMode(800, 600), "Visualization of shapes");
	window.setVerticalSyncEnabled(true);

	vector<CFigureMovementDecorator*> shapes;

	while (input >> figure) {
		if (figure == circle) {
			float x, y, r;
			input >> x >> y >> r;
			CCircleDecorator* circleDecorator = new CCircleDecorator(new CircleShape());
			circleDecorator->SetRadius(r);
			circleDecorator->SetPosition(x, y);
			circleDecorator->SetFillColor(Color::Blue);
			shapes.push_back(circleDecorator);
			output << circleDecorator->GetDescription() << endl;
		}

		if (figure == rectangle) {
			float x1, y1, x2, y2;
			input >> x1 >> y1 >> x2 >> y2;
			CRectangleDecorator* rectangleDecorator = new CRectangleDecorator(new RectangleShape());
			rectangleDecorator->SetSize(Vector2f(x2 - x1, y2 - y1));
			rectangleDecorator->SetPosition((x2 - x1) / 2, (y2 - y1) / 2);
			rectangleDecorator->SetFillColor(Color::Cyan);
			shapes.push_back(rectangleDecorator);
			output << rectangleDecorator->GetDescription() << endl;
		}

		if (figure == triangle) {
			sf::Vector2f point1, point2, point3;
			input >> point1.x >> point1.y >> point2.x >> point2.y >> point3.x >> point3.y;
			CTriangleDecorator* triangleDecorator = new CTriangleDecorator(new ConvexShape());
			triangleDecorator->SetPointCount(3);
			triangleDecorator->SetPoint(0, point1);
			triangleDecorator->SetPoint(1, point2);
			triangleDecorator->SetPoint(2, point3);
			triangleDecorator->SetPosition((point1.x + point2.x + point3.x) / 3, (point1.y + point2.y + point3.y) / 3);
			triangleDecorator->SetFillColor(Color::Red);
			shapes.push_back(move(triangleDecorator));
			output << triangleDecorator->GetDescription() << endl;
		}
	}

	int index = -1;
	float dX = 0;
	float dY = 0;
	vector<CFigureMovementDecorator*> selectedShapes;
	while (window.isOpen()) {
		Vector2i pos = Mouse::getPosition(window);

		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();

			if (Keyboard::isKeyPressed(sf::Keyboard::LShift)) {
				if (event.type == Event::MouseButtonPressed)
					if (event.key.code == Mouse::Left)
						for (size_t i = 0; i < shapes.size(); i++)
							if (shapes[i]->GetGlobalBounds().contains(pos.x, pos.y)) {
								shapes[i]->SetMoved(true);
								selectedShapes.push_back(shapes[i]);
							}
			}
			else if (event.type == Event::MouseButtonPressed) {
				if (event.key.code == Mouse::Left)
					for (size_t i = 0; i < shapes.size(); i++)
						if (shapes[i]->GetGlobalBounds().contains(pos.x, pos.y)) {
							if (shapes[i]->GetMoved()) {
								index = i;
								dX = pos.x - shapes[i]->GetPosition().x;
								dY = pos.y - shapes[i]->GetPosition().y;
							}
							else {
								index = i;
								shapes[i]->SetMoved(true);
								selectedShapes.clear();
								selectedShapes.push_back(shapes[i]);
								dX = pos.x - shapes[i]->GetPosition().x;
								dY = pos.y - shapes[i]->GetPosition().y;
								for (size_t j = 0; j < shapes.size(); j++)
									if (j != i)
										shapes[j]->SetMoved(false);
							}
						}
				if (event.key.code == Mouse::Right)
					for (size_t i = 0; i < shapes.size(); i++)
					{
						if (shapes[i]->GetGlobalBounds().contains(pos.x, pos.y)) {
							if (shapes[i]->GetMoved()) {
								shapes[i]->SetMoved(false);
								index = -1;
								vector<CFigureMovementDecorator*>::iterator it = find(selectedShapes.begin(), selectedShapes.end(), shapes[i]);
								if (it != selectedShapes.end())
									selectedShapes.erase(it);
							}
						}
					}
			}

			if (Keyboard::isKeyPressed(sf::Keyboard::LControl))
				if (Keyboard::isKeyPressed(sf::Keyboard::G)) {
					if (!selectedShapes.empty()) {
						CFigureCompound* compoundFigure = new CFigureCompound();
						for (CFigureMovementDecorator* figure : selectedShapes) {
							compoundFigure->Add(figure);
							vector<CFigureMovementDecorator*>::iterator itShapes = find(shapes.begin(), shapes.end(), figure);
							if (itShapes != shapes.end())
								shapes.erase(itShapes);
						}
						selectedShapes.clear();
						index = -1;
						shapes.push_back(compoundFigure);
					}
				}

			if (Keyboard::isKeyPressed(sf::Keyboard::LControl))
				if (Keyboard::isKeyPressed(sf::Keyboard::U)) {
					if (selectedShapes.size() == 1 && static_cast<CFigureCompound*>(selectedShapes.front())) {
						CFigureCompound* compoundFigure = dynamic_cast<CFigureCompound*>(selectedShapes.front());
						vector<CFigureMovementDecorator*> figures = compoundFigure->GetFigures();

						vector<CFigureMovementDecorator*>::iterator itShapes = find(shapes.begin(), shapes.end(), compoundFigure);
						if (itShapes != shapes.end())
							shapes.erase(itShapes);
						for (CFigureMovementDecorator* figure : figures) {
							shapes.push_back(figure);
						}
						selectedShapes.clear();
						index = -1;
					}
				}

			if (event.type == Event::MouseButtonReleased)
				if (event.key.code == Mouse::Left)
					index = -1;
		}

		if (index != -1 && shapes[index]->GetMoved())
			shapes[index]->SetPosition(pos.x - dX, pos.y - dY);

		window.clear();
		for (size_t i = 0; i < shapes.size(); i++)
		{
			shapes[i]->Draw(window);
		}
		window.display();
	}

	input.close();
	output.close();

	return 0;
}