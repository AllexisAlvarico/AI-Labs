#include "SFML/Graphics.hpp"
#include "Global.h"
#include <iostream>
#include "MyVector3.h"
#pragma once
class Player
{
public:
	Player();
	~Player();
	void movement(sf::Time t_deltaTime);
	void setupSprite();
	void render(sf::RenderWindow& t_window);
	void update(sf::Time t_deltaTime);
	void setBoundary();
	sf::Vector2f getPosition();
	double RadianToDegrees(float t_radian);

private:
	sf::Sprite m_sprite;
	sf::Texture m_texture;
	MyVector3 m_position{ (m_windowWidth / 2),(m_windowHeight / 2),0};
	MyVector3 m_velocity{ 1.0,1.0,0.0 };
	MyVector3 m_newVelocity{};

	double m_maxVelocity{ 250.0f };
	double m_minVelocity{ 5.0 };
	double m_radians{0.0};
	double m_angle{50.0};
	double m_rotation{ 0.0 };
	double m_orientation{0.0};
	double m_speed{ 10.0 };

};

