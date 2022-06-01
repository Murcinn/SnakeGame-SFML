#include "Button.h"

Button::Button(double x, double y, double width, double height, sf::Font* font, std::string text, sf::Color idleColor, sf::Color hoverColor, sf::Color activeColor)
{

	this->shape.setPosition(sf::Vector2f(x, y));
	this->shape.setSize(sf::Vector2f(width, height));

	this->font = font;
	this->text.setFont(*this->font);
	this->text.setString(text);
	this->text.setFillColor(sf::Color::White);
	this->text.setCharacterSize(15);
	this->text.setPosition(this->shape.getPosition().x +( this->shape.getGlobalBounds().width / 2.f)-this->text.getGlobalBounds().width/2.f,
						   this->shape.getPosition().y + (this->shape.getGlobalBounds().height / 2.f) - this->text.getGlobalBounds().height / 2.f);


	this->idleColor = idleColor;
	this->hoverColor = hoverColor;
	this->activeColor = activeColor;

	this->shape.setFillColor(this->idleColor);

	this->buttonTypeSU = buttonIdle;
}

Button::~Button()
{
}

void Button::render(sf::RenderWindow* window)
{
	window->draw(this->shape);
}

void Button::update(const sf::Vector2f mouseVec)
{	//idle
	this->buttonTypeSU = buttonIdle;
	//hover
	if (this->shape.getGlobalBounds().contains(mouseVec)) {
	
		this->buttonTypeSU = buttonHover;

		if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
			//pressed
			this->buttonTypeSU = buttonActive;
		
		}
	
	}

	switch (this->buttonTypeSU)  {

	case buttonIdle:
		this->shape.setFillColor(this->idleColor);
		break;

	case buttonHover:
		this->shape.setFillColor(this->hoverColor);
		break;

	case buttonActive:
		this->shape.setFillColor(sf::Color::Red);
		break;



	}
		

}

const bool Button::isKeyPressed() const
{
	if (this->buttonTypeSU == buttonActive) {
	
		return true;
	
	}
	return false;

}



void Button::updateMousePos(sf::RenderWindow* window1)
{

	this->mousePosScreen = sf::Mouse::getPosition();
	this->mousePosWin = sf::Mouse::getPosition(*window1);
	this->mousePosView = this->window->mapPixelToCoords(mousePosWin);
}
