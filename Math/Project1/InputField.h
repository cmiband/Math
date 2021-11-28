#pragma once
#include <SFML/Graphics.hpp>
#include "GeoShape.h"
#include <string>

using namespace std;

class InputField : public GeoShape
{
private:
	string value;
	string labelVal;
	bool focused;
	int maximumAmountOfLetters;
	float width, height;

	sf::Font font;
	sf::Text label;
	sf::Text text;
	sf::Mouse mouse;
	sf::RectangleShape field;

public:
	InputField(sf::Font f, sf::Vector2f p, float w, float h, string l);
	~InputField() {};

	virtual void drawOnScreen(sf::RenderWindow* w);
	void update(sf::Event &ev, sf::RenderWindow &w);
	void reset();
	void setPos(sf::Vector2f p);

	float getValue();
};

