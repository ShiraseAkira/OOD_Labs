#pragma once
#include <string>
#include <memory>
#include <SFML/Graphics.hpp>
#include <math.h>
using namespace std;
using namespace sf;

class CFigureMovementDecorator {
public:
	virtual void SetPosition(float x, float y) const = 0;
	virtual void SetFillColor(Color color) const = 0;
	virtual void Draw(RenderWindow& window) const = 0;
	virtual FloatRect GetGlobalBounds() const = 0;
	virtual Vector2f GetPosition() const = 0;
	void SetMoved(bool isMoved);
	bool GetMoved() const;
private:
	bool m_isMoved;
};