#include "ShapeSummaryPrintVisitor.h"
#include "CircleDecorator.h"
#include "RectangleDecorator.h"
#include "TriangleDecorator.h"
#include <iostream>
#include <stdexcept>

string ShapeSummaryPrintVisitor::OUTPUT_ERROR = "Output Error: could not open ";

ShapeSummaryPrintVisitor::ShapeSummaryPrintVisitor(std::string fileToWrite) {
    m_output.open(fileToWrite);
    if (!m_output.is_open()) {
        cout << OUTPUT_ERROR << fileToWrite << endl;
        throw std::exception("output error");
    }
}
ShapeSummaryPrintVisitor::~ShapeSummaryPrintVisitor() {
    m_output.close();
}

void ShapeSummaryPrintVisitor::visit(const CircleDecorator& circle) {
    m_output << circle.toString() << endl;
}
void ShapeSummaryPrintVisitor::visit(const RectangleDecorator& rectangle) {
    m_output << rectangle.toString() << endl;
}
void ShapeSummaryPrintVisitor::visit(const TriangleDecorator& triangle) {
    m_output << triangle.toString() << endl;
}