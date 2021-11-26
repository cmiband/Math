#pragma once
#include <SFML/Graphics.hpp>
#include "GeoShape.h"
#include <iostream>
#include <string>

using namespace std;

class InputField : public GeoShape
{
private:
	sf::RectangleShape field;

	string value;
	bool focused;
	int maximumAmountOfLetters;

	sf::Font font;
	sf::Text text;
	sf::Mouse mouse;

public:
	InputField(sf::Font f, sf::Vector2f p);
	~InputField() {};

	virtual void drawOnScreen(sf::RenderWindow* w);
	void update(sf::Event &ev, sf::RenderWindow &w);
	void reset();
	void setPos(sf::Vector2f p);

	string getValue();
};

