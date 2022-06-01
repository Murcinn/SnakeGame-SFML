#pragma once

#include "Unit.h"
#include "Tail.h"
#include <vector>

enum DIRECTION { UP = 0, RIGHT, DOWN, LEFT };

class Snake : public Unit {

	double snakeCounter;
	DIRECTION dir;
	double growCounter;

	//tail
	
	sf::Texture tailTexture;

public:


	Snake(sf::Vector2f position, sf::Texture* texture);
	~Snake();

	void draw(sf::RenderWindow* window) override;

	void update(double deltaTime) override;
	
	void keyboardInput();

	void followingTail();

	void growTail();

	bool checkSnakeCollision();

private:
	std::vector<Tail*> tailVec;
};