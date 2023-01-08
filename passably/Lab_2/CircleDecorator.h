#pragma once
#include "ShapeDecorator.h"

class CircleDecorator :
	public ShapeDecorator
{
public:
	CircleDecorator(unique_ptr<sf::Shape> shape);
	virtual size_t getPointCount() const;
	virtual sf::Vector2f getPoint(size_t index) const;
	void setRadius(float radius);
	float getRadius() const;

	double GetArea() const;
	double GetPerimeter() const;
	string ToString() const;
};

