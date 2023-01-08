#include "RectangleDecorator.h"
#define _USE_MATH_DEFINES
#include <math.h>

const string TO_STRING_PREFIX = "RECTANGLE: ";

RectangleDecorator::RectangleDecorator(unique_ptr<sf::Shape> shape)
	:ShapeDecorator(std::move(shape))
{}

size_t RectangleDecorator::getPointCount() const {
	return m_decoratee->getPointCount();
}
sf::Vector2f RectangleDecorator::getPoint(size_t index) const {
	return m_decoratee->getPoint(index);
}

double RectangleDecorator::GetArea() const {
	auto size = static_cast<sf::RectangleShape*>(m_decoratee.get())->getSize();
	return round(size.x * size.y);
}
double RectangleDecorator::GetPerimeter() const {
	auto size = static_cast<sf::RectangleShape*>(m_decoratee.get())->getSize();
	return round((size.x + size.y) * 2);
}

string RectangleDecorator::ToString() const {
	return TO_STRING_PREFIX + "P=" + to_string((int)GetPerimeter()) + "; S=" + to_string((int)GetArea());
}