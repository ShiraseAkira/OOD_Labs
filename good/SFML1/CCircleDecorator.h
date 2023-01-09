#pragma once
#include "CFigureDecorator.h"

class CCircleDecorator : public CFigureDecorator {
public:
	CCircleDecorator(CircleShape* circle);
	string GetDescription() const override;
	void SetRadius(float r) const;
private:
	CircleShape* m_circle;

	float GetPerimeter() const override;
	float GetSquare() const override;
};