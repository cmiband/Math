#pragma once
#include "GeoShape.h"
#include "coordinates.h"

class Circle : public GeoShape
{
private:
	float radius;
	float posx, posy;

	sf::CircleShape circ;
public:
	Circle(float r, float x, float y);
	~Circle() {};
	virtual void drawOnScreen(sf::RenderWindow* w);

};

