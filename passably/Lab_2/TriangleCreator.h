#pragma once
#include "IShapeCreator.h"
class TriangleCreator :
    public IShapeCreator
{
public:
	static TriangleCreator* GetInstance();
	TriangleCreator(TriangleCreator& other) = delete;
	void operator=(const TriangleCreator&) = delete;
	unique_ptr<sf::Shape> CreateShape(string& shapeDescription) override;

protected:
	TriangleCreator() = default;
	static TriangleCreator* m_Creator;
};
