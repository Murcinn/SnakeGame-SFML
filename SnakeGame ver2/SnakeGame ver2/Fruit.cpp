#include"Fruit.h"
#include <iostream>
#include <vector>

Fruit::Fruit(sf::Vector2f position, sf::Texture* texture): Unit(position,texture)
{
	this->ifCollide = false;

	
	int ranX = ((rand() % 28 + 1) * 32) + 16;
	int ranY = ((rand() % 28 + 1) * 32) + 16;
	this->setPos(sf::Vector2f(ranX, ranY));
	

}

Fruit::~Fruit()
{
}

void Fruit::update(double deltaTime)
{
	
		if (this->ifCollide == true) {

			
				//max 912 min 48
				int ranX = ((rand() % 28 + 1) * 32) + 16;
				int ranY = ((rand() % 28 + 1) * 32) + 16;

				//std::cout << ranX << " " << ranY << "\n";

				Unit::setPos(sf::Vector2f(ranX, ranY));
				this->ifCollide = false;

			
		}
	
}



void Fruit::setCollide(bool newCol)
{
	this->ifCollide = newCol;
}
