#include "SFML/Graphics.hpp"
#include <iostream>
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
	sf::Vector2f m_position{ 1000.0f,500.0f};
};

