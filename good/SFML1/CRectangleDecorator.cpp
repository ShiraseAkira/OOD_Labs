#include "CRectangleDecorator.h";

const string rectangle = "RECTANGLE: ";

CRectangleDecorator::CRectangleDecorator(RectangleShape* rectangle)
	:m_rectangle(rectangle),
	CFigureDecorator(rectangle) {}

void CRectangleDecorator::SetSize(Vector2f size) const {
	m_rectangle->setSize(size);
}

float CRectangleDecorator::GetPerimeter() const {
	Vector2f size = m_rectangle->getSize();
	return (size.x + size.y) * 2;
}

float CRectangleDecorator::GetSquare() const {
	Vector2f size = m_rectangle->getSize();
	return size.x * size.y;
}

string CRectangleDecorator::GetDescription() const {
	return rectangle + "P=" + to_string(GetPerimeter()) + "; S=" + to_string(round(GetSquare()));
}