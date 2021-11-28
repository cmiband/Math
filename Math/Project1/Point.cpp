#include "Point.h"

Point::Point(float x, float y) : posx(x), posy(y)
{
	pt.setFillColor(color);
	pt.setOrigin(sf::Vector2f(radius, radius));
	//TODO : fixed X and Y for position
	pt.setPosition(sf::Vector2f(posx, posy));
}

void Point::drawOnScreen(sf::RenderWindow* w)
{
	w->draw(pt);
}


