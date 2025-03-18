#include <SFML/Graphics.hpp>

#include "Random.hpp"
#include "Ring.hpp"

using namespace SfmlLab1;

int main()
{
    Random::init(); // Инициализация ГПСЧ

    Circle circle(50, 45, sf::Vector2f(400, 300), sf::Color::White); // Круг
    Ring ring(90, 80, 10, sf::Vector2f(400, 300), sf::Color::Red); // Кольцо

    auto window = sf::RenderWindow(sf::VideoMode({ 800u, 600u }), "SfmlLab1"); // Объект окна SFML
    window.setFramerateLimit(60); // Частота кадров - 60 fps

    window.clear(); // Залить окно стандартным цветом
    ring.render(window); // Отрисовка кольца и круга
    circle.render(window);
    window.display(); // Отобразить нарисованное

    while (window.isOpen())
    {
        while (const std::optional event = window.pollEvent()) // Обработка событий ОС\SFML
        {
            if (event->is<sf::Event::Closed>())
            {
                window.close();
            }

            if (event->is<sf::Event::KeyPressed>()) // Анимация при зажатой кнопке (любой)
            {
                window.clear();
                ring.animate(window, 60);
                ring.render(window);
                circle.animate(window, 100);
                circle.render(window);
                window.display();
            }
        }

        sf::sleep(sf::milliseconds(300)); // Задержка 300 мс
    }

	return 0;
}
