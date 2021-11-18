#pragma once
#include <SFML/Graphics.hpp>
#include "coordinates.h"

class Point
{
private:
	float posx, posy;
	const float radius = 5.0f;
	sf::CircleShape pt = sf::CircleShape(radius);

public:
	Point(float x, float y);
	~Point() {};

	sf::Vector2f getPosition();
	void setPosition(float x, float y);
	sf::CircleShape getShape();
};

