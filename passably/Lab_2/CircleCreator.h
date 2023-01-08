#pragma once
#include "IShapeCreator.h"

class CircleCreator:
	public IShapeCreator
{
public:
	static CircleCreator *GetInstance();
	CircleCreator(CircleCreator& other) = delete;
	void operator=(const CircleCreator&) = delete;
	unique_ptr<sf::Shape> CreateShape(string& shapeDescription) override;
	
protected:
	CircleCreator() = default;
	static CircleCreator* m_Creator;
};

