#pragma once
#include <SFML/Graphics.hpp>
#include <cmath>

namespace mt
{

	class Rhombus
	{
		float m_r;
		bool change_color = false;
		float m_x, m_y;
		float m_v;
		sf::CircleShape m_shape;

	public:
		Rhombus() = default;

		Rhombus(float x, float y, float r, float v)
		{
			Setup(x, y, r, v);
		}

		void Setup(float x, float y, float r, float v)
		{
			m_x = x;
			m_y = y;
			m_r = r;
			m_v = v;
            m_shape.setPointCount(4);
			m_shape.setOrigin(m_r, m_r);
			m_shape.setRadius(m_r);
			m_shape.setPosition(m_x, m_y);
			RandomColor();
		}

		sf::CircleShape Get()
		{
			return m_shape;
		}

		void TouchBorder(int width, int height)
		{
			if (change_color){

			}
			else if (m_x + m_r >= width || m_x - m_r <= 0 || m_y + m_r >= height || m_y - m_r <= 0)
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
			m_shape.setFillColor(sf::Color(color_r, color_b, color_g, 255));
		}

		void Move(float dt, int width, int height)
		{
			float new_x = m_x - m_v * dt;
			float new_y = m_y + m_v * dt;

			if (new_x - m_r < 0 or new_y + m_r > height) {
				if (m_x + m_y > height){
					m_x = m_x - (height - m_r - m_y);
					m_y = height - m_r;
				}
				else if (m_x + m_y < height) {
					m_y = m_y + m_x - m_r; 
					m_x = m_r;
				}
				else {
					m_x = m_r;
					m_y = height - m_r;
				}
			} 
			else {
				if (new_x - m_r < 0) {
					m_x = m_r;
				}
				else {
					m_x = new_x;
				}
				if (new_y + m_r > height) {
					m_y = height - m_r;
				} 
				else {
					m_y = new_y;
				}
			}
			m_shape.setPosition(m_x, m_y);
		}
	};

}