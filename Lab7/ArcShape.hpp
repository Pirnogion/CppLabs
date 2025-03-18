#pragma once

#include <cmath>

namespace SfmlLab1
{
	class ArcShape : public sf::ConvexShape // Расширение поведения SFML-класса форм
	{
	protected:
		float radius;

	public:
		ArcShape(float aRadius) : radius(aRadius) {}

		void setArc(float startAngle, float endAngle) {
			auto pointCount = 30;

			setPointCount(pointCount + 2);

			setPoint(0, sf::Vector2f(0, 0));

			float angleStep = (endAngle - startAngle) / (pointCount - 1);
			for (int i = 0; i < pointCount; ++i) {
				float angle = startAngle + i * angleStep;
				float x = radius * std::cos(angle * 3.14159265359f / 180.0f);
				float y = radius * std::sin(angle * 3.14159265359f / 180.0f);
				setPoint(i + 1, sf::Vector2f(x, y));
			}
		}
	};
}