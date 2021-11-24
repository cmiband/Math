#pragma once
#include <SFML/Graphics.hpp>
#include "coordinates.h"
#include <math.h>
#include <iostream>
#include "GeoShape.h"

#define PI 3.14159265

class DirectLine : public GeoShape
{
private:
	float startingPointx;
	float aRatio, bRatio;  

	sf::Vertex line[2];

public:
	DirectLine(float x, float a, float b);
	virtual void drawOnScreen(sf::RenderWindow* w);
};
