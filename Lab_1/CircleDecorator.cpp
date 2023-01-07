#include "CircleDecorator.h"
#define _USE_MATH_DEFINES
#include <math.h>

CircleDecorator::CircleDecorator(unique_ptr<sf::Shape> shape)
	:ShapeDecorator(std::move(shape))
{}

size_t CircleDecorator::getPointCount() const {
	return this->m_decoratee->getPointCount();
}
sf::Vector2f CircleDecorator::getPoint(size_t index) const {
	return this->m_decoratee->getPoint(index);
}

double CircleDecorator::GetArea() const { 
	auto r = static_cast<sf::CircleShape*>(this->m_decoratee.get())->getRadius();
	return M_PI * r * r;
}
double CircleDecorator::GetPerimeter() const {
	auto r = static_cast<sf::CircleShape*>(this->m_decoratee.get())->getRadius();
	return 2 * M_PI * r;
}

string CircleDecorator::ToString() const { return "test"; }