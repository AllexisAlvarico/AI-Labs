#include "Grid.h"

Grid::Grid(int t_x, int t_y) : m_x{t_x}, m_y{t_y}
{
	m_rect.setSize(sf::Vector2f(10, 10));
	m_rect.setFillColor(sf::Color::Blue);
	m_rect.setOutlineColor(sf::Color::Black);
	m_rect.setOutlineThickness(1);
	m_rect.setPosition(1,1);
}

Grid::~Grid()
{
}

void Grid::update(sf::Time t_deltaTime)
{
}

void Grid::processInput()
{
}

void Grid::render(sf::RenderWindow& t_window)
{
	int m_count = 0;
	sf::Vector2f m_position{0,0};
	for (int i = 0; i < m_x; i++)
	{
		for (int j = 0; j < m_y; j++)
		{
			m_rect.setPosition(m_position);
			t_window.draw(m_rect);
			m_position.x += 10;
		}
		
		if (m_position.x == (m_x * 10))
		{
			m_position.y += 10;
			m_position.x = 0;
		}
	}
}
