#pragma once
#include <SFML/Graphics.hpp>
#include <cmath>

namespace mt
{

	class Rectangle
	{
		float m_a, m_b;
		bool change_color = false;
		float m_x, m_y;
		float m_v;
		sf::RectangleShape rectangle;

	public:
		Rectangle() = default;

		Rectangle(float x, float y, float a, float b, float v)
		{
			Setup(x, y, a, b, v);
		}

		void Setup(float x, float y, float a, float b, float v)
		{
			m_x = x;
			m_y = y;
			m_a = a;
            m_b = b;
			m_v = v;
			rectangle.setSize(sf::Vector2f(m_a, m_b));
			rectangle.setPosition(m_x, m_y);
			RandomColor();
		}

		sf::RectangleShape Get()
		{
			return rectangle;
		}

		void TouchBorder(int width, int height)
		{
			if (change_color){

			}
			else if (m_x <= 0 ||  m_y + m_b >= height)
			{
				RandomColor();
				change_color = true;
				m_v = 0;
			}
		}
		void RandomColor(){
			int color_r = rand() % 256;
			int color_g = rand() % 256;
			int color_b = rand() % 256;
			rectangle.setFillColor(sf::Color(color_r, color_b, color_g, 255));
		}
		void Move(float dt, int width, int height)
		{
			float new_x = m_x - m_v * dt;
			float new_y = m_y + m_v * dt;

			if (new_x < 0 and new_y + m_b >= height) {
				if (m_x + m_y > height - m_b){
					m_x = m_x - (height - m_b);
					m_y = height - m_b;
				}
				else if (m_x + m_y < height - m_b) {
					m_y = m_x + m_y ; 
					m_x = 0;
				}
				else {
					m_x = 0;
					m_y = height - m_b;
				}
			} 
			else {
				if (new_x < 0) {
					m_x = 0;
				}
				else {
					m_x = new_x;
				}

				if (new_y + m_b >= height){
					m_y = height - m_b; 
				}
				else {
					m_y = new_y;
				}
			}
			rectangle.setPosition(m_x, m_y);
		}
	};

}