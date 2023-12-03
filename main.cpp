#include <SFML/Graphics.hpp>
#include "Ground.hpp"
#include "Player.hpp"
#include "Enemy.hpp"

int main()
{
	sf::View camera;

	// Window
	unsigned short windowWidth = 800, windowHeight = 600;
	sf::RenderWindow window(sf::VideoMode(windowWidth, windowHeight), "haha");
	window.setVerticalSyncEnabled(true);

	// Ground
	ground.setTiles();

	// Player
	player.setPosition(sf::Vector2f(windowWidth / 2, windowHeight / 2));

	// Enemy
	enemy.setPosition(sf::Vector2f(windowWidth - 300, windowHeight / 2));

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
				window.close();
		}

		camera.setCenter(player.getPosition().x, player.getPosition().y);

		enemy.controller();
		player.controller();

		window.setView(camera);

		window.clear();
		window.draw(ground);
		window.draw(enemy);
		window.draw(player);
		window.display();
	}

	return 0;
}
