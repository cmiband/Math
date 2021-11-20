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

	sf::Vertex line[2];

public:
	DirectLine(float x, float a, float b);
	sf::Vertex start();
	sf::Vertex end();
};

