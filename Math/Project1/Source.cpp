#include <SFML/Graphics.hpp>
#include "Application.h"

int main() {

	sf::Font font;
	if (!font.loadFromFile("BebasNeue-Regular.ttf"))
		return EXIT_FAILURE;

	Application *app = new Application(font);

	app->Run();

	return 0;
}