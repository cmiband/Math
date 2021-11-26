#include "Button.h"

Button::Button(string t, sf::Vector2f p) : valText(t)
{
	click = false;

	button = sf::RectangleShape(sf::Vector2f(40.0f, 20.0f));
	button.setFillColor(sf::Color::White);
	button.setPosition(p);

	text.setString(valText);
	text.setFillColor(color);
	text.setPosition(p);
}

bool Button::getClick()
{
	return click;
}

void Button::drawOnScreen(sf::RenderWindow* w)
{
	w->draw(button);
	w->draw(text);
}
