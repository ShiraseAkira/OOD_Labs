#pragma once
#include "IShapeCreator.h"
class TriangleCreator :
    public IShapeCreator
{
public:
	static TriangleCreator* getInstance();
	TriangleCreator(TriangleCreator& other) = delete;
	void operator=(const TriangleCreator&) = delete;
	unique_ptr<sf::Shape> createShape(string& shapeDescription) override;

protected:
	TriangleCreator() = default;
	static TriangleCreator* m_Creator;
};
