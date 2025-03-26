#ifndef SHAPE_HPP
#define SHAPE_HPP

#include <SFML/graphics.hpp>
#include <vector>
#include <random>

class Shape {
private:
	std::vector<sf::Vector2f> points; // vector to hold 2d points to draw shape from
	sf::VertexArray vertexArray;
	sf::Color shapeColor;

	void updateVertexArray();
public:
	Shape();
	Shape(const std::vector<sf::Vector2f>& points);

	// manual shape creation
	void addPoints(const sf::Vector2f& point);
	void setPoints(const std::vector<sf::Vector2f>& points);
	void setColor(const sf::Color& color);

	void draw(sf::RenderWindow& window) const;

	// automatic shape creation
	//void createShape(sf::Vector2f& origin, std::string shape);
	void createCircle(sf::Vector2f& origin, unsigned int resolution, float radius);
	void createRoundRect(sf::Vector2f& origin, unsigned int resolution, float radius, float width, float height);
	// generated shape creation
	float genRandBound(float min, float max) const;
	void randomColor();
	void randomShape();

};




#endif SHAPE_HPP