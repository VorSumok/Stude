#pragma once
#include <SFML/Graphics.hpp>

namespace ms
{

	class Rectangle
	{
	public:
		Rectangle(int x, int y, float Long, float width, int SPEED)
		{
			m_x = x;
			m_y = y;
			m_Long = Long;
			m_width = width;
			m_SPEED = SPEED;
			m_rectangle = new sf::RectangleShape(sf::Vector2f(m_Long, m_width));
			m_rectangle->setOrigin(m_Long / 2, m_width / 2);
			m_rectangle->setFillColor(sf::Color::Green);
			m_rectangle->setPosition(m_x, m_y);
		}

		~Rectangle()
		{
			delete m_rectangle;
		}

		sf::RectangleShape* Get() { return m_rectangle; }

		void Move()
		{
			m_y += m_SPEED;
			m_rectangle->setPosition(m_x, m_y);
		}

		void SetY(int y)
		{
			m_y = y;
			m_rectangle->setPosition(m_x, m_y);
		}

		int GetY() { return m_y; }

		void SetSPEED(int SPEED)
		{
			m_SPEED = SPEED;
		}

	private:
		int m_x, m_y, m_SPEED;
		float m_Long, m_width;
		sf::RectangleShape* m_rectangle;
	};

}