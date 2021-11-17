#include "Point.h"

Point::Point(float x, float y) : posx(x), posy(y)
{
	pt.setFillColor(sf::Color(0, 0, 0));
	pt.setPosition(posx, posy);
}

sf::Vector2f Point::getPosition()
{
	return sf::Vector2f(posx, posy);
}

void Point::setPosition(float x, float y)
{
	posx = x; posy = y;
	pt.setPosition(sf::Vector2f(posx, posy));
}

sf::CircleShape Point::getShape()
{
	return pt;
}


