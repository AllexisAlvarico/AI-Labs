#include "SFML/Graphics.hpp"
#include <iostream>
#include "Global.h"
#include "MyVector3.h"
#include "Steering.h"

class Arrive
{
public:
	Arrive();
	void setupSprite();
	void render(sf::RenderWindow& t_window);
	void update(sf::Time t_deltaTime, MyVector3 t_playerPos);
	Steering getSteering(MyVector3 t_targetPos);
	double getRotation(MyVector3 t_vector);
	double RadianToDegrees(float t_radian);

private:
	sf::Sprite m_sprite;
	sf::Texture m_texture;
	MyVector3	m_position{ (m_windowWidth / 2),(m_windowHeight / 2) + 100,0 };
	MyVector3	m_targetVelocity{};

	double	m_maxSpeed{20.0};
	double	m_targetSpeed{ 15.0 };
	double	m_targetRadius{50.0};
	double	m_slowRadius{30.0};
};

