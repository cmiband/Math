#include "Circle.h"

Circle::Circle(float r, float x, float y) : radius(r), posx(x), posy(y)
{
	circ = sf::CircleShape(radius*coordinates::CENT_LENGHT);
	circ.setFillColor(sf::Color(0,0,0,0));
	circ.setOutlineThickness(3.0f);
	circ.setOutlineColor(color);
	
	float tempx = coordinates::toCoordinate(posx, true) * coordinates::CENT_LENGHT;
	float tempy = coordinates::toCoordinate(posy, false) * coordinates::CENT_LENGHT;

	circ.setOrigin(sf::Vector2f(radius*coordinates::CENT_LENGHT, radius*coordinates::CENT_LENGHT)); 
	circ.setPosition(sf::Vector2f(tempx, tempy));
}

void Circle::drawOnScreen(sf::RenderWindow* w)
{
	w->draw(circ);
}
