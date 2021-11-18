#pragma once
#include <SFML/Graphics.hpp>
#include "coordinates.h"

class DirectLine
{
private:
	float startingPointx, startingPointy;
	float aRatio, bRatio;
	float xAxisAngle;     // TODO : tangens alfa = aRatio

	sf::RectangleShape line;

public:
	DirectLine(float x, float a, float b);
	sf::RectangleShape getShape();

};

