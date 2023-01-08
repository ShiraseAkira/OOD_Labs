#pragma once
#include "ShapeDecorator.h"

class TriangleDecorator :
    public ShapeDecorator
{
public:
	TriangleDecorator(unique_ptr<sf::Shape> shape);
	virtual size_t getPointCount() const;
	virtual sf::Vector2f getPoint(size_t index) const;
	void setPointCount(size_t count);
	void setPoint(size_t index, const sf::Vector2f& point);

	double GetArea() const;
	double GetPerimeter() const;
	string ToString() const;

	double GetVectorLength(sf::Vector2f p1, sf::Vector2f p2) const;
};

