#include "TriangleDecorator.h"
#define _USE_MATH_DEFINES
#include <math.h>

const string TO_STRING_PREFIX = "TRIANGLE: ";

TriangleDecorator::TriangleDecorator(unique_ptr<sf::Shape> shape)
	:ShapeDecorator(std::move(shape))
{}

size_t TriangleDecorator::getPointCount() const {
	return m_decoratee->getPointCount();
}
sf::Vector2f TriangleDecorator::getPoint(size_t index) const {
	return m_decoratee->getPoint(index);
}

void TriangleDecorator::setPointCount(size_t count) {
	static_cast<sf::ConvexShape*>(m_decoratee.get())->setPointCount(count);
}

void TriangleDecorator::setPoint(size_t index, const sf::Vector2f& point) {
	static_cast<sf::ConvexShape*>(m_decoratee.get())->setPoint(index, point);
}

double TriangleDecorator::getVectorLength(sf::Vector2f p1, sf::Vector2f p2) const {
	auto x = p2.x - p1.x;
	auto y = p2.y - p1.y;
	return sqrt((x * x) + (y * y));
}

double TriangleDecorator::getArea() const {
	auto semiperimeter = getPerimeter() / 2;
	auto side1 = getVectorLength(m_decoratee->getPoint(0), m_decoratee->getPoint(1));
	auto side2 = getVectorLength(m_decoratee->getPoint(1), m_decoratee->getPoint(2));
	auto side3 = getVectorLength(m_decoratee->getPoint(2), m_decoratee->getPoint(0));
	return sqrt(semiperimeter * (semiperimeter - side1) * (semiperimeter - side2) * (semiperimeter - side3));
}
double TriangleDecorator::getPerimeter() const {
	auto side1 = getVectorLength(m_decoratee->getPoint(0), m_decoratee->getPoint(1));
	auto side2 = getVectorLength(m_decoratee->getPoint(1), m_decoratee->getPoint(2));
	auto side3 = getVectorLength(m_decoratee->getPoint(2), m_decoratee->getPoint(0));
	return side1 + side2 + side3;
}

string TriangleDecorator::toString() const {
	return TO_STRING_PREFIX + "P=" + to_string((int)getPerimeter()) + "; S=" + to_string((int)getArea());
}
sf::FloatRect TriangleDecorator::getGlobalBounds() const {
	return (*m_decoratee).getGlobalBounds();
}
void TriangleDecorator::move(float offsetX, float offsetY) {
	(*m_decoratee).move(offsetX, offsetY);
}