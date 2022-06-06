#pragma once



#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include<iostream>

#include "Snake.h"
#include "Unit.h"
#include "Border.h"
#include "Fruit.h"
#include "Snake.h"
#include "DeltaTime.h"


#include <vector>

#include "Button.h"

#include <sstream> 
#include <fstream>

#include <filesystem>




class GameProcess{

	int x = 30;	  //ile kwadracików na planszy
	int y = 30;
	int pixels = 32;//rozmiar jednego kwadracika
	int width = x * pixels;
	int height = y * pixels;

	


	Snake* mySnake;
	Border* myBorder;
	Fruit* myFruit;
	Fruit* myFruit1;

	double tailCounter;

	double snakeDT;
	double fruitDT;




public:
	sf::RenderWindow window;

	GameProcess();
	~GameProcess();
	void RunGame();


	//initializations
	void allInits();
	void initWindow();
	void initSnake();
	void initBorder();
	void initFruit();

	void allLoaders();
	void loadSnake();
	void loadBorder();
	void loadFruit();
	void loadWindow();

	//collisions
	void boardCollide();
	void fruitCollide();
	void bodyCollide(double deltaTime);



	//clear
	void clearMemory();

private:
	//textures
		
		//board
		sf::Texture boardTexture;
		sf::Sprite boardSprite;
		sf::Texture boardBGTexture;
		sf::RectangleShape boardBGShape;

		//snake
		sf::Texture snakeTexture;
		sf::Vector2f snakePosition;

		//border
		sf::Texture borderTexture;
		sf::Vector2f borderPosition;
		std::vector<Border*> vecBorder;

		//fruit
		sf::Texture fruitTexture;
		sf::Vector2f fruitPosition;
		sf::Texture fruitTexture1;
		std::vector<Fruit* > fruitVec;
		std::vector<Fruit* > fruit1Vec;

	//other functions
		void setTimers();
		void loadMenu();
		void initMenu();

	//score
		int gameScore;
		sf::Font font;
		std::ostringstream ssScore;
		sf::Text lblScore;
	
		void setScore();
		void saveScore();

	//highest score
		std::ifstream readFile;
		std::ofstream writeFile;

		sf::Text highScore;
		std::ostringstream hsScore;

		int highestScore;
		void setHighestScore();

		void readHighestScore();

};