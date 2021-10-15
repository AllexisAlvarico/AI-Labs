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
	void getNewOrientation(MyVector3 t_currentOrientation, MyVector3 t_velocity);
	Steering getSteering(MyVector3 t_targetPos);
	sf::Vector3f magnitude(MyVector3 t_vector3);

private:
	sf::Sprite m_sprite;
	sf::Texture m_texture;
	MyVector3 m_position{ (m_windowWidth / 2),(m_windowHeight / 2) + 100,0 };
	MyVector3 m_velocity{};
	MyVector3 m_newVelocity{};

	double m_maxVelocity{ 1.0f };
	double m_minVelocity{ 0.0 };
	double m_radians{ 0.0 };
	double m_angle{ 0.0 };
	double m_speed{ 0.0 };
};

