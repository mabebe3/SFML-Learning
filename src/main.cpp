#include <SFML/Graphics.hpp>
#include "Window.hpp"
#include "Shape.hpp"

int main()
{
    WindowManager windowManager(1920u,1080u,"test");
    Shape roundRect;
    //Shape circle;
    sf::Vector2f origin = { 500.0f,500.0f };
    roundRect.createRoundRect(origin, 10, 50, 1000, 400);
    /*circle.createCircle(origin, 50, 100.0f);
    circle.setColor(sf::Color::Red);*/
    /*std::vector<sf::Vector2f> roundRectPoints = {
       

    };*/
    /*std::vector<sf::Vector2f> trianglePoints = {
       {500.f, 400.f},
       {400.f, 500.f},
       {300.f, 400.f}
    };*/

    /*Shape triangle(trianglePoints);
    triangle.setColor(sf::Color::Cyan);*/
    /*Shape randShape;
    Shape randShape1;
    randShape.randomShape();
    randShape1.randomShape();*/
    //Shape roundRect(roundRectPoints);
    while (windowManager.isOpen()) {
        windowManager.pollEvents();
        windowManager.clear();
        //triangle.draw(windowManager.getWindow());
        /*randShape.draw(windowManager.getWindow());
        randShape1.draw(windowManager.getWindow());*/
        /*roundRect.draw(windowManager.getWindow());*/
        //circle.draw(windowManager.getWindow());
        roundRect.draw(windowManager.getWindow());
        windowManager.display();
    }

    return 0;
}
