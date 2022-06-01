#pragma once
#include "Unit.h"


class Border :public Unit {

public:
	
	Border(sf::Vector2f position, sf::Texture* texture);

	~Border();

	void update(double deltaTime) override;

};