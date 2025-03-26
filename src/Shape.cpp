#include "SFML/Graphics.hpp"
#include "Window.hpp"
#include "Shape.hpp"
#include <random>
#include <cmath>
#include <numbers>

constexpr double pi = std::numbers::pi;

Shape::Shape() : vertexArray(sf::PrimitiveType::TriangleFan), shapeColor(sf::Color::White) {}

// const data memebers must be initialized with init list
Shape::Shape(const std::vector<sf::Vector2f>& points) : points(points), vertexArray(sf::PrimitiveType::TriangleFan), shapeColor(sf::Color::White) {
	updateVertexArray();
}

void Shape::updateVertexArray() {
	vertexArray.clear();

	for (const auto& point : points) {
		vertexArray.append(sf::Vertex(point, shapeColor));
	}

	if (points.size() > 2 && vertexArray.getPrimitiveType() == sf::PrimitiveType::TriangleFan) {
		vertexArray.append(sf::Vertex(points.front(), shapeColor));
	}
}

// manual shape creation
void Shape::addPoints(const sf::Vector2f& point) {
	points.push_back(point);
	updateVertexArray();
}
void Shape::setPoints(const std::vector<sf::Vector2f>& newPoints) {
	this->points = newPoints;
	updateVertexArray();
}

void Shape::setColor(const sf::Color& color) {
	shapeColor = color;
	updateVertexArray();
}

void Shape::draw(sf::RenderWindow& window) const {
	window.draw(vertexArray);
}

float Shape::genRandBound(float min, float max) const {
	std::random_device rand;
	std::mt19937 rng(rand());
	std::uniform_real_distribution<float> uni(min, max);
	float rf = uni(rng);
	return rf;
}

void Shape::randomColor() {
	shapeColor = sf::Color::Color(genRandBound(0, 255), genRandBound(0, 255), genRandBound(0, 255), genRandBound(50,255));
}
void Shape::randomShape() {
	for (int i = 0; i < (int)genRandBound(3, 10); i++) {
		sf::Vector2f point(genRandBound(200, 1000), genRandBound(200, 1000));
		addPoints(point);
	}
	randomColor();
	updateVertexArray();
}



void Shape::createCircle(sf::Vector2f& origin, unsigned int resolution, float radius) {
	//float theta = 360.0f / resolution;
	double deltaTheta = 2 * pi / resolution;
	sf::Vector2f shift;
	sf::Vector2f p;

	for (int i = 0; i < resolution; i++) {
		shift = { radius * (float)cos(deltaTheta * i) , radius * (float)sin(deltaTheta * i) };
		p = origin + shift;
		addPoints(p);
	}
}

void Shape::createRoundRect(sf::Vector2f& origin, unsigned int resolution, float radius, float width, float height) {
	
	double deltaTheta = 2 * pi / resolution / 4;
	float deltaY = (height - 2 * radius)/2;
	float deltaX = (width - 2 * radius)/2;
	sf::Vector2f topright = {deltaX, deltaY};
	sf::Vector2f topleft = {-deltaX, deltaY};
	sf::Vector2f bottomleft = {-deltaX, -deltaY};
	sf::Vector2f bottomright = {deltaX, -deltaY};


	sf::Vector2f shift;
	sf::Vector2f p0;
	sf::Vector2f p;

	// top right
	int i = 0;
	for (i; i < resolution; i++) {
		shift = { radius * (float)cos(deltaTheta * i) , radius * (float)sin(deltaTheta * i) };
		p0 = origin + topright;
		p = p0 + shift;
		addPoints(p);
	}
	// top left
	for (i; i < resolution * 2; i++) {
		shift = { radius * (float)cos(deltaTheta * i) , radius * (float)sin(deltaTheta * i) };
		p0 = origin + topleft;
		p = p0 + shift;
		addPoints(p);
	}
	// bottom left
	for (i; i < resolution * 3; i++) {
		shift = { radius * (float)cos(deltaTheta * i) , radius * (float)sin(deltaTheta * i) };
		p0 = origin + bottomleft;
		p = p0 + shift;
		addPoints(p);
	}
	// bottom right
	for (i; i < resolution * 4; i++) {
		shift = { radius * (float)cos(deltaTheta * i) , radius * (float)sin(deltaTheta * i) };
		p0 = origin + bottomright;
		p = p0 + shift;
		addPoints(p);
	}
}
