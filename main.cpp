#include <SFML/Graphics.hpp>
#include "Ground.hpp"
#include "Player.hpp"
#include "Enemy.hpp"

int main()
{
	sf::View camera;
	sf::Clock clock; // starts the clock

	// Window
	unsigned short windowWidth = 800, windowHeight = 600;
	sf::RenderWindow window(sf::VideoMode(windowWidth, windowHeight), "haha");
	window.setVerticalSyncEnabled(true);

	// Ground
	ground.setTiles(ground.grass);

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

		sf::Time elapsed = clock.getElapsedTime();

		if (elapsed.asSeconds() > 2.f)
			player.setPosition(0.f, 0.f);

		camera.setCenter(player.getPosition().x, player.getPosition().y);

		enemy.controller();
		player.controller();

		window.setView(camera);

		window.clear();
		window.draw(ground);
		if (player.getPosition().y > enemy.getPosition().y)
		{
			window.draw(enemy);
			window.draw(player);
		}
		else
		{
			window.draw(player);
			window.draw(enemy);
		}
		window.display();
	}

	return 0;
}
