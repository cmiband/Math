#pragma once
#include <SFML/Graphics.hpp>

class Point
{
private:
	float posx, posy;
	sf::CircleShape pt = sf::CircleShape(5.0f);

public:
	Point(float x, float y);
	~Point() {};

	sf::Vector2f getPosition();
	void setPosition(float x, float y);
	sf::CircleShape getShape();
};

