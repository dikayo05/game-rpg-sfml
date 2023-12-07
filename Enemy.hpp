#pragma once

#include <SFML/Graphics.hpp>

class Enemy : public sf::Sprite
{
private:
    int health = 100;

public:
    int width = 180,
        height = 180;
    float moveSpeed = 2.f,
          moveDistance = 0.f,
          scale = 0.5f;
    bool isMove = false,
         toRight;

    sf::Texture playerTexture;

    // Idle Sprite
    sf::IntRect spriteIdleUp = sf::IntRect(0, 540, width, height);
    sf::IntRect spriteIdleDown = sf::IntRect(0, 0, width, height);
    sf::IntRect spriteIdleLeft = sf::IntRect(0, 180, width, height);
    sf::IntRect spriteIdleRight = sf::IntRect(0, 360, width, height);

    // Move Sprite
    sf::IntRect spriteMoveUp = sf::IntRect(180, 540, width, height);
    sf::IntRect spriteMoveDown = sf::IntRect(180, 0, width, height);
    sf::IntRect spriteMoveLeft = sf::IntRect(180, 180, width, height);
    sf::IntRect spriteMoveRight = sf::IntRect(180, 360, width, height);

    sf::IntRect spriteDirection = spriteIdleDown;

    Enemy()
    {
        playerTexture.loadFromFile("resources/player.png");

        this->setTexture(playerTexture);
        this->setTextureRect(spriteIdleDown);
        this->setScale(scale, scale);
        this->setOrigin(width / 2, height / 2);
    }

    void spriteIdle(sf::IntRect spriteDirection) { this->setTextureRect(spriteDirection); }
    void spriteMove(sf::IntRect spriteDirection) { this->setTextureRect(spriteDirection); }

    void controller()
    {
    }
} enemy;
