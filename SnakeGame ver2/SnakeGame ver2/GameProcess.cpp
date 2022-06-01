#include "GameProcess.h"

//#include "Snake.h"
#include "GameDeath.h"


GameProcess::GameProcess() : window(sf::VideoMode(width * 4 / 3, height), "Snake Game !!!!!", sf::Style::Close) {

	this->tailCounter = 0;

	this->gameScore = 0;

	
}

GameProcess::~GameProcess()
{
	delete this->mySnake;
	delete this->myFruit;
	delete this->myBorder;
	this->fruitVec.clear();
	this->gameScore = 0;
	
	
	

}

	



void GameProcess::RunGame() {
	float fps;
	sf::Clock clock = sf::Clock::Clock();
	sf::Time previousTime = clock.getElapsedTime();
	sf::Time currentTime;
	std::cout << "xd";
	//window.setFramerateLimit(120);

	GameProcess::allLoaders();
	

	while (this->window.isOpen()) {
		this->lblScore.setString(this->ssScore.str());
		sf::Event mainEvent;
		
		while (this->window.pollEvent(mainEvent)) {
			
			if (mainEvent.type == sf::Event::Closed) {
				window.close();
			}
			if (mainEvent.type == sf::Event::KeyPressed) {
				if (mainEvent.key.code == sf::Keyboard::Escape) {
					window.close();
				}
			}

		}
		GameProcess::clearMemory();
		GameProcess::setTimers();
	

		GameProcess::allInits();

		

		GameProcess::boardCollide();
		GameProcess::fruitCollide();
		GameProcess::bodyCollide(fruitDT);//0.0002
		
		
	
		

		this->window.display();

		//fps checker
		currentTime = clock.getElapsedTime();
		fps = 1.0f / (currentTime.asSeconds() - previousTime.asSeconds());
		//std::cout << "fps =" << floor(fps) << std::endl;
		previousTime = currentTime;

	}
	
}

void GameProcess::allInits()
{
	GameProcess::initWindow();
	GameProcess::initBorder();
	GameProcess::initSnake();
	GameProcess::initFruit();
	//GameProcess::initMenu();
	this->window.draw(this->lblScore);
	this->window.draw(this->highScore);
	this->setHighestScore();


}

void GameProcess::allLoaders()
{
	this->loadSnake();
	this->loadBorder();
	this->loadFruit();
	this->loadWindow();
	//this->loadMenu();

	this->setScore();
	this->readHighestScore();

}

void GameProcess::loadWindow()
{
	this->boardTexture.loadFromFile("images/background.png");

	this->boardSprite.setTexture(boardTexture);

	//sf::Sprite boardSprite(boardTexture);
	this->boardBGTexture.loadFromFile("images/gameBG.png");
	this->boardBGShape = sf::RectangleShape(sf::Vector2f(width * 4 / 3, height));
	this->boardBGShape.setTexture(&boardBGTexture);
}

void GameProcess::initWindow()
{
	this->window.draw(boardBGShape);
	
	
	for (int i = 0; i < x; i++)
		for (int j = 0; j < y; j++)
		{
			this->boardSprite.setPosition(i * this->pixels, j * this->pixels);
			//	boardSprite.setPosition(i * this->pixels, j * this->pixels);

				this->window.draw(this->boardSprite);
			
		}
	
}

void GameProcess::loadSnake()
{

	this->snakeTexture.loadFromFile("images/snake.png");

	snakePosition.x = (height / 2) + (pixels / 2);
	snakePosition.y = (width / 2) + (pixels / 2);

	this->mySnake = new Snake(snakePosition, &snakeTexture);



}

void GameProcess::initSnake()
{
	this->mySnake->draw(&window);
	this->mySnake->update(snakeDT); //0.0003
	//fast 0.00035
}

void GameProcess::loadBorder()
{

	this->borderTexture.loadFromFile("images/border.png");


	this->myBorder = new Border(borderPosition, &borderTexture);


}

void GameProcess::initBorder()
{
	for (int i = 0; i < x; i++) {
		for (int j = 0; j < y; j++)
		{
			if (i == 0 || i == x - 1 || j == 0 || j == y - 1) {
				
				this->myBorder->setPos(sf::Vector2f(i * pixels + (0.5 * pixels), j * pixels + (0.5 * pixels)));

				this->myBorder->draw(&window);

				borderPosition = this->myBorder->getPos();

				this->vecBorder.push_back(new Border(borderPosition, &borderTexture));


			}

		}

	}

}

void GameProcess::boardCollide()
{
	for (int i = 0; i < vecBorder.size(); i++) {

		
		if (this->mySnake->getCollider().checkCollision(this->vecBorder[i]->getCollider()) == true) {

			std::cout << "kolizja" << i << std::endl;
			this->saveScore();
			this->window.close();
			GameDeath firstDeath;
			firstDeath.runGameDeath();
			

		}

	}

}

