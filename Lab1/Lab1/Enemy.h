#include "SFML/Graphics.hpp"
#pragma once
class Enemy
{
public:
	Enemy();
	void AIBehavior();
	void setupSprite();
	void render(sf::RenderWindow& t_window);
	void update(sf::Time t_deltaTime);

private:
	sf::Sprite m_sprite;
	sf::Texture m_texture;
	sf::Vector2f m_position;
};

