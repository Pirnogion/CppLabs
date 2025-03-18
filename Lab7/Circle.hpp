#pragma once

#include "Random.hpp"
#include "Point.hpp"
#include "ArcShape.hpp"

namespace SfmlLab1
{
	class Circle : public Point // Публичное наследование, т.е. модификаторы доступа не изменяются
	{
	protected: // Защищенные члены класса, видимы только наследникам
		unsigned radius;
		float angle;

	public: // Публичные члены класса, видимы везде
		Circle(unsigned aRadius, float aAngle, sf::Vector2f aPosition, sf::Color aColor) : Point(aPosition, aColor), radius(aRadius), angle(aAngle) {}

		void render(sf::RenderWindow& window) override
		{
			ArcShape arc(radius);
			arc.setFillColor(color);
			arc.setPosition(position);
			arc.setArc(0, angle);
			window.draw(arc);
		}

		void animate(sf::RenderWindow& window, int cost) override
		{
			Point::animate(window, cost);

			angle = Random::fRandom() * 360.0f;
		}
	};
}