#include <SFML/Graphics.hpp>
#include "Window.hpp"

int main()
{
    WindowManager windowManager(1920u,1080u,"test");

    while (windowManager.isOpen()) {
        windowManager.pollEvents();
        windowManager.clear();
        windowManager.display();
    }

    return 0;
}
