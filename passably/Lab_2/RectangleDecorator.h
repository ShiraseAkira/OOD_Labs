#pragma once
#include "ShapeDecorator.h"

class RectangleDecorator :
    public ShapeDecorator
{
public:
	RectangleDecorator(unique_ptr<sf::Shape> shape);
	virtual size_t getPointCount() const;
	virtual sf::Vector2f getPoint(size_t index) const;
	void setSize(const sf::Vector2f& size);
	const sf::Vector2f& getSize() const;

	double getArea() const;
	double getPerimeter() const;
	string toString() const;
};

