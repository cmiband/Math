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
	figures fig = figures::POINT;

	sf::RenderWindow window(sf::VideoMode(800, 600), "Math");
	window.setFramerateLimit(30);

	Button choosePoint("Point", sf::Vector2f(10.0f, 440.0f), font, 80.0f, 40.0f);
	Button chooseCircle("Circle", sf::Vector2f(170.0f, 440.0f), font, 80.0f, 40.0f);
	Button chooseLine("Line", sf::Vector2f(310.0f, 440.0f), font, 80.0f, 40.0f);
	Button submit("Submit", sf::Vector2f(550.0f, 400.0f), font, 100.0f, 40.0f);

	while (window.isOpen()) {
		sf::Event event;

		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				window.close();
			}
		}

		window.clear(bgColor);

		window.draw(coordsRect);

		choosePoint.drawOnScreen(&window); chooseCircle.drawOnScreen(&window); chooseLine.drawOnScreen(&window); submit.drawOnScreen(&window);

		window.display();
	}

	return 0;
}
