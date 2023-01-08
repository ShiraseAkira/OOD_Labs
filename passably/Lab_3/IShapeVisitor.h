#pragma once
class CircleDecorator;
class RectangleDecorator;
class TriangleDecorator;

class IShapeVisitor
{
public:
	virtual void visit(const CircleDecorator&) = 0;
	virtual void visit(const RectangleDecorator&) = 0;
	virtual void visit(const TriangleDecorator&) = 0;
	virtual ~IShapeVisitor() = default;
};
