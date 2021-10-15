#include "SFML/Graphics.hpp"
#include <iostream>
#include "Global.h"
#include "MyVector3.h"
#include "Steering.h"
#pragma once
class Seek
{
public:
	Seek();
	void setupSprite();
	void render(sf::RenderWindow& t_window);
	void update(sf::Time t_deltaTime, MyVector3 t_playerPos);
	Steering getSteering(MyVector3 t_targetPos);
	double getRotation(MyVector3 t_vector);
	double RadianToDegrees(float t_radian);
private:
	sf::Sprite m_sprite;
	sf::Texture m_texture;
	MyVector3 m_position{ (m_windowWidth / 2),(m_windowHeight / 2) + 100,0 };
	double m_maxVelocity{ 1.0f };
	double m_minVelocity{ 0.0 };
};

