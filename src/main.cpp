#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/System/Vector2.hpp>
#include <iostream>

const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;

int main()
{
    auto mainWindow = sf::RenderWindow(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT, 32u), "Cool Stuff");

    sf::Vector2i mousePos = {1, 1};

    sf::CircleShape mainShape(16.0f);
    mainShape.setFillColor(sf::Color::Red);
    mainWindow.setFramerateLimit(144);

    // cout works in windows ;)
    //std::cout << "hello";

    sf::Font font;
    if (!font.loadFromFile("assets/fonts/Acme-Regular.ttf"))
    {
        return EXIT_FAILURE;
    }

    sf::Text mousePosText;
    sf::String inputBuffer = "";
    mousePosText.setFont(font);

    // set the character size
    mousePosText.setCharacterSize(24); // in pixels, not points!

    // set the color
    mousePosText.setFillColor(sf::Color::White);

    // set the text style
    mousePosText.setStyle(sf::Text::Regular);

    sf::Text userText = mousePosText;
    userText.setCharacterSize(18);
    userText.setPosition({SCREEN_HEIGHT - 20, 0});

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

            if (event.type == sf::Event::TextEntered)
            {
                if (event.text.unicode < 128)
                {
                    char n = static_cast<char>(event.text.unicode);
                    userText.setString(userText.getString() + n);
                }
            }

            if (event.type == sf::Event::LostFocus)
            {
                inputBuffer = userText.getString();
                userText.setString("Game Paused");
            }

            if (event.type == sf::Event::GainedFocus)
            {
                userText.setString(inputBuffer);
                inputBuffer = "";
            }

            if (event.type == sf::Event::MouseMoved)
            {
                mousePos = { event.mouseMove.x, event.mouseMove.y };
                mousePosText.setString(std::to_string(mousePos.x) + ", " + std::to_string(mousePos.y));
            }
        }

        mainShape.setPosition( (float)mousePos.x, (float)mousePos.y );

        mainWindow.clear(sf::Color(0, 0, 20));
        mainWindow.draw(mousePosText);
        mainWindow.draw(userText);
        mainWindow.draw(mainShape);
        mainWindow.display();

        color++;
    }
}

void render()
{
}
