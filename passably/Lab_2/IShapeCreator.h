#pragma once
#include <SFML/Graphics.hpp>
#include <memory>
#include <string>
using namespace std;

class IShapeCreator
{
public:
	virtual unique_ptr<sf::Shape> CreateShape(string& shapeDescription) = 0;
protected:
	string getShapeNumbersDescription(string& shapeDescription);
};

