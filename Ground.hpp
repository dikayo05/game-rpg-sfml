#include <SFML/Graphics.hpp>

class Ground : public sf::Sprite
{
private:
public:
    int width = 96,
        height = 76;

    sf::IntRect groundGrass = sf::IntRect(95, 720, width, height);
    sf::Texture groundTexture;

    
    Ground()
    {
        groundTexture.loadFromFile("resources/map.png");
        for (int i = 0; i < 500; i += width)
        {
            this->setTexture(groundTexture);
            this->setPosition(i, i);
        }
    }

    void setTiles()
    {
        this->setTextureRect(groundGrass);
    }
} ground;
