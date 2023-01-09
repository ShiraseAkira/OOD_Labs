#pragma once
#include "CFigureDecorator.h";

class CRectangleDecorator : public CFigureDecorator {
public:
	CRectangleDecorator(RectangleShape* rectangle);
	string GetDescription() const override;
	void SetSize(Vector2f size) const;
private:
	RectangleShape* m_rectangle;

	float GetPerimeter() const override;
	float GetSquare() const override;
};