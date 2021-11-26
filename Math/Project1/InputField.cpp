#include "InputField.h"

InputField::InputField(sf::Font f, sf::Vector2f p)
{
	focused = false;
	font = f;
	value = "";

	maximumAmountOfLetters = 5;
	field = sf::RectangleShape(sf::Vector2f(75.0f, 30.0f));
	field.setFillColor(sf::Color::White);
	field.setPosition(p);

	text.setFont(font);
	text.setPosition(p);
	text.setString(value);
	text.setFillColor(color);
}

void InputField::drawOnScreen(sf::RenderWindow* w)
{
	w->draw(field);
	w->draw(text);
}

void InputField::update(sf::Event &ev, sf::RenderWindow &w)
{
	sf::Vector2i mpos = mouse.getPosition(w);
	sf::Vector2f mposf = sf::Vector2f((float)mpos.x, (float)mpos.y);
	bool cont = field.getGlobalBounds().contains(mposf);
	if (cont && sf::Mouse::isButtonPressed(sf::Mouse::Left)) focused = true;
	if (!cont && sf::Mouse::isButtonPressed(sf::Mouse::Left)) focused = false;

	if (focused) {
		if (ev.type == sf::Event::TextEntered && !sf::Keyboard::isKeyPressed(sf::Keyboard::BackSpace)) {
			if (ev.text.unicode < 128) {
				if (value.size() < maximumAmountOfLetters) {
					value += static_cast<char>(ev.text.unicode);
					text.setString(value);
				}
			}
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::BackSpace)) {
			if (value.size() > 0) {
				value.erase(value.end()-1);
				text.setString(value);
			}
		}
	}
}

void InputField::reset()
{
	value = "";
	text.setString(value);
}

void InputField::setPos(sf::Vector2f p)
{
	field.setPosition(p);
	text.setPosition(p);
}

string InputField::getValue()
{
	return value;
}
