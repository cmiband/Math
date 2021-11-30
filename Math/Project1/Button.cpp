#include "Button.h"

Button::Button(string t, sf::Vector2f p, sf::Font f, float w, float h, float of) : valText(t), font(f), buttonWidth(w), buttonHeight(h), leftOffset(of)
{
	button = sf::RectangleShape(sf::Vector2f(buttonWidth, buttonHeight));
	button.setFillColor(sf::Color::White);
	button.setPosition(p);

	text.setFont(font);
	text.setString(valText);
	text.setFillColor(color);
	text.setPosition(sf::Vector2f(p.x+leftOffset, p.y));
}

bool Button::checkClick(sf::RenderWindow &w)
{
	sf::Vector2i mpos = mouse.getPosition(w);
	sf::Vector2f mposf = sf::Vector2f((float)mpos.x, (float)mpos.y);
	bool cont = button.getGlobalBounds().contains(mposf);

	if (cont && sf::Mouse::isButtonPressed(sf::Mouse::Left)) return true;

	return false;

}

void Button::drawOnScreen(sf::RenderWindow* w)
{
	w->draw(button);
	w->draw(text);
}
