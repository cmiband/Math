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

	InputField aParam(font, sf::Vector2f(500.0f, 50.0f), 80.0f, 40.0f, "a: ");
	InputField bParam(font, sf::Vector2f(500.0f, 120.0f), 80.0f, 40.0f, "b: ");

	DirectLine* line;
	Point* point;
	Circle* circle;

	float a = 0, b = 0;

	bool drawPoint = false, drawLine = false, drawCircle = false;
	bool submitBool = false;
	while (window.isOpen()) {
		sf::Event event;

		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				window.close();
			}
		}

		if (choosePoint.checkClick(window)) fig = figures::POINT;
		if (chooseLine.checkClick(window)) fig = figures::LINE;
		if (chooseCircle.checkClick(window)) fig = figures::CIRCLE;

		submitBool = submit.checkClick(window);

		switch (fig) {
		case figures::POINT: {
			if (submitBool) {
				a = aParam.getValue();
				b = bParam.getValue();
				drawPoint = true;
				drawLine = false;
				drawCircle = false;
			}
		} break;

		case figures::LINE: {
			if (submitBool) {
				a = aParam.getValue();
				b = bParam.getValue();
				drawPoint = false;
				drawLine = true;
				drawCircle = false;
			}
		} break;
			
		case figures::CIRCLE: {
			if (submitBool) {
				a = aParam.getValue();
				b = bParam.getValue();
				drawPoint = false;
				drawLine = false;
				drawCircle = true;
			}
		} break;
		}

		window.clear(bgColor);

		window.draw(coordsRect);

		choosePoint.drawOnScreen(&window); chooseCircle.drawOnScreen(&window); chooseLine.drawOnScreen(&window); submit.drawOnScreen(&window);
		aParam.drawOnScreen(&window); bParam.drawOnScreen(&window);
		aParam.update(event, window); bParam.update(event, window);

		if (drawPoint) {

		}
		if (drawLine) {
			line = new DirectLine(-5.0f, a, b);
			line->drawOnScreen(&window);
		}
		if (drawCircle) {
			circle = new Circle(3.0f, a, b);
			circle->drawOnScreen(&window);
		}

		window.display();
	}

	return 0;
}
