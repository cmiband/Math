#include "Application.h"

Application::Application()
{
	coordsImage.loadFromFile("coords.jpg");
	coordsTexture.loadFromImage(coordsImage);

	coordsRect = sf::RectangleShape(sf::Vector2f(coordsTexture.getSize()));
	coordsRect.setTexture(&coordsTexture);
}

int Application::Run()
{
	cout << coordsImage.getSize().x << " " << coordsImage.getSize().y << endl;
	sf::RenderWindow window(sf::VideoMode(800, 600), "Math");
	window.setFramerateLimit(30);

	Point point1(coordinates::toCoordinate(1.5,true)*CENT_LENGHT,coordinates::toCoordinate(1,false)*CENT_LENGHT);
	DirectLine line1(-5, 2, 0);
	cout << coordinates::toCoordinate(-5, true) * CENT_LENGHT << endl;
	cout << coordinates::toCoordinate(1, false) * CENT_LENGHT;

	while (window.isOpen()) {
		sf::Event event;

		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				window.close();
			}
		}

		window.clear(bgColor);

		window.draw(coordsRect);
		window.draw(point1.getShape());
		window.draw(line1.getShape());

		window.display();
	}

	return 0;
}
