#pragma once

#include "Random.hpp"

namespace SfmlLab1
{
	class Point
	{
	protected:
		sf::Vector2f position;
		sf::Color color;

	public:
		Point(sf::Vector2f aPosition, sf::Color aColor) : position(aPosition), color(aColor) {}

		virtual void render(sf::RenderWindow& window) {}

		virtual void animate(sf::RenderWindow& window, int cost)
		{
			do {
				position.x += roundf((Random::fRandom() - 0.5) * cost);
			} while (position.x <= 0 || position.x >= 800);
			
			do {
				position.y += roundf((Random::fRandom() - 0.5) * cost);
			} while (position.y <= 0 || position.y >= 600);

			color = sf::Color(Random::ubRandom(), Random::ubRandom(), Random::ubRandom());
		}
	};
}