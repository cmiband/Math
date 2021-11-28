#include "Point.h"

Point::Point(float x, float y) : posx(x), posy(y)
{
	pt.setFillColor(color);
	pt.setOrigin(sf::Vector2f(radius, radius));
	float fixedX = coordinates::toCoordinate(posx, true) * coordinates::CENT_LENGHT;
	float fixedY = coordinates::toCoordinate(posy, false) * coordinates::CENT_LENGHT;

	pt.setPosition(sf::Vector2f(fixedX, fixedY));
}

void Point::drawOnScreen(sf::RenderWindow* w)
{
	w->draw(pt);
}


