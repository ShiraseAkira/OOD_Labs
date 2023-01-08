#include "TriangleCreator.h"
#include <sstream>

TriangleCreator* TriangleCreator::m_Creator = nullptr;

TriangleCreator* TriangleCreator::GetInstance() {
	if (m_Creator == nullptr) {
		m_Creator = new TriangleCreator();
	}
	return m_Creator;
}

unique_ptr<sf::Shape> TriangleCreator::CreateShape(string& shapeDescription) {
	istringstream iss(getShapeNumbersDescription(shapeDescription));
	float skip;
	sf::Vector2f p1, p2, p3;
	iss >> skip >> p1.x >> p1.y >> skip >> p2.x >> p2.y >> skip >> p3.x >> p3.y;

	sf::ConvexShape triangle;
	triangle.setPointCount(3);
	triangle.setPoint(0, p1);
	triangle.setPoint(1, p2);
	triangle.setPoint(2, p3);

	return make_unique<sf::ConvexShape>(triangle);
}