#pragma once

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include<iostream>

enum buttonType {buttonIdle=0, buttonHover, buttonActive};

class Button {


	sf::RectangleShape shape;
	sf::Font* font;
	sf::Text text;

	sf::Color idleColor;
	sf::Color hoverColor;
	sf::Color activeColor;

	short unsigned buttonTypeSU;

	sf::RenderWindow* window;

public:

	Button(double x, double y, double width, double height, sf::Font* font, std::string text,sf::Color idleColor, sf::Color hoverColor, sf::Color activeColor);
	~Button();

	void render(sf::RenderWindow* window);

	void update(const sf::Vector2f mouseVec);




	const bool isKeyPressed()const;

	//mouse pos

	sf::Vector2i mousePosScreen;
	sf::Vector2i mousePosWin;
	sf::Vector2f mousePosView;

	void updateMousePos(sf::RenderWindow* window1);

};