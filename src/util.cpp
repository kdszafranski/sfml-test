#include <SFML/System.hpp>

namespace ts_util
{
    sf::String getMousePositionString(sf::Vector2f &position)
    {
        sf::String xOut(std::to_string(position.x));
        sf::String yOut(std::to_string(position.y));

        return xOut + ", " + yOut;
    }
}