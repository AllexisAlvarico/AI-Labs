#include "SFML/Graphics.hpp"
#include <iostream>
#include "Global.h"
#include "MyVector3.h"
#include "Steering.h"
#include <random>
/// <summary>
/// I have no Idea what the slides are telling me
/// </summary>

class Wander
{
	Wander();
	void setupSprite();
	void render(sf::RenderWindow& t_window);
	void update(sf::Time t_deltaTime);
	Steering getSteering();
	double getRotation(MyVector3 t_vector);
	double RadianToDegrees(float t_radian);

private:
	sf::Sprite m_sprite;
	sf::Texture m_texture;
	MyVector3 m_position{ (m_windowWidth / 2),(m_windowHeight / 2) + 100,0 };

	double m_wanderOffset{5.0};
	double m_wanderRadius{5.0};
	double m_wanderRate{5.0};
	double m_wanderOrientation{};
	double m_maxVelocity{ 10.0 };

};

