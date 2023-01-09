#pragma once
#include "CFigureMovementDecorator.h"
using namespace std;
using namespace sf;

class CFigureDecorator : public CFigureMovementDecorator {
public:
	virtual string GetDescription() const = 0;
	void SetPosition(float x, float y) const override;
	void SetFillColor(Color color) const override;
	void Draw(RenderWindow& window) const override;
	FloatRect GetGlobalBounds() const override;
	Vector2f GetPosition() const override;
protected:
	Shape* m_shape;

	CFigureDecorator(Shape* shape);
	virtual float GetPerimeter() const = 0;
	virtual float GetSquare() const = 0;
};