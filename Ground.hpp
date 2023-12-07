#include <SFML/Graphics.hpp>

class Ground : public sf::Sprite
{
private:
    sf::Texture groundTexture;

public:
    int width = 96,
        height = 76;

    sf::IntRect grass = sf::IntRect(95, 720, width, height);
    
    Ground()
    {
        groundTexture.loadFromFile("resources/map.png");
        this->setTexture(groundTexture);
    }

    void setTiles(sf::IntRect groundSprite)
    {
        this->setTextureRect(groundSprite);
    }
} ground;
