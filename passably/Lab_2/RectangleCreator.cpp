#include "RectangleCreator.h"
#include <sstream>

RectangleCreator* RectangleCreator::m_Creator = nullptr;

RectangleCreator* RectangleCreator::GetInstance() {
	if (m_Creator == nullptr) {
		m_Creator = new RectangleCreator();
	}
	return m_Creator;
}

unique_ptr<sf::Shape> RectangleCreator::CreateShape(string& shapeDescription) {
	istringstream iss(getShapeNumbersDescription(shapeDescription));
	float x1, y1, x2, y2, skip;
	iss >> skip >> x1 >> y1 >> skip >> x2 >> y2;

	sf::RectangleShape rectangle;
	rectangle.setPosition(x1, y1);
	rectangle.setSize(sf::Vector2f(x2 - x1, y2 - y1));

	return make_unique<sf::RectangleShape>(rectangle);
}