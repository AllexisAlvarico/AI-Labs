#include "SFML/Graphics.hpp"
#include "Global.h"
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
	void setBoundary();

private:
	sf::Sprite m_sprite;
	sf::Texture m_texture;
	sf::Vector2f m_position{500.0f, 500.0f};
	double m_velocity{ 0.0 };
	double m_maxVelocity{ 20.0 };
	double m_minVelocity{ -20.0 };

};

