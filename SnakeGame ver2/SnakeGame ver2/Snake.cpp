#include "Snake.h"

#include<iostream>

Snake::Snake(sf::Vector2f position, sf::Texture* texture): Unit(position,texture)
{
	this->dir = LEFT;

	this->snakeCounter = 0;

	this->growCounter = 0;

	this->tailTexture.loadFromFile("images/body.png");
		
	this->tailVec.push_back(new Tail(Unit::getPos(), texture));

}

Snake::~Snake()
{
	for (int i=0; i < tailVec.size(); i++) {
		delete tailVec[i];
	}
}

void Snake::draw(sf::RenderWindow* window)
{
	window->draw(Unit::getBody());

	for (int i = 1; i < tailVec.size(); i++) {
		
		window->draw(tailVec[i]->Unit::getBody());
		
	}

}


void Snake::update(double deltaTime)
{


	Snake::keyboardInput();
	

	if (snakeCounter >= 0.06)
	{
		

		if (this->dir == UP)
		{
			Unit::setPos(Unit::getPos() + sf::Vector2f(0, -32));
			
		}
		if (this->dir == RIGHT)
		{
			Unit::setPos(Unit::getPos() + sf::Vector2f(Unit::getSiz().x, 0));
		}
		if (this->dir == DOWN)
		{

			Unit::setPos(Unit::getPos() + sf::Vector2f(0, Unit::getSiz().y));
		}
		if (this->dir == LEFT)
		{
			Unit::setPos(Unit::getPos() + sf::Vector2f(-Unit::getSiz().x, 0));
		}
		
		snakeCounter = 0;
		this->followingTail();
	}
	
	snakeCounter += deltaTime;

	

}

void Snake::keyboardInput()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)&&this->dir!= DOWN)
	{
		dir = UP;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && this->dir != LEFT)
	{
		dir = RIGHT;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && this->dir != UP)
	{
		dir = DOWN;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && this->dir != RIGHT)
	{
		dir = LEFT;
	}

}

void Snake::followingTail()
{	

	for (int i = tailVec.size() - 1; i > 0; i--)
	{
		
		tailVec[i]->setPos(tailVec[i - 1]->getPos());
	}

	if (tailVec.size() >= 1) {
		
		tailVec[0]->setPos(Unit::getPos());

	}

}

void Snake::growTail( )
{

		if (this->tailVec.size() == 1)
		{
			this->tailVec.push_back(new Tail(Unit::getPos(), &this->tailTexture));
		}
		else
		{
			this->tailVec.push_back(new Tail(this->tailVec[this->tailVec.size() - 1]->getPos(), &this->tailTexture));
		}
}

bool Snake::checkSnakeCollision() {
	
	if (this->tailVec.size() > 3) {
	
		for (int i=1; i < this->tailVec.size(); i++) {
		
			if (Unit::getCollider().checkCollision(this->tailVec[i]->getCollider()) == true) {
			
				return true;
			
			}
		
		}

	}
	return false;
}


