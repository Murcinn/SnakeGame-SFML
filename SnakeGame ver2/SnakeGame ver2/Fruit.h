#pragma once
#include"Unit.h"

class Fruit :public Unit {

	bool ifCollide;


	std::vector<Fruit*> vecFruit;
	
public:
	Fruit(sf::Vector2f position, sf::Texture* texture);

	~Fruit();

	void update(double deltaTime) override;

	void setCollide(bool newCol);

};