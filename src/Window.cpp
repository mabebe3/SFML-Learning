#include "Window.hpp"
#include "SFML/Graphics.hpp"
#include <SFML/Window/Event.hpp>

WindowManager::WindowManager(unsigned int width, unsigned int height, std::string name) {
	if (width < 0 or height < 0) {
		//break
	} 
	window.create(sf::VideoMode({ width, height }), name);
	// other settings
}

bool WindowManager::isOpen() const {
	return window.isOpen();
}

sf::RenderWindow& WindowManager::getWindow() {
	return window;
}

sf::Vector2u WindowManager::getSize() const {
	return window.getSize();
}

void WindowManager::clear() {
	window.clear();
}

void WindowManager::display() {
	window.display();
}

void WindowManager::pollEvents() {
	//sf::Event event;
	/*std::optional<sf::Event> event;
	while (window.pollEvent(event)) {
		if (event.type == sf::Event::Closed) {
			window.close();
		}
	}*/

	while (std::optional event = window.pollEvent()) {
		if (event->is<sf::Event::Closed>()) {
			window.close();
		}
	}
}