void GameProcess::clearMemory()
{
	this->window.clear();
	this->vecBorder.clear();
	
}

void GameProcess::loadFruit()
{
	this->fruitTexture.loadFromFile("images/apple.png");
	
	//fruitPosition.x = (height / 3) + (pixels / 3);
	//fruitPosition.y = (width / 2) + (pixels / 2);

	
	
	this->fruitTexture1.loadFromFile("images/pear.png");
	
	for (int i = 0; i < 3; i++) {
		
		this->myFruit = new Fruit(fruitPosition, &fruitTexture);
		this->fruitVec.push_back(this->myFruit);
	}

	for (int i = 0; i < 2; i++) {
		this->myFruit1 = new Fruit(fruitPosition, &fruitTexture1);
		this->fruit1Vec.push_back(this->myFruit1);
	}

}

void GameProcess::initFruit()
{
	


		//this->myFruit1->draw(&window);
		//this->myFruit1->update(fruitDT);

		for (int i = 0; i < 3; i++) {

			this->fruitVec[i]->draw(&window);
			this->fruitVec[i]->update(fruitDT);

		}

		for (int i = 0; i < 2; i++) {

			this->fruit1Vec[i]->draw(&window);
			this->fruit1Vec[i]->update(fruitDT);

		}

	


		//std::cout << myFruit->getPos().x << " " << myFruit->getPos().y << " \n";
	
}

void GameProcess::fruitCollide()
{
	for (int i = 0; i < fruitVec.size(); i++) {
		if (mySnake->getCollider().checkCollision(fruitVec[i]->getCollider()) == true) {

			fruitVec[i]->setCollide(true);

			this->mySnake->growTail();

			this->gameScore++;
			this->ssScore.str("");
			this->ssScore << "Score: " << this->gameScore;
		
			
		}
	}

	for (int i = 0; i < fruit1Vec.size(); i++) {
		if (mySnake->getCollider().checkCollision(fruit1Vec[i]->getCollider()) == true) {

			fruit1Vec[i]->setCollide(true);

			this->mySnake->growTail();
			this->mySnake->growTail();
			
			this->gameScore++;
			this->gameScore++;
			this->ssScore.str("");
			this->ssScore << "Score: " << this->gameScore;
			

		}
	}

}

void GameProcess::bodyCollide(double deltaTime)
{
	
		if (this->mySnake->checkSnakeCollision() == true) {

			std::cout << "Body collide\n";
			this->saveScore();
			this->window.close();
			GameDeath firstDeath;
			firstDeath.runGameDeath();
			
		}
	
	
}

void GameProcess::setTimers()
{
	snakeDT = DeltaTime::getInstance().getDT();
	fruitDT = DeltaTime::getInstance().getDT();
	DeltaTime::getInstance().updateDT();
	//std::cout << yikesDT << " \n";
}

void GameProcess::loadMenu()
{
	
//	this->myMenu = new GameMenu(width, height);

}

void GameProcess::initMenu()
{




	//this->myMenu->draw(window);
	//this->myMenu->gameStateButton->update(this->moveposviev)
	
}

void GameProcess::setScore()
{



	font.loadFromFile("fonts/Tropics.ttf");
	ssScore << "Your\nScore: " <<  gameScore;
	lblScore.setCharacterSize(50);
	lblScore.setPosition(width+32 , height*(0.25));
	lblScore.setFont(font);

	
	
}


void GameProcess::setHighestScore()
{
	readFile.open("Resources/HighestScore.txt");

	if (readFile.is_open()) {
		while (!readFile.eof()) {
			readFile >> highestScore;
		}
	}
	readFile.close();

	writeFile.open("Resources/HighestScore.txt");
	if (writeFile.is_open()) {
		if (gameScore > highestScore) {
			highestScore = gameScore;
		}
		writeFile << highestScore;
	}
	writeFile.close();
}

void GameProcess::readHighestScore()
{
	readFile.open("Resources/HighestScore.txt");

	if (readFile.is_open()) {
		while (!readFile.eof()) {
			readFile >> highestScore;
		}
	}
	readFile.close();

	font.loadFromFile("fonts/Tropics.ttf");
	hsScore << "Highest\nScore: " << highestScore;
	highScore.setCharacterSize(50);
	highScore.setPosition(width + 32, height * (0.5));
	highScore.setFont(font);
	//highScore.setFillColor(sf::Color::Red);
	highScore.setString(hsScore.str());


}


void GameProcess::saveScore()
{




	

	writeFile.open("Resources/Score.txt");
	writeFile.clear();
	if (writeFile.is_open()) {
		
		writeFile << gameScore;

	}
	writeFile.close();


}
