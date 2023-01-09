#include "Composite.h"
Composite::Composite() {};

void Composite::add(ShapeDecorator* shape) {
	m_shapes.push_back(shape);
}

void Composite::remove(ShapeDecorator* shape) {
	m_shapes.remove(shape);
}

void Composite::setPosition(float x, float y) {
	sf::Vector2f targetPosition(x, y);
	sf::Vector2f currentPosition = getPosition();
	sf::Vector2f offset = targetPosition - currentPosition;

	for (ShapeDecorator* shape : m_shapes) {
		sf::Vector2f shapePosition = shape->getPosition();
		shape->setPosition(shapePosition + offset);
	}
}

void Composite::draw(sf::RenderTarget& window, sf::RenderStates state) const {
	if (isSelected()) {
		sf::FloatRect bounds = getGlobalBounds();
		sf::RectangleShape frame;
		frame.setSize(sf::Vector2f(bounds.width, bounds.height));
		frame.setPosition(sf::Vector2f(bounds.left, bounds.top));
		frame.setFillColor(sf::Color::Transparent);
		frame.setOutlineThickness(1);
		frame.setOutlineColor(sf::Color::White);
		window.draw(frame);
	}
	for (ShapeDecorator* shape : m_shapes) {
		window.draw(*shape);
	}
}

sf::FloatRect Composite::getGlobalBounds() const {
	auto initialFrame = m_shapes.front()->getGlobalBounds();
	sf::Vector2f leftTop(initialFrame.left, initialFrame.top);
	sf::Vector2f rightBottom(leftTop.x + initialFrame.width,
							 leftTop.y + initialFrame.height);

	for (ShapeDecorator* shape : m_shapes) {
		auto shapeFrame = shape->getGlobalBounds();

		if (leftTop.x > shapeFrame.left)
			leftTop.x = shapeFrame.left;
		if (leftTop.y > shapeFrame.top)
			leftTop.y = shapeFrame.top;
		if (rightBottom.x < shapeFrame.left + shapeFrame.width)
			rightBottom.x = shapeFrame.left + shapeFrame.width;
		if (rightBottom.y < shapeFrame.top + shapeFrame.height)
			rightBottom.y = shapeFrame.top + shapeFrame.height;
	}

	return sf::FloatRect(leftTop.x, leftTop.y,
						abs(rightBottom.x - leftTop.x),
						abs(rightBottom.y - leftTop.y));
}

const sf::Vector2f& Composite::getPosition() const {
	auto bound = getGlobalBounds();
	return sf::Vector2f(bound.left, bound.top);
}

list<ShapeDecorator*> Composite::getShapes() const {
	return m_shapes;
}

void Composite::move(float offsetX, float offsetY) {
	for (ShapeDecorator* shape : m_shapes) {
		shape->move(offsetX, offsetY);
	}
}


double Composite::getArea() const {
	return 0;
}
double Composite::getPerimeter() const {
	return 0;
}
string Composite::toString() const {
	return "str";
}
size_t Composite::getPointCount() const {
	return 0;
}
sf::Vector2f Composite::getPoint(size_t index) const {
	return sf::Vector2f(0, 0);
}