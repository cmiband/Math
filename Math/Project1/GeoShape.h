#pragma once
#include <SFML/Graphics.hpp>

class GeoShape
{
public:
	sf::Color color = sf::Color::Black;

	virtual void drawOnScreen(sf::RenderWindow* w) = 0;
};

