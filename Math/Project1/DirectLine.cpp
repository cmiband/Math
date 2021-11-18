#include "DirectLine.h"

DirectLine::DirectLine(float x, float a, float b) : startingPointx(x), aRatio(a), bRatio(b)
{
	startingPointy = startingPointx * aRatio + bRatio;

	line.setSize(sf::Vector2f(coordinates::SYSTEM_LENGHT - startingPointx, 5.0f));
	line.setFillColor(sf::Color(0, 0, 0));
}

sf::RectangleShape DirectLine::getShape()
{
	return line;
}
