#pragma once

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Collider.h"



class Unit {
	sf::Sprite unitSprite;
	sf::RectangleShape body;

	Collider* col;

public:
	Unit(sf::Vector2f position, sf::Texture* texture);
	~Unit();


	//getters
	sf::Vector2f getPos();
	sf::RectangleShape getSha();
	sf::Vector2f getSiz();
	sf::RectangleShape getBody();

	Collider getCollider();

	//setters
	void setPos(sf::Vector2f newPosition);
	void setSiz(sf::Vector2f newSize);



	virtual void draw(sf::RenderWindow* window);
	virtual void update(double deltaTime) = 0;

};

