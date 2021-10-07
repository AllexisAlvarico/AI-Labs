#include "SFML/Graphics.hpp"
#include <iostream>
#include "Global.h"
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
	sf::Vector2f m_position{ (m_windowWidth / 2) + 100,(m_windowHeight / 2 )+ 100 };
};

