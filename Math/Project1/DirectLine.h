#pragma once
#include <SFML/Graphics.hpp>
#include "coordinates.h"
#include <math.h>
#include <iostream>

#define PI 3.14159265

class DirectLine
{
private:
	float startingPointx;
	float aRatio, bRatio;
	float xAxisAngle;     // TODO : tangens alfa = aRatio

	sf::RectangleShape line;

public:
	DirectLine(float x, float a, float b);
	sf::RectangleShape getShape();

};

