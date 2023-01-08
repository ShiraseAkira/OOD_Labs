#pragma once
#include "IShapeCreator.h"

class CircleCreator:
	public IShapeCreator
{
public:
	static CircleCreator *getInstance();
	CircleCreator(CircleCreator&) = delete;
	void operator=(const CircleCreator&) = delete;
	unique_ptr<sf::Shape> createShape(string& shapeDescription) override;
	
protected:
	CircleCreator() = default;
	static CircleCreator* m_Creator;
};
