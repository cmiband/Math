#include "Application.h"

Application::Application(sf::Font f)
{
	formula = "";
	font = f;
	coordsImage.loadFromFile("coords.jpg");
	coordsTexture.loadFromImage(coordsImage);

	coordsRect = sf::RectangleShape(sf::Vector2f(coordsTexture.getSize()));
	coordsRect.setTexture(&coordsTexture);

	formLabel.setFont(font);
	formLabel.setFillColor(sf::Color::Black);
	formLabel.setString(formula);
	formLabel.setPosition(sf::Vector2f(410.0f, 260.0f));
}

int Application::Run()
{
	figures fig = figures::POINT;

	sf::RenderWindow window(sf::VideoMode(800, 600), "Math");
	window.setFramerateLimit(30);

	Button choosePoint("Point", sf::Vector2f(10.0f, 440.0f), font, 80.0f, 40.0f, 15.0f);
	Button chooseCircle("Circle", sf::Vector2f(170.0f, 440.0f), font, 80.0f, 40.0f, 10.0f);
	Button chooseLine("Line", sf::Vector2f(310.0f, 440.0f), font, 80.0f, 40.0f, 18.0f);
	Button submit("Submit", sf::Vector2f(550.0f, 400.0f), font, 100.0f, 40.0f, 17.0f);

	InputField aParam(font, sf::Vector2f(500.0f, 50.0f), 80.0f, 40.0f, "a: ",30.0f);
	InputField bParam(font, sf::Vector2f(500.0f, 120.0f), 80.0f, 40.0f, "b: ", 30.0f);
	InputField cradius(font, sf::Vector2f(500.0f, 190.0f), 80.0f, 40.0f, "radius: ", 80.0f);

	DirectLine* line;
	Point* point;
	Circle* circle;

	float a = 0, b = 0, r=0;

	string tempA = "", tempB = "", tempR = "";
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
				r = cradius.getValue();
				drawPoint = false;
				drawLine = false;
				drawCircle = true;
			}
		} break;
		}

		window.clear(bgColor);

		window.draw(coordsRect);

		choosePoint.drawOnScreen(&window); 
		chooseCircle.drawOnScreen(&window);
		chooseLine.drawOnScreen(&window); 
		submit.drawOnScreen(&window);
		
		aParam.drawOnScreen(&window); 
		bParam.drawOnScreen(&window);
		if (fig == figures::POINT) {
			aParam.setLabel("X: ");
			bParam.setLabel("Y: ");
		}
		else {
			aParam.setLabel("a: ");
			bParam.setLabel("b: ");
		}
		if (fig == figures::CIRCLE)
			cradius.drawOnScreen(&window);
		aParam.update(event, window); 
		bParam.update(event, window); 
		cradius.update(event, window);

		if (drawPoint) {
			point = new Point(a, b);
			point->drawOnScreen(&window);
		}
		if (drawLine) {
			tempA = to_string(a); tempA.erase(tempA.begin() + 3, tempA.end());
			tempB = to_string(b); tempB.erase(tempB.begin() + 3, tempB.end());
			
			formula = "y = " +tempA + "*x+" + tempB;
			formLabel.setString(formula);
			line = new DirectLine(-5.0f, a, b);
			line->drawOnScreen(&window);
			window.draw(formLabel);
		}
		if (drawCircle) {
			tempA = to_string(a); tempA.erase(tempA.begin() + 3, tempA.end());
			tempB = to_string(b); tempB.erase(tempB.begin() + 3, tempB.end());
			tempR = to_string(r*r); tempR.erase(tempR.begin() + 3, tempR.end());
			formula = "y=(x-" + tempA + ")^2+(y-" + tempB + ")^2="+tempR;
			formLabel.setString(formula);
			circle = new Circle(r, a, b);
			circle->drawOnScreen(&window);
			window.draw(formLabel);
		}

		window.display();
	}

	return 0;
}
