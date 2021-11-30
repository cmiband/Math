#pragma once
#include "GeoShape.h"
#include <string>
#include <iostream>

using namespace std;

class Button : public GeoShape
{
private:
	string valText;
	float buttonWidth, buttonHeight;
	float leftOffset;

	sf::Mouse mouse;
	sf::Text text;
	sf::RectangleShape button;
	sf::Font font;
public:
	Button(string t, sf::Vector2f p, sf::Font f, float w, float h, float of);
	bool checkClick(sf::RenderWindow &w);

	virtual void drawOnScreen(sf::RenderWindow* w);
};

