#include "ShapeDecorator.h"
ShapeDecorator::ShapeDecorator(unique_ptr<sf::Shape> shape)
	:m_decoratee(std::move(shape))
	,m_selected(false)
{}



void ShapeDecorator::setTexture(const sf::Texture* texture, bool resetRect) {
	(*m_decoratee).setTexture(texture, resetRect);
}

void ShapeDecorator::setTextureRect(const sf::IntRect& rect) {
	(*m_decoratee).setTextureRect(rect);
}

void ShapeDecorator::setFillColor(const sf::Color& color) {
	(*m_decoratee).setFillColor(color);
}

void ShapeDecorator::setOutlineColor(const sf::Color& color) {
	(*m_decoratee).setOutlineColor(color);
}

void ShapeDecorator::setOutlineThickness(float thickness) {
	(*m_decoratee).setOutlineThickness(thickness);
}

const sf::Texture* ShapeDecorator::getTexture() const {
	return (*m_decoratee).getTexture();
}

const sf::IntRect& ShapeDecorator::getTextureRect() const {
	return (*m_decoratee).getTextureRect();
}

const sf::Color& ShapeDecorator::getFillColor() const {
	return (*m_decoratee).getFillColor();
}

const sf::Color& ShapeDecorator::getOutlineColor() const {
	return (*m_decoratee).getOutlineColor();
}

float ShapeDecorator::getOutlineThickness() const {
	return (*m_decoratee).getOutlineThickness();
}

sf::FloatRect ShapeDecorator::getLocalBounds() const {
	return (*m_decoratee).getLocalBounds();
}

sf::FloatRect ShapeDecorator::getGlobalBounds() const {
	return (*m_decoratee).getGlobalBounds();
}


void ShapeDecorator::draw(sf::RenderTarget& window, sf::RenderStates state) const {
	if (isSelected()) {
		sf::FloatRect bounds = getGlobalBounds();
		sf::RectangleShape frame;
		frame.setSize(sf::Vector2f(bounds.width, bounds.height));
		frame.setPosition(sf::Vector2f(bounds.left, bounds.top));
		frame.setFillColor(sf::Color::Transparent);
		frame.setOutlineThickness(1);
		frame.setOutlineColor(sf::Color::White);
		window.draw(frame);
	}
	window.draw(*m_decoratee);
}


void ShapeDecorator::setPosition(float x, float y) {
	(*m_decoratee).setPosition(x, y);
}

void ShapeDecorator::setPosition(const sf::Vector2f& position) {
	(*m_decoratee).setPosition(position);
}

void ShapeDecorator::setRotation(float angle) {
	(*m_decoratee).setRotation(angle);
}

void ShapeDecorator::setScale(float factorX, float factorY) {
	(*m_decoratee).setScale(factorX, factorY);
}

void ShapeDecorator::setScale(const sf::Vector2f& factors) {
	(*m_decoratee).setScale(factors);
}

void ShapeDecorator::setOrigin(float x, float y) {
	(*m_decoratee).setOrigin(x, y);
}

void ShapeDecorator::setOrigin(const sf::Vector2f& origin) {
	(*m_decoratee).setOrigin(origin);
}

const sf::Vector2f& ShapeDecorator::getPosition() const {
	return (*m_decoratee).getPosition();
}

float ShapeDecorator::getRotation() const {
	return (*m_decoratee).getRotation();
}

const sf::Vector2f& ShapeDecorator::getScale() const {
	return (*m_decoratee).getScale();
}

const sf::Vector2f& ShapeDecorator::getOrigin() const {
	return (*m_decoratee).getOrigin();
}

void ShapeDecorator::move(float offsetX, float offsetY) {
	(*m_decoratee).move(offsetX, offsetY);
}

void ShapeDecorator::move(const sf::Vector2f& offset) {
	(*m_decoratee).move(offset);
}

void ShapeDecorator::rotate(float angle) {
	(*m_decoratee).rotate(angle);
}

void ShapeDecorator::scale(float factorX, float factorY) {
	(*m_decoratee).scale(factorX, factorY);
}

void ShapeDecorator::scale(const sf::Vector2f& factor) {
	(*m_decoratee).scale(factor);
}

const sf::Transform& ShapeDecorator::getTransform() const {
	return (*m_decoratee).getTransform();
}

const sf::Transform& ShapeDecorator::getInverseTransform() const {
	return (*m_decoratee).getInverseTransform();
}

void ShapeDecorator::setSelected(bool selected) {
	m_selected = selected;
}

bool ShapeDecorator::isSelected() const {
	return m_selected;
}
