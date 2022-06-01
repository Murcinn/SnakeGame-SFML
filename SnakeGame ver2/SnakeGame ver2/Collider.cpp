#include "Collider.h"

Collider::Collider(sf::RectangleShape* shape): body(shape)
{
	
}

Collider::~Collider()
{
}

bool Collider::checkCollision(const Collider& colEl)
{

	sf::Vector2f deltaDistance(this->getPos() - colEl.getPos());

	sf::Vector2f halfSize(this->getHalfSize() + colEl.getHalfSize());

	if (abs(deltaDistance.x) - halfSize.x < 0 && abs(deltaDistance.y) - halfSize.y < 0) {
	
		return true;

	}
	return false;
}

sf::Vector2f Collider::getHalfSize() const
{
	return sf::Vector2f(body->getSize().x/2.0f,body->getSize().y/2.0f);
}

sf::Vector2f Collider::getPos() const
{
	return sf::Vector2f(body->getPosition());
}
