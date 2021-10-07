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
	sf::Vector2f m_position{ (m_windowWidth / 2),(m_windowHeight / 2)};
	double m_velocity{ 0.0 };
	double m_maxVelocity{ 20.0 };
	double m_minVelocity{ -20.0 };
	double m_radians{0.0};
	double m_angle{0.0};
};

