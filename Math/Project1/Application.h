#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include "Point.h"
#include "coordinates.h"
#include <iostream>

using namespace std;

class Application
{
private:
	const sf::Color bgColor = sf::Color(192, 192, 192);
	sf::Image coordsImage;
	sf::Texture coordsTexture;
	sf::RectangleShape coordsRect;

	const float BOX_LENGHT = 20.0f;
	const float CENT_LENGHT = 40.0f;

	float toCoordinate(float val, bool axis);
public:
	Application();
	~Application() {};

	int Run();
};
