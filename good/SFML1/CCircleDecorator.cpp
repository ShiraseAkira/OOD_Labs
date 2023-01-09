#include "CCircleDecorator.h"
#define _USE_MATH_DEFINES
#include <math.h>

const string circle = "CIRCLE: ";

CCircleDecorator::CCircleDecorator(CircleShape* circle)
	:m_circle(circle),
	CFigureDecorator(move(circle)) {}

void CCircleDecorator::SetRadius(float r) const {
	m_circle->setRadius(r);
}

float CCircleDecorator::GetPerimeter() const {
	return 2 * M_PI * m_circle->getRadius();
}

float CCircleDecorator::GetSquare() const {
	float radius = m_circle->getRadius();
	return M_PI * radius * radius;
}

string CCircleDecorator::GetDescription() const {
	return circle + " P=" + to_string(GetPerimeter()) + "; S=" + to_string(round(GetSquare()));
}