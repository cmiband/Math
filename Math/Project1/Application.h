#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include "Point.h"
#include "coordinates.h"
#include "DirectLine.h"
#include "Circle.h"
#include <iostream>

using namespace std;

class Application
{
private:
	const sf::Color bgColor = sf::Color(192, 192, 192);
	sf::Image coordsImage;
	sf::Texture coordsTexture;
	sf::RectangleShape coordsRect;
	sf::Font font;

	const float BOX_LENGHT = 20.0f;
	const float CENT_LENGHT = coordinates::CENT_LENGHT;
public:
	Application(sf::Font f);
	~Application() {};

	int Run();
};

