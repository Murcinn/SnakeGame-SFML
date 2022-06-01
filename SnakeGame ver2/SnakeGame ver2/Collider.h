#pragma once
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

class Collider {

	sf::RectangleShape* body;

public:
	Collider(sf::RectangleShape* shape);

	~Collider();

	bool checkCollision(const Collider& colEl);

	sf::Vector2f getHalfSize() const;

	sf::Vector2f getPos() const;

};