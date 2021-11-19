#include "DirectLine.h"

DirectLine::DirectLine(float x, float a, float b) : startingPointx(x), aRatio(a), bRatio(b)
{
	line.setSize(sf::Vector2f(coordinates::SYSTEM_LENGHT - startingPointx, 5.0f));
	line.setFillColor(sf::Color(0, 0, 0));
	line.setOrigin(sf::Vector2f(0.0f, 2.5f));
	line.setPosition(sf::Vector2f(coordinates::toCoordinate(startingPointx, true)*coordinates::CENT_LENGHT, coordinates::toCoordinate(coordinates::linearFunction(startingPointx, aRatio, bRatio),false)*coordinates::CENT_LENGHT));

	xAxisAngle = 360.0f - (atan2f(coordinates::linearFunction(5.0f, aRatio, bRatio), 5.0f) * 180/PI);
	line.setRotation(xAxisAngle);
}

sf::RectangleShape DirectLine::getShape()
{
	return line;
}
