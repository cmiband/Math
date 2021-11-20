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

	sf::Vertex line[2];
	line[0].position = sf::Vector2f(0, 400);
	line[0].color = sf::Color::Black;
	line[1].position = sf::Vector2f(400, 0);
	line[1].color = sf::Color::Black;

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
		window.draw(line,2,sf::Lines);

		window.display();
	}

	return 0;
}
