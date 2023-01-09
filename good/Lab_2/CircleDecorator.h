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
	sf::FloatRect getGlobalBounds() const;
	void move(float offsetX, float offsetY);

	double getArea() const;
	double getPerimeter() const;
	string toString() const;
};

