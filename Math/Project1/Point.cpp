#include "Point.h"

Point::Point(float x, float y) : posx(x), posy(y)
{
	pt.setFillColor(color);
	pt.setOrigin(sf::Vector2f(radius, radius));
	pt.setPosition(sf::Vector2f(posx, posy));
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

void Point::drawOnScreen(sf::RenderWindow* w)
{
	w->draw(pt);
}


