#include "InputField.h"

InputField::InputField(sf::Font f, sf::Vector2f p)
{
	focused = false;
	font = f;

	field = sf::RectangleShape(sf::Vector2f(75.0f, 30.0f));
	field.setFillColor(sf::Color::White);
	field.setPosition(p);

	text.setFont(font);
	text.setPosition(p);
	text.setString(value);
}

void InputField::drawOnScreen(sf::RenderWindow* w)
{
	w->draw(field);
	w->draw(text);
}

void InputField::checkForFocus(sf::RenderWindow& w)
{
	sf::Vector2i mpos = mouse.getPosition(w);
	sf::Vector2f mposf = sf::Vector2f((float)mpos.x, (float)mpos.y);
	bool cont = field.getGlobalBounds().contains(mposf);
	(cont) ? focused = true : focused = false;
}
