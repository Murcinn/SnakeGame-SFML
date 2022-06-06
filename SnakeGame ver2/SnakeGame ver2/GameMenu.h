#pragma once


#define MAX_NUMBER_OF_ITEMS 3

#include <SFML/Graphics.hpp>
#include <sstream> 
#include <fstream>
#include <filesystem>
class GameMenu {
	int x = 30;	  //ile kwadracików na planszy
	int y = 30;
	int pixels = 32;//rozmiar jednego kwadracika
	int width = x * pixels;
	int height = y * pixels;

	sf::RenderWindow window;
	
	//background
	sf::RectangleShape bgShape;
	sf::Texture bgTexture;

	//score
	std::ifstream readFilee;
	sf::Text highScoree;
	std::ostringstream hsScoree;
	int highestScoree;
	sf::Font fontt;
	std::ofstream writeFile;

public:
	
	GameMenu();
	~GameMenu();

	void draw(sf::RenderWindow& window);
	void moveUp();
	void moveDown();

	void loadMenuBG();

	void showHS();

	std::filesystem::path hcCur = std::filesystem::current_path().append("Resources/HighestScore.txt");
	void clearHS();



	//run
	void runMenu();
	
private:

	int selectedItemIndex;//mainmenuselected
	sf::Font font;
	sf::Text menu[MAX_NUMBER_OF_ITEMS];




};
