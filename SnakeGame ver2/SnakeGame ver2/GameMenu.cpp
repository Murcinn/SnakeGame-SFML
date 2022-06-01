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
	
	//this->gameStateButton = new Button(100,100,150,50,&this->font,"XDDDDD",sf::Color::White,sf::Color::Red,sf::Color::Cyan);

}

GameMenu::~GameMenu()
{
	//delete this->gameStateButton;
}

void GameMenu::runMenu()
{
	//this->firstGameProcess->RunGame();
	//GameMenu();
	

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
					//sf::RenderWindow Play;//(sf::VideoMode(960, 720), "SNAKE")
					//sf::RenderWindow ResetHs;//(sf::VideoMode(960, 720), "OPTIONS");
					//sf::RenderWindow Exit;// (sf::VideoMode(960, 720), "ABOUT");
					

					int x = this->selectedItemIndex;
					if (x == 0) {
						//while (Play.isOpen()) {
						//	sf::Event ev;
						//	while (Play.pollEvent(ev)) {
						//		if (ev.type == sf::Event::Closed) {
						//			Play.close();
						//		}
						//		if (ev.type == sf::Event::KeyPressed) {
						//			if (ev.key.code == sf::Keyboard::Escape) {
						//				Play.close();
						//			}

						//		}
						//	}
						//	
						//	ResetHs.clear();
						//	Exit.clear();
						//	Play.clear();
		
						//}
						GameProcess firstGameProcess;
						this->window.close();
						firstGameProcess.RunGame();
						

					}
					if (x == 1) {						
						//while (ResetHs.isOpen()) {
						//	sf::Event ev;
						//	while (ResetHs.pollEvent(ev)) {
						//		if (ev.type == sf::Event::Closed) {
						//			ResetHs.close();
						//		}
						//		if (ev.type == sf::Event::KeyPressed) {
						//			if (ev.key.code == sf::Keyboard::Escape) {
						//				ResetHs.close();
						//			}

						//		}
						//	}
						//	this->clearHS();
						//	//ResetHs.clear();
						//	//Exit.clear();
						//	//Play.clear();
						//	//Exit.display();

						//}
						
						this->clearHS();
						GameMenu g1;
						this->window.close();
						g1.runMenu();
					}
					/*if (x == 2) {
						while (Control.isOpen()) {
							sf::Event ev;
							while (Options.pollEvent(ev)) {
								if (ev.type == sf::Event::Closed) {
									Options.close();
								}
								if (ev.type == sf::Event::KeyPressed) {
									if (ev.key.code == sf::Keyboard::Escape) {
										Control.close();
									}

								}
							}
							Options.clear();
							Control.clear();
							Play.clear();
							Control.display();

						}

					}*/
					if (x == 2) 
						std::cout << "\n\nigger";
						this->window.close();
					return;

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
	//writeFile.open("Resources/HighestScore.txt");
	//writeFile.clear();
	//writeFile.close();
	std::filesystem::remove_all(hcCur);



}

