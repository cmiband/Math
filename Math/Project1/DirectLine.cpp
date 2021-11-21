#include "DirectLine.h"

DirectLine::DirectLine(float x, float a, float b) : startingPointx(x), aRatio(a), bRatio(b)
{
	float coordX = coordinates::toCoordinate(startingPointx, true);
	float yStart = coordinates::toCoordinate(coordinates::linearFunction(startingPointx, aRatio, bRatio),false)*coordinates::CENT_LENGHT;
	if (yStart >= coordinates::SYSTEM_LENGHT) {
		yStart = coordinates::SYSTEM_LENGHT;
		coordX = coordinates::toCoordinate(coordinates::reverseLinearFunction(-5.0f, aRatio, bRatio), true) * coordinates::CENT_LENGHT;
	}
	line[0].position = sf::Vector2f(coordX, yStart);
	line[0].color = sf::Color::Black;

	float yEnd = coordinates::toCoordinate(coordinates::linearFunction(5.0f, aRatio, bRatio), false)*coordinates::CENT_LENGHT;
	float xEnd = coordinates::toCoordinate(5.0f, true) * coordinates::CENT_LENGHT;
	if (yEnd >= coordinates::SYSTEM_LENGHT) {
		xEnd = coordinates::toCoordinate(coordinates::reverseLinearFunction(-5.0f, aRatio, bRatio),true) * coordinates::CENT_LENGHT;
		yEnd = coordinates::SYSTEM_LENGHT;
	}

	line[1].position = sf::Vector2f(xEnd, yEnd);
	line[1].color = sf::Color::Black;
}

sf::Vertex DirectLine::start()
{
	return line[0];
}

sf::Vertex DirectLine::end()
{
	return line[1];
}
