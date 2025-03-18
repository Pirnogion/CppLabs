#pragma once

#include <cmath>

#include "Circle.hpp"

namespace SfmlLab1
{
	class Ring : public Circle
	{
	protected:
		unsigned width;

	public:
		Ring(unsigned aRadius, float aAngle, unsigned aWidth, sf::Vector2f aPosition, sf::Color aColor) : Circle(aRadius, aAngle, aPosition, aColor), width(aWidth) {}

		void render(sf::RenderWindow& window) override // Переопределение поведения вирутальной функции
		{
			ArcShape outer(radius);
			outer.setFillColor(color);
			outer.setPosition(position);
			outer.setArc(90, angle);
			window.draw(outer);
			
			if (width < radius)
			{
				unsigned innerRadius = radius - width;

				ArcShape inner(innerRadius);
				inner.setFillColor(sf::Color::Black);
				inner.setPosition(position);
				inner.setArc(90, angle);
				window.draw(inner);
			}
		}
	};
}