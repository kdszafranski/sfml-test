#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/System/Vector2.hpp>

int main()
{
    auto mainWindow = sf::RenderWindow(sf::VideoMode(800, 600, 32u), "CMake SFML asdfProject");

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

    while (mainWindow.isOpen())
    {
        for (auto event = sf::Event(); mainWindow.pollEvent(event);)
        {
            if (event.type == sf::Event::Closed)
            {
                mainWindow.close();
            }
        }

        // sf::Vector2i mousePos = sf::Mouse::getPosition();

        mainWindow.clear();
        // mainWindow.draw(mainShape);
        mainWindow.draw(text);
        mainWindow.display();
    }
}
