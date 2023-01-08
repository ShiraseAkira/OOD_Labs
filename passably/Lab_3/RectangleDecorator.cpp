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

void RectangleDecorator::setSize(const sf::Vector2f& size) {
	static_cast<sf::RectangleShape*>(m_decoratee.get())->setSize(size);
}

const sf::Vector2f& RectangleDecorator::getSize() const {
	return static_cast<sf::RectangleShape*>(m_decoratee.get())->getSize();
}

double RectangleDecorator::getArea() const {
	auto size = getSize();
	return round(size.x * size.y);
}
double RectangleDecorator::getPerimeter() const {
	auto size = getSize();
	return round((size.x + size.y) * 2);
}

string RectangleDecorator::toString() const {
	return TO_STRING_PREFIX + "P=" + to_string((int)getPerimeter()) + "; S=" + to_string((int)getArea());
}

void RectangleDecorator::accept(IShapeVisitor& visitor) const {
	visitor.visit(*this);
}