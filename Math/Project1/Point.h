#pragma once
#include <SFML/Graphics.hpp>
#include "coordinates.h"
#include "GeoShape.h"

class Point : public GeoShape
{
private:
	float posx, posy;
	const float radius = 5.0f;
	sf::CircleShape pt = sf::CircleShape(radius);

public:
	Point(float x, float y);
	~Point() {};

	virtual void drawOnScreen(sf::RenderWindow* w);
};

