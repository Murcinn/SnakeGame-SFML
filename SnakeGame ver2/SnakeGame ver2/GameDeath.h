#pragma once

#define MAX_NUMBER_OF_ITEMS_GAME_DEATH 2

#include <SFML/Graphics.hpp>
#include <sstream> 
#include <fstream>


class GameDeath {

	int x = 30;	  //ile kwadracików na planszy
	int y = 30;
	int pixels = 32;//rozmiar jednego kwadracika
	int width = x * pixels;
	int height = y * pixels;

	sf::RenderWindow window;

	//BG
	sf::RectangleShape bgShape;
	sf::Texture bgTexture;


	//score

	std::ifstream readFilee;
	sf::Text highScoree;
	std::ostringstream hsScoree;
	int highestScoree;
	sf::Font fontt;

	
	sf::Text scoree;
	std::ostringstream sScoree;
	int scoreInt;
	

public:

	GameDeath();
	~GameDeath();

	void draw(sf::RenderWindow& window);
	void moveUp();
	void moveDown();
	void loadDeathBG();
	void showScores();

	//run
	void runGameDeath();

private:

	int selectedItemIndex;//mainmenuselected
	sf::Font font;
	sf::Text menu[MAX_NUMBER_OF_ITEMS_GAME_DEATH];

};
