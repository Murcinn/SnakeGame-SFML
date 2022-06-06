#include "DeltaTime.h"

#include <iostream>

DeltaTime& DeltaTime::getInstance()
{
	static DeltaTime instance;
	return instance;
}

double DeltaTime::getDT()
{
	return DT;
}

void DeltaTime::updateDT()
{
	this->DT = this->clock.restart().asSeconds();

}
