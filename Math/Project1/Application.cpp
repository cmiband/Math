#include "Application.h"

Application::Application(sf::Font f)
{
	font = f;
	coordsImage.loadFromFile("coords.jpg");
	coordsTexture.loadFromImage(coordsImage);

	coordsRect = sf::RectangleShape(sf::Vector2f(coordsTexture.getSize()));
	coordsRect.setTexture(&coordsTexture);
}

int Application::Run()
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "Math");
	window.setFramerateLimit(30);

	Point point1(coordinates::toCoordinate(1.5,true)*CENT_LENGHT,coordinates::toCoordinate(1,false)*CENT_LENGHT);
	DirectLine line(-5.0f, -1.0f, 1.0f);
	Circle crc(3.0f, 1.0f, 1.0f);
	InputField input1(font, sf::Vector2f(500.0f, 50.0f));

	while (window.isOpen()) {
		sf::Event event;

		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				window.close();
			}
		}

		window.clear(bgColor);

		window.draw(coordsRect);
		point1.drawOnScreen(&window);
		line.drawOnScreen(&window);
		crc.drawOnScreen(&window);

		input1.update(event, window);
		input1.drawOnScreen(&window);

		window.display();
	}

	return 0;
}
