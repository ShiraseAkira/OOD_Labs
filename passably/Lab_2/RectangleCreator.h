#pragma once
#include "IShapeCreator.h"
class RectangleCreator :
    public IShapeCreator
{
public:
	static RectangleCreator* getInstance();
	RectangleCreator(RectangleCreator& other) = delete;
	void operator=(const RectangleCreator&) = delete;
	unique_ptr<sf::Shape> createShape(string& shapeDescription) override;

protected:
	RectangleCreator() = default;
	static RectangleCreator* m_Creator;
};
