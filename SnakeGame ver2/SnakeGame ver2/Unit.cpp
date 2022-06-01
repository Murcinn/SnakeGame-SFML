
#include "Unit.h"

Unit::Unit(sf::Vector2f position, sf::Texture* texture)
{
	this->body.setSize(sf::Vector2f(32, 32));
	this->body.setOrigin(this->body.getSize().x / 2.0f, this->body.getSize().y / 2.0f);
	this->body.setPosition(position);
	this->body.setTexture(texture);

	this->col = new Collider(&this->body);
}

Unit::~Unit()
{
	delete col;
}


sf::Vector2f Unit::getPos()
{
	return this->body.getPosition();
}

sf::RectangleShape Unit::getSha()
{
	return body;
}

sf::Vector2f Unit::getSiz()
{
	return body.getSize();
}

sf::RectangleShape Unit::getBody()
{
	return body;
}

void Unit::setPos(sf::Vector2f newPosition)
{
	this->body.setPosition(newPosition);
}

void Unit::setSiz(sf::Vector2f newSize)
{
	this->body.setSize(newSize);
}

void Unit::draw(sf::RenderWindow* window)
{
	window->draw(this->body);
}

Collider Unit::getCollider()
{
	return *col;
}