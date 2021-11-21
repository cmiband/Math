#include "Application.h"

void Application::DrawLine(DirectLine *line, sf::RenderWindow* window)
{
	sf::Vertex temp[2] = {
		line->start(),
		line->end()
	};
	
	window->draw(temp, 2, sf::Lines);
}

Application::Application()
{
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
	DirectLine line(-5.0f, 2.0f, 1.0f);

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
		DrawLine(&line, &window);

		window.display();
	}

	return 0;
}
