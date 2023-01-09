#include "CFigureDecorator.h"

class CTriangleDecorator : public CFigureDecorator {
public:
	CTriangleDecorator(ConvexShape* triangle);
	string GetDescription() const override;
	void SetPointCount(size_t count) const;
	void SetPoint(size_t index, Vector2f point) const;
private:
	ConvexShape* m_triangle;

	float GetVectorLength(Vector2f point1, Vector2f point2) const;
	float GetPerimeter() const override;
	float GetSquare() const override;
};
