#include "GameDeath.h"
#include "GameProcess.h"
#include "GameMenu.h"


GameDeath::GameDeath() :window(sf::VideoMode(width * 4 / 3, height), "Snake Game !!!!", sf::Style::Close)
{
	if (!font.loadFromFile("fonts/ReactiveAnchor-L3L0n.ttf")) {

	}

	//P{lay again
	menu[0].setFont(font);
	menu[0].setFillColor(sf::Color::Red);
	menu[0].setString("PLAY AGAIN");
	menu[0].setCharacterSize(80);
	menu[0].setPosition(sf::Vector2f(width *0.4, height / (MAX_NUMBER_OF_ITEMS_GAME_DEATH + 2) *0.7 ));
	//Back to menu
	menu[1].setFont(font);
	menu[1].setFillColor(sf::Color::Yellow);
	menu[1].setString("BACK TO MENU");
	menu[1].setCharacterSize(80);
	menu[1].setPosition(sf::Vector2f(width *0.4, height / (MAX_NUMBER_OF_ITEMS_GAME_DEATH + 2) * 1.4));
	
	

	selectedItemIndex = 0;
	this->showScores();

}

GameDeath::~GameDeath()
{
	
}


void GameDeath::runGameDeath()
{
	//this->firstGameProcess->RunGame();
	//GameMenu();

	this->loadDeathBG();
	

	while (this->window.isOpen()) {
	
		sf::Event mainEvent;
		GameProcess* fristProcess;


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
					//sf::RenderWindow Play_again;//(sf::VideoMode(960, 720), "SNAKE")
					//sf::RenderWindow Back_to_menu;//(sf::VideoMode(960, 720), "OPTIONS");
					GameProcess gameProcess1;
				
					

					int x = this->selectedItemIndex;
					if (x == 0) {
						//while (Play_again.isOpen()) {
						//	sf::Event ev;
						//	while (Play_again.pollEvent(ev)) {
						//		if (ev.type == sf::Event::Closed) {
						//			Play_again.close();
						//		}
						//		if (ev.type == sf::Event::KeyPressed) {
						//			if (ev.key.code == sf::Keyboard::Escape) {
						//				Play_again.close();
						//			}

						//		}
						//	}

							//Play_again.clear();
							//Back_to_menu.clear();	
							this->window.clear();
							

					//	}
						this->window.close();
						gameProcess1.RunGame();


					}
					if (x == 1) {
						/*while (Back_to_menu.isOpen()) {
							sf::Event ev;
							while (Back_to_menu.pollEvent(ev)) {
								if (ev.type == sf::Event::Closed) {
									Back_to_menu.close();
								}
								if (ev.type == sf::Event::KeyPressed) {
									if (ev.key.code == sf::Keyboard::Escape) {
										Back_to_menu.close();
									}

								}
							}*/
							//Play_again.clear();
							//Back_to_menu.clear();
							
						

						//}
						gameProcess1.window.close();
						GameMenu gameMenu1;
						this->window.close();
						gameMenu1.runMenu();
						

					}

				}
			}
		}

		//this->gameStateButton->updateMousePos(&window);
		//system("cls");
		//std::cout << this->gameStateButton->mousePosView.x << "  " << this->gameStateButton->mousePosView.y << "\n";





		//this->gameStateButton->render(&window);
		//this->gameStateButton->update(this->gameStateButton->mousePosView);

		this->window.clear();
		
		this->window.draw(bgShape);
		this->draw(window);
		this->window.draw(this->highScoree);
		this->window.draw(this->scoree);
		
		
		


		this->window.display();
	}




}



void GameDeath::draw(sf::RenderWindow& window)
{
	for (int i = 0; i < MAX_NUMBER_OF_ITEMS_GAME_DEATH; i++) {
		window.draw(menu[i]);


	}
}

void GameDeath::moveUp()
{
	if (selectedItemIndex - 1 >= 0) {
		menu[selectedItemIndex].setFillColor(sf::Color::Yellow);
		selectedItemIndex--;

		if (selectedItemIndex == -1) {
			selectedItemIndex == 1;
		}
		this->menu[selectedItemIndex].setFillColor(sf::Color::Red);
	}
}

void GameDeath::moveDown()
{
	if (selectedItemIndex + 1 <= MAX_NUMBER_OF_ITEMS_GAME_DEATH) {
		menu[selectedItemIndex].setFillColor(sf::Color::Yellow);
		selectedItemIndex++;
		if (selectedItemIndex == 2) {
			selectedItemIndex = 0;
		}
		this->menu[selectedItemIndex].setFillColor(sf::Color::Red);
	}
}

void GameDeath::loadDeathBG()
{

	this->bgShape = sf::RectangleShape(sf::Vector2f(width * 4 / 3, height));

	this->bgTexture.loadFromFile("images/menu.jpg");

	this->bgShape.setTexture(&bgTexture);


}



void GameDeath::showScores()
{
	readFilee.open("Resources/HighestScore.txt");

	if (readFilee.is_open()) {
		while (!readFilee.eof()) {
			readFilee >> highestScoree;
		}
	}
	readFilee.close();

	fontt.loadFromFile("fonts/Tropics.ttf");
	hsScoree << "Highest\nScore: " << highestScoree;
	highScoree.setCharacterSize(50);
	highScoree.setPosition(sf::Vector2f(width * 0.4, height / (MAX_NUMBER_OF_ITEMS_GAME_DEATH + 2) * 2.8));
	highScoree.setFont(fontt);

	highScoree.setString(hsScoree.str());

	readFilee.open("Resources/Score.txt");

	if (readFilee.is_open()) {
		while (!readFilee.eof()) {
			readFilee >> scoreInt;
		}
	}
	readFilee.close();

	
	sScoree << "Highest\nScore: " << scoreInt;
	scoree.setCharacterSize(50);
	scoree.setPosition(sf::Vector2f(width * 0.4, height / (MAX_NUMBER_OF_ITEMS_GAME_DEATH + 2) * 2.1));
	scoree.setFont(fontt);
	scoree.setString(sScoree.str());


}