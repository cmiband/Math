#pragma once
#include "GeoShape.h"
#include <string>

using namespace std;

class Button : public GeoShape
{
private:
	string valText;
	bool click;

	sf::Text text;
	sf::RectangleShape button;
public:
	Button(string t, sf::Vector2f p);
	bool getClick();

	virtual void drawOnScreen(sf::RenderWindow* w);
};

