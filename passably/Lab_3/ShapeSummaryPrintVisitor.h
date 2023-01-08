#pragma once
#include "IShapeVisitor.h"
#include <fstream>
#include <string>

class CircleDecorator;
class RectangleDecorator;
class TriangleDecorator;

class ShapeSummaryPrintVisitor :
	public IShapeVisitor
{
public:
	ShapeSummaryPrintVisitor(std::string);
	~ShapeSummaryPrintVisitor();
	void visit(const CircleDecorator&) override;
	void visit(const RectangleDecorator&) override;
	void visit(const TriangleDecorator&) override;
protected:
	std::ofstream m_output;
	static std::string OUTPUT_ERROR;
};
