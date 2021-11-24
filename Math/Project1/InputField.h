#pragma once
#include <SFML/Graphics.hpp>
#include "GeoShape.h"
#include <iostream>

using namespace std;

class InputField : public GeoShape
{
private:
	sf::RectangleShape field;

	string value;
	bool focused;

	sf::Font font;
	sf::Text text;
	sf::Mouse mouse;

public:
	InputField(sf::Font f, sf::Vector2f p);
	~InputField() {};

	virtual void drawOnScreen(sf::RenderWindow* w);
	void checkForFocus(sf::RenderWindow& w);
};

