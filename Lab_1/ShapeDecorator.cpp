#include "ShapeDecorator.h"
ShapeDecorator::ShapeDecorator(unique_ptr<sf::Shape> shape)
	:m_decoratee(std::move(shape))
{}



void ShapeDecorator::setTexture(const sf::Texture* texture, bool resetRect) {
	(*this->m_decoratee).setTexture(texture, resetRect);
}

void ShapeDecorator::setTextureRect(const sf::IntRect& rect) {
	(*this->m_decoratee).setTextureRect(rect);
}

void ShapeDecorator::setFillColor(const sf::Color& color) {
	(*this->m_decoratee).setFillColor(color);
}

void ShapeDecorator::setOutlineColor(const sf::Color& color) {
	(*this->m_decoratee).setOutlineColor(color);
}

void ShapeDecorator::setOutlineThickness(float thickness) {
	(*this->m_decoratee).setOutlineThickness(thickness);
}

const sf::Texture* ShapeDecorator::getTexture() const {
	return (*this->m_decoratee).getTexture();
}

const sf::IntRect& ShapeDecorator::getTextureRect() const {
	return (*this->m_decoratee).getTextureRect();
}

const sf::Color& ShapeDecorator::getFillColor() const {
	return (*this->m_decoratee).getFillColor();
}

const sf::Color& ShapeDecorator::getOutlineColor() const {
	return (*this->m_decoratee).getOutlineColor();
}

float ShapeDecorator::getOutlineThickness() const {
	return (*this->m_decoratee).getOutlineThickness();
}

sf::FloatRect ShapeDecorator::getLocalBounds() const {
	return (*this->m_decoratee).getLocalBounds();
}

sf::FloatRect ShapeDecorator::getGlobalBounds() const {
	return (*this->m_decoratee).getGlobalBounds();
}


void ShapeDecorator::draw(sf::RenderTarget& window, sf::RenderStates state) const {
	window.draw(*this->m_decoratee);
}




void ShapeDecorator::setPosition(float x, float y) {
	(*this->m_decoratee).setPosition(x, y);
}

void ShapeDecorator::setPosition(const sf::Vector2f& position) {
	(*this->m_decoratee).setPosition(position);
}

void ShapeDecorator::setRotation(float angle) {
	(*this->m_decoratee).setRotation(angle);
}

void ShapeDecorator::setScale(float factorX, float factorY) {
	(*this->m_decoratee).setScale(factorX, factorY);
}

void ShapeDecorator::setScale(const sf::Vector2f& factors) {
	(*this->m_decoratee).setScale(factors);
}

void ShapeDecorator::setOrigin(float x, float y) {
	(*this->m_decoratee).setOrigin(x, y);
}

void ShapeDecorator::setOrigin(const sf::Vector2f& origin) {
	(*this->m_decoratee).setOrigin(origin);
}

const sf::Vector2f& ShapeDecorator::getPosition() const {
	return (*this->m_decoratee).getPosition();
}

float ShapeDecorator::getRotation() const {
	return (*this->m_decoratee).getRotation();
}

const sf::Vector2f& ShapeDecorator::getScale() const {
	return (*this->m_decoratee).getScale();
}

const sf::Vector2f& ShapeDecorator::getOrigin() const {
	return (*this->m_decoratee).getOrigin();
}

void ShapeDecorator::move(float offsetX, float offsetY) {
	(*this->m_decoratee).move(offsetX, offsetY);
}

void ShapeDecorator::move(const sf::Vector2f& offset) {
	(*this->m_decoratee).move(offset);
}

void ShapeDecorator::rotate(float angle) {
	(*this->m_decoratee).rotate(angle);
}

void ShapeDecorator::scale(float factorX, float factorY) {
	(*this->m_decoratee).scale(factorX, factorY);
}

void ShapeDecorator::scale(const sf::Vector2f& factor) {
	(*this->m_decoratee).scale(factor);
}

const sf::Transform& ShapeDecorator::getTransform() const {
	return (*this->m_decoratee).getTransform();
}

const sf::Transform& ShapeDecorator::getInverseTransform() const {
	return (*this->m_decoratee).getInverseTransform();
}