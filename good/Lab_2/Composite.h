#pragma once
#include <memory>
#include <string>
#include <list>

#include <SFML/Graphics.hpp>

#include "ShapeDecorator.h"

using namespace std;

class Composite :
	public ShapeDecorator
{
public:
	Composite();
	void add(ShapeDecorator* shape);
	void remove(ShapeDecorator* shape);
	void setPosition(float x, float y);
	void draw(sf::RenderTarget& window, sf::RenderStates state) const;
	sf::FloatRect getGlobalBounds() const;
	const sf::Vector2f& getPosition() const;

	virtual double getArea() const;
	virtual double getPerimeter() const;
	virtual string toString() const;
	virtual size_t getPointCount() const;
	virtual sf::Vector2f getPoint(size_t index) const;
	void move(float offsetX, float offsetY);

	list<ShapeDecorator*> getShapes() const;
private:
	list<ShapeDecorator*> m_shapes;
};