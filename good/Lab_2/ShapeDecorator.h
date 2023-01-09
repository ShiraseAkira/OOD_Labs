#pragma once
#include <memory>
#include <string>

#include <SFML/Graphics.hpp>

using namespace std;

class ShapeDecorator :
	public sf::Shape
{
public:
	ShapeDecorator(unique_ptr<sf::Shape> shape);
	virtual ~ShapeDecorator() = default;


	void setTexture(const sf::Texture* texture, bool resetRect = false);
	void setTextureRect(const sf::IntRect& rect);
	void setFillColor(const sf::Color& color);
	void setOutlineColor(const sf::Color& color);
	void setOutlineThickness(float thickness);
	const sf::Texture* getTexture() const;
	const sf::IntRect& getTextureRect() const;
	const sf::Color& getFillColor() const;
	const sf::Color& getOutlineColor() const;
	float getOutlineThickness() const;
	sf::FloatRect getLocalBounds() const;
	sf::FloatRect getGlobalBounds() const;

	void draw(sf::RenderTarget& window, sf::RenderStates state) const;


	void setPosition(float x, float y);
	void setPosition(const sf::Vector2f& position);
	void setRotation(float angle);
	void setScale(float factorX, float factorY);
	void setScale(const sf::Vector2f& factors);
	void setOrigin(float x, float y);
	void setOrigin(const sf::Vector2f& origin);
	const sf::Vector2f& getPosition() const;
	float getRotation() const;
	const sf::Vector2f& getScale() const;
	const sf::Vector2f& getOrigin() const;
	void move(float offsetX, float offsetY);
	void move(const sf::Vector2f& offset);
	void rotate(float angle);
	void scale(float factorX, float factorY);
	void scale(const sf::Vector2f& factor);
	const sf::Transform& getTransform() const;
	const sf::Transform& getInverseTransform() const;


	virtual double getArea() const = 0;
	virtual double getPerimeter() const = 0;
	virtual string toString() const = 0;

	void setSelected(bool);
	bool isSelected() const;

protected:
	unique_ptr<sf::Shape> m_decoratee;
	bool m_selected;
};

