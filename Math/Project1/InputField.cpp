#include "InputField.h"

InputField::InputField(sf::Font f, sf::Vector2f p, float w, float h, string l, float lOffset) : font(f), width(w), height(h), labelVal(l)
{
	focused = false;
	value = "";

	maximumAmountOfLetters = 4;
	field = sf::RectangleShape(sf::Vector2f(width, height));
	field.setFillColor(sf::Color::White);
	field.setPosition(p);

	text.setFont(font);
	text.setPosition(sf::Vector2f(p.x+width/7,p.y));
	text.setString(value);
	text.setFillColor(color);

	label.setFont(font);
	label.setPosition(sf::Vector2f(p.x - lOffset, p.y));
	label.setString(labelVal);
	label.setFillColor(color);
}

void InputField::drawOnScreen(sf::RenderWindow* w)
{
	w->draw(field);
	w->draw(text);
	w->draw(label);
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

void InputField::setLabel(string val)
{
	labelVal = val;
	label.setString(labelVal);
}

float InputField::getValue()
{
	return stof(value);
}
