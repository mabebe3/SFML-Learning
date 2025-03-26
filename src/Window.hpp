#ifndef WINDOW_HPP
#define WINDOW_HPP

#include  <SFML/Graphics.hpp>

class WindowManager {
private:
	sf::RenderWindow window;
public:
	WindowManager(unsigned int width, unsigned int height, std::string name);

	sf::RenderWindow& getWindow(); // get window object reference
	sf::Vector2u getSize() const; // get size for scaling renders

	void pollEvents(); // event loop
	bool isOpen() const; // check if open for event loop
	void clear(); // clear graphics
	void display(); // show window
};
//void getWindow();
//
//void openWindow();
//
//void closeWindow();
//
//void escWindow();
//
//void mousePosition();
//
//void fullscreen();

#endif WINDOW_HPP