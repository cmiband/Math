#include <SFML/Graphics.hpp>
#include "Application.h"

int main() {

	Application app;
	Application* ptr = &app;

	ptr->Run();

	return 0;
}