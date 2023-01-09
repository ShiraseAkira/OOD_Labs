#include "CFigureCompound.h"

void CFigureCompound::Add(CFigureMovementDecorator* figure) {
	auto figureLocal = figure;
	figureLocal->SetMoved(false);
	m_figures.push_back(figureLocal);
}

FloatRect CFigureCompound::GetGlobalBounds() const {
	auto defaultFrame = m_figures.at(0)->GetGlobalBounds();
	Vector2f minPoint;
	minPoint.x = defaultFrame.left;
	minPoint.y = defaultFrame.top;

	Vector2f maxPoint;
	maxPoint.x = defaultFrame.left + defaultFrame.width;
	maxPoint.y = defaultFrame.top + defaultFrame.height;

	for (CFigureMovementDecorator* figure : m_figures) {
		auto localFrame = figure->GetGlobalBounds();

		if (localFrame.left < minPoint.x)
			minPoint.x = localFrame.left;
		if (localFrame.top < minPoint.y)
			minPoint.y = localFrame.top;
		if (localFrame.left + localFrame.width > maxPoint.x)
			maxPoint.x = localFrame.left + localFrame.width;
		if (localFrame.top + localFrame.height > maxPoint.y)
			maxPoint.y = localFrame.top + localFrame.height;
	}

	return FloatRect(minPoint.x, minPoint.y, abs(maxPoint.x - minPoint.x), abs(maxPoint.y - minPoint.y));
}

Vector2f CFigureCompound::GetPosition() const {
	auto globalBounds = GetGlobalBounds();

	return Vector2f(globalBounds.left, globalBounds.top);
}

void CFigureCompound::SetPosition(float x, float y) const {
	Vector2f d;
	d.x = x - GetPosition().x;
	d.y = y - GetPosition().y;

	for (CFigureMovementDecorator* figure : m_figures)
		figure->SetPosition(figure->GetPosition().x + d.x, figure->GetPosition().y + d.y);
}

void CFigureCompound::SetFillColor(Color color) const {
	for (CFigureMovementDecorator* figure : m_figures)
		figure->SetFillColor(color);
}

void CFigureCompound::Draw(RenderWindow& window) const {
	if (GetMoved()) {
		FloatRect globalBounds = GetGlobalBounds();
		RectangleShape frame;
		frame.setSize(Vector2f(globalBounds.width, globalBounds.height));
		frame.setPosition(Vector2f(globalBounds.left, globalBounds.top));
		frame.setFillColor(sf::Color(0, 0, 0, 0));
		frame.setOutlineThickness(1);
		frame.setOutlineColor(Color::White);
		window.draw(frame);
		for (CFigureMovementDecorator* figure : m_figures)
			figure->Draw(window);
	}
	else
		for (CFigureMovementDecorator* figure : m_figures)
			figure->Draw(window);
}

vector<CFigureMovementDecorator*> CFigureCompound::GetFigures() const {
	return m_figures;
}