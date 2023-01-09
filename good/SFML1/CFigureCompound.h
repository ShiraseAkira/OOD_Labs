#pragma once
#include "CFigureMovementDecorator.h"
using namespace std;
using namespace sf;

class CFigureCompound: public CFigureMovementDecorator {
public:
	void Add(CFigureMovementDecorator* figure);
	void SetPosition(float x, float y) const override;
	void SetFillColor(Color color) const override;
	void Draw(RenderWindow& window) const override;
	FloatRect GetGlobalBounds() const override;
	Vector2f GetPosition() const override;
	vector<CFigureMovementDecorator*> GetFigures() const;
private:
	vector<CFigureMovementDecorator*> m_figures;
};