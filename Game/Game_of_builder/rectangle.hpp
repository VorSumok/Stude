#pragma once
#include <SFML/Graphics.hpp>

namespace ms
{

	class Rectangle
	{
	public:
		Rectangle(int x, int y, float Long, float width, bool Physics, int r, int g, int b, int opacity)
		{
			m_x = x;
			m_y = y;
			m_r = r;
			m_g = g;
			m_b = b;
			m_o = opacity;
			m_Long = Long;
			m_width = width;
			m_Physics = Physics;
			m_rectangle = new sf::RectangleShape(sf::Vector2f(m_Long, m_width));
			m_rectangle->setFillColor(sf::Color::Color(m_r, m_g, m_b, m_o));
			m_rectangle->setPosition(m_x, m_y);
		}

		~Rectangle()
		{
			delete m_rectangle;
		}

		sf::RectangleShape* Get() { return m_rectangle; }


		int GetY() { return m_y; }
		int GetX() { return m_x; }

		void SetPhysics(int Physics)
		{
			m_Physics = Physics;
			m_rectangle->setFillColor(sf::Color::Color(210, 105, 30));
		}
		bool GetPhisics() { return m_Physics;}

		int SetColor(int r,int g,int b, int opacity)
		{
			m_r = r;
			m_g = g;
			m_b = b;
			m_o = opacity;
			m_rectangle->setFillColor(sf::Color::Color(m_r, m_g, m_b, m_o));
		}

	private:
		int m_x, m_y, m_r, m_g, m_b, m_o;
		float m_Long, m_width;
		bool m_Physics;
		sf::RectangleShape* m_rectangle;
	};

	class Player
	{
	public:
		Player(int x, int y, float R, int r, int g, int b)
		{
			m_R = R;
			m_x = x;
			m_y = y;
			m_r = r;
			m_g = g;
			m_b = b;
			m_circle = new sf::CircleShape(m_R);
			m_circle->setOrigin(m_R, m_R);
			m_circle->setPosition(m_x, m_y);
			m_circle->setFillColor(sf::Color(m_r, m_g, m_b));

		}
		~Player()
		{
			delete m_circle;
		}
		sf::CircleShape* Get() { return m_circle; }

		void Move(int y,int x) 
		{
			m_y += y;
			m_x += x;
			m_circle->setPosition(m_x, m_y);
		}
		int GetY() { return m_y; }
		int GetX() { return m_x; }
	private:
		float m_R;
		int m_x, m_y, m_r, m_g, m_b;
		sf::CircleShape* m_circle;
	};

	
}