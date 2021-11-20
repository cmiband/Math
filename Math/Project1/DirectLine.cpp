#include "DirectLine.h"

DirectLine::DirectLine(float x, float a, float b) : startingPointx(x), aRatio(a), bRatio(b)
{
	float yStart = coordinates::toCoordinate(coordinates::linearFunction(startingPointx, aRatio, bRatio),false);
	line[0].position = sf::Vector2f(coordinates::toCoordinate(startingPointx,true), yStart);
	line[0].color = sf::Color::Black;

	float yEnd = coordinates::toCoordinate(coordinates::linearFunction(5.0f, aRatio, bRatio), false);
	line[1].position = sf::Vector2f(coordinates::toCoordinate(5.0f, true), yEnd);
	line[1].color = sf::Color::Black;
}

sf::Vertex DirectLine::start()
{
	return line[0];
}
