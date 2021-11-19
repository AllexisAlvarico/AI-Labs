#include <SFML/Graphics.hpp>
#include <iostream>

class Grid
{
public:
	Grid(int t_x, int t_y);
	~Grid();

	void update(sf::Time t_deltaTime);
	void processInput();
	void render(sf::RenderWindow& t_window);

private:
	int m_cost{};
	int m_x, m_y{};
	sf::RectangleShape m_rect;

};

