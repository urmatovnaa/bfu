#include <SFML/Graphics.hpp>
#include "inc/Circle.hpp"
#include "inc/Rectangle.hpp"
#include "inc/Rhombus.hpp"
#include <chrono>
#include <thread>

int main()
{   srand(time(0));
	sf::RenderWindow m_window;
	int width = 1000;
	int height = 1000;
	m_window.create(sf::VideoMode(width, height), "GAME!!!!");
	sf::WindowHandle handle = m_window.getSystemHandle();

	mt::Circle c1(700, 400, 90, 2000);
	mt::Rectangle r1(400, 300, 200, 100, 100000);
	mt::Rhombus romb(700, 500, 90, 200000);

	m_window.clear(sf::Color::Black);
	m_window.draw(c1.Get());
	m_window.draw(r1.Get());
	m_window.draw(romb.Get());
	m_window.display();

	std::this_thread::sleep_for(std::chrono::seconds(2));
	sf::Clock clock;

	while (m_window.isOpen())
	{
		sf::Event event;
		while (m_window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				m_window.close();
		}

		float dt = clock.getElapsedTime().asSeconds();
		clock.restart();

		r1.Move(dt, width, height);
		c1.Move(dt, width, height);
		romb.Move(dt, width, height);
        	
		r1.TouchBorder(width, height);
		c1.TouchBorder(width, height);	
		romb.TouchBorder(width, height);

		m_window.clear(sf::Color::Black);
		m_window.draw(c1.Get());
		m_window.draw(r1.Get());
		m_window.draw(romb.Get());
		m_window.display();
	}
	return 0;
}