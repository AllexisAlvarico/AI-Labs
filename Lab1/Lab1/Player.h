#include "SFML/Graphics.hpp"
#include <iostream>
#pragma once
class Player
{
public:
	Player();
	void handleInput();
	void setupSprite();
	void render(sf::RenderWindow& t_window);
	void update(sf::Time t_deltaTime);

private:
	sf::Sprite m_sprite;
	sf::Texture m_texture;
	sf::Vector2f m_position{500, 500};

};

