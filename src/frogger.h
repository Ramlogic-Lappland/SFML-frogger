#pragma once
#include <SFML/Graphics.hpp>

namespace frogger
{
	struct Player
	{
		sf::Vector2f size = {0.f, 0.f};
		sf::Vector2f pos = {0.f, 0.f};

		int lives = 0;
	};

	struct Obstacle
	{
		sf::Vector2f size = { 0.f, 0.f };
		sf::Vector2f pos = { 0.f, 0.f };
	};

	void run();
}
