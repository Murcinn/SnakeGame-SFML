#pragma once

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

class DeltaTime{
	sf::Clock clock;
	double DT;
	

public:
	
	DeltaTime() { DT = 0.f; }

	static DeltaTime& getInstance();

	double getDT();
	
	void updateDT();

};