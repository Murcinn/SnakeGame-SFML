#include "GameMenu.h"

#include "GameProcess.h"
//double width, double height
GameMenu::GameMenu():window(sf::VideoMode(width * 4 / 3, height), "Snake Game !!!", sf::Style::Close)
{
	if (!font.loadFromFile("fonts/ReactiveAnchor-L3L0n.ttf")) {
	
	}

	//PLAY GAME
	menu[0].setFont(font);
	menu[0].setFillColor(sf::Color::Red);
	menu[0].setString("PLAY");
	menu[0].setCharacterSize(80);
	menu[0].setPosition(sf::Vector2f(width / 2, height / (MAX_NUMBER_OF_ITEMS + 2) *0.7));
	//options
	menu[1].setFont(font);
	menu[1].setFillColor(sf::Color::Yellow);
	menu[1].setString("RESET HS");
	menu[1].setCharacterSize(80);
	menu[1].setPosition(sf::Vector2f(width / 2, height / (MAX_NUMBER_OF_ITEMS + 2)*1.7));
	////constrols
	//menu[2].setFont(font);
	//menu[2].setFillColor(sf::Color::Yellow);
	//menu[2].setString("CONTROL");
	//menu[2].setCharacterSize(80);
	//menu[2].setPosition(sf::Vector2f(width / 2, height / (MAX_NUMBER_OF_ITEMS + 2)*3));
	//exit
	menu[2].setFont(font);
	menu[2].setFillColor(sf::Color::Yellow);
	menu[2].setString("EXIT");
	menu[2].setCharacterSize(80);
	menu[2].setPosition(sf::Vector2f(width / 2, height / (MAX_NUMBER_OF_ITEMS + 2) * 2.7));

	selectedItemIndex = 0;
	this->showHS();	

}

GameMenu::~GameMenu()
{

}

void GameMenu::runMenu()
{
	this->loadMenuBG();

	while (this->window.isOpen()) {

		sf::Event mainEvent;

		
		
		while (this->window.pollEvent(mainEvent)) {

			if (mainEvent.type == sf::Event::Closed) {
				window.close();
			}

		if (mainEvent.type == sf::Event::KeyReleased) {
			
				if (mainEvent.key.code == sf::Keyboard::Up) {
				
					this->moveUp();
					break;
				
				}
				if (mainEvent.key.code == sf::Keyboard::Down) {

					this->moveDown();
					break;

				}
				if (mainEvent.key.code == sf::Keyboard::Return) {


					int x = this->selectedItemIndex;
					if (x == 0) {

						GameProcess firstGameProcess;
						this->window.close();
						firstGameProcess.RunGame();
						
					}
					if (x == 1) {						
						
						this->clearHS();
						GameMenu g1;
						this->window.close();
						g1.runMenu();
					}

					if (x == 2) 
						
						this->window.close();
					return;

				}			
			}
		}

		this->window.clear();
		this->window.draw(bgShape);
		this->draw(window);
		this->window.draw(this->highScoree);


		this->window.display();
	}




}

void GameMenu::draw(sf::RenderWindow& window)
{
	for (int i = 0; i < MAX_NUMBER_OF_ITEMS; i++) {
		window.draw(menu[i]);
	
	
	}
}

void GameMenu::moveUp()
{
	if (selectedItemIndex - 1 >= 0) {
		menu[selectedItemIndex].setFillColor(sf::Color::Yellow);
		selectedItemIndex--;

		if (selectedItemIndex == -1) {
			selectedItemIndex == 3;
		}
		this->menu[selectedItemIndex].setFillColor(sf::Color::Red);
	}
}

void GameMenu::moveDown()
{
	if (selectedItemIndex + 1 <= MAX_NUMBER_OF_ITEMS) {
		menu[selectedItemIndex].setFillColor(sf::Color::Yellow);
		selectedItemIndex++;
		if (selectedItemIndex == 3) {
			selectedItemIndex = 0;
		}
		this->menu[selectedItemIndex].setFillColor(sf::Color::Red);
	}
}


void GameMenu::loadMenuBG()
{

	this->bgShape=sf::RectangleShape(sf::Vector2f( width*4/3,height));

	this->bgTexture.loadFromFile("images/menu.jpg");

	this->bgShape.setTexture(&bgTexture);


}



void GameMenu::showHS()
{
	readFilee.open("Resources/HighestScore.txt");

	if (readFilee.is_open()) {
		while (!readFilee.eof()) {
			readFilee >> highestScoree;
		}
	}
	readFilee.close();

	fontt.loadFromFile("fonts/Tropics.ttf");
	hsScoree << "Highest Score: " << highestScoree;
	highScoree.setCharacterSize(50);
	highScoree.setPosition(sf::Vector2f(width / 2, height / (MAX_NUMBER_OF_ITEMS + 2) * 3.7));
	highScoree.setFont(fontt);

	highScoree.setString(hsScoree.str());




}


void GameMenu::clearHS()
{
	std::filesystem::remove_all(hcCur);
}

