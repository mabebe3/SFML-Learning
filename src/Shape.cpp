#include "SFML/Graphics.hpp"
#include "Window.hpp"
#include "Shape.hpp"
#include <random>

Shape::Shape() : vertexArray(sf::PrimitiveType::TriangleFan), shapeColor(sf::Color::White) {}

// const data memebers must be initialized with init list
Shape::Shape(const std::vector<sf::Vector2f>& points) : points(points), vertexArray(sf::PrimitiveType::TriangleFan), shapeColor(sf::Color::White) {
	updateVertexArray();
}

// manual shape creation
void Shape::addPoints(const sf::Vector2f& point) {
	points.push_back(point);
	updateVertexArray();
}
void Shape::setPoints(const std::vector<sf::Vector2f>& newPoints) {
	this->points = newPoints;
}

void Shape::setColor(const sf::Color& color) {
	shapeColor = color;
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
		sf::Vector2f point(genRandBound(-100, 100), genRandBound(-100, 100));
		addPoints(point);
	}
	randomColor();
}

void Shape::updateVertexArray() {
	vertexArray.clear();

	for (const auto& point : points) {
		vertexArray.append(sf::Vertex(point, shapeColor));
	}

	if (points.size() > 2 && vertexArray.getPrimitiveType() == sf::TriangleFan) {
		vertexArray.append(sf::Vertex(points.front(), shapeColor));
	}
}