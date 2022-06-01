#pragma once

#include "Unit.h"

class Tail :public Unit {

public:
	Tail(sf::Vector2f position, sf::Texture* texture);
	~Tail();

	void update(double deltaTime) override;


};