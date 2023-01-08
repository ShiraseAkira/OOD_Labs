#include "CircleCreator.h"
#include "ShapeSummaryPrintVisitor.h"
#include <sstream>

CircleCreator* CircleCreator::m_Creator = nullptr;

CircleCreator *CircleCreator::getInstance() {
	if (m_Creator == nullptr) {
		m_Creator = new CircleCreator();
	}
	return m_Creator;
}

unique_ptr<sf::Shape> CircleCreator::createShape(string& shapeDescription) {
	istringstream iss(getShapeNumbersDescription(shapeDescription));
	float x, y, r;
	iss >> x >> y >> r;

	sf::CircleShape circle;
	circle.setPosition(x - r, y - r);
	circle.setRadius(r);

	return make_unique<sf::CircleShape>(circle);
}