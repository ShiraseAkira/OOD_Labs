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
	void add(ShapeDecorator* shape);
	void setPosition(float x, float y);
	void draw(sf::RenderTarget& window, sf::RenderStates state) const;
	sf::FloatRect getGlobalBounds() const;
	const sf::Vector2f& getPosition() const;

	list<ShapeDecorator*> getShapes() const;
private:
	list<ShapeDecorator*> m_shapes;
};