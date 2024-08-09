#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/System/Vector2.hpp>
#include "util.cpp"

const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;

int main()
{
    auto mainWindow = sf::RenderWindow(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT, 32u), "CMake SFML asdfProject");

    sf::CircleShape mainShape(200.0f);
    mainShape.setFillColor(sf::Color::Red);
    mainWindow.setFramerateLimit(144);

    sf::Font font;
    if(!font.loadFromFile("assets/fonts/Acme-Regular.ttf")) {
        return EXIT_FAILURE;
    }

    sf::Text text;
    text.setFont(font);
    text.setString("Woot");

    // set the character size
    text.setCharacterSize(24); // in pixels, not points!

    // set the color
    text.setFillColor(sf::Color::White);

    // set the text style
    text.setStyle(sf::Text::Bold);


    // colors
    float redSteps = SCREEN_WIDTH % 255;
    float blueSteps = SCREEN_HEIGHT % 255;
    int color = 0;

    while (mainWindow.isOpen())
    {
        for (auto event = sf::Event(); mainWindow.pollEvent(event);)
        {
            if (event.type == sf::Event::Closed)
            {
                mainWindow.close();
            }
        }

        sf::Vector2i mousePos = sf::Mouse::getPosition(mainWindow);
        sf::Vector2f worldMouse = mainWindow.mapPixelToCoords(mousePos);
        // sf::Vector2f worldMouse = mainWindow.mapCoordsToPixel(mousePos);
        text.setString( std::to_string(redSteps) );
        text.setString( ts_util::getMousePositionString(worldMouse));

        mainWindow.clear(sf::Color(0, 0, 0));
        mainWindow.draw(text);
        mainWindow.display();

        color++;
    }
}
