#include <SFML/Graphics.hpp>

#include "Random.hpp"
#include "Ring.hpp"

using namespace SfmlLab1;

int main()
{
    Random::init();

    Circle circle(50, 45, sf::Vector2f(400, 300), sf::Color::White);
    Ring ring(90, 80, 10, sf::Vector2f(400, 300), sf::Color::Red);

    auto window = sf::RenderWindow(sf::VideoMode({ 800u, 600u }), "SfmlLab1");
    window.setFramerateLimit(60);

    window.clear();
    ring.render(window);
    circle.render(window);
    window.display();

    while (window.isOpen())
    {
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
            {
                window.close();
            }

            if (event->is<sf::Event::KeyPressed>())
            {
                window.clear();
                ring.animate(window, 60);
                ring.render(window);
                circle.animate(window, 100);
                circle.render(window);
                window.display();
            }
        }

        sf::sleep(sf::milliseconds(300));
    }

	return 0;
}
