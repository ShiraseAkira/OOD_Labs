#include "CircleDecorator.h"
#define _USE_MATH_DEFINES
#include <math.h>

const string TO_STRING_PREFIX = "CIRCLE: ";

CircleDecorator::CircleDecorator(unique_ptr<sf::Shape> shape)
	:ShapeDecorator(std::move(shape))
{}

size_t CircleDecorator::getPointCount() const {
	return m_decoratee->getPointCount();
}
sf::Vector2f CircleDecorator::getPoint(size_t index) const {
	return m_decoratee->getPoint(index);
}

void CircleDecorator::setRadius(float radius) {
	static_cast<sf::CircleShape*>(m_decoratee.get())->setRadius(radius);
}

float CircleDecorator::getRadius() const {
	return static_cast<sf::CircleShape*>(m_decoratee.get())->getRadius();
}

double CircleDecorator::GetArea() const { 
	auto r = getRadius();
	return round(M_PI * r * r);
}
double CircleDecorator::GetPerimeter() const {
	auto r = getRadius();
	return round(2 * M_PI * r);
}

string CircleDecorator::ToString() const { 
	return TO_STRING_PREFIX + "P=" + to_string((int)GetPerimeter()) + "; S=" + to_string((int)GetArea());
}