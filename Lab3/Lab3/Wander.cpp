#include "Wander.h"
/// <summary>
/// I have no Idea what the slides are telling me
/// </summary>


void Wander::setupSprite()
{
	if (!m_texture.loadFromFile("ASSETS\\IMAGES\\enemySprite.png")) {

		std::cout << "Error enemy's texture not found!" << std::endl; // Error on texture
	}
	m_texture.setSmooth(true);
	m_sprite.setTexture(m_texture);
	m_sprite.setPosition(m_position);
	m_sprite.setOrigin(130.0f, 121.5f);
	m_sprite.setScale(sf::Vector2f(0.3f, 0.3f));
}

void Wander::render(sf::RenderWindow& t_window)
{
	t_window.draw(m_sprite);
}

void Wander::update(sf::Time t_deltaTime)
{
	//Steering m_steering = getSteering();
	//m_position = m_position + m_steering.m_linear;
	//m_sprite.setPosition(m_position);
	//m_sprite.setRotation(m_steering.m_rotation);
	//std::cout << "position x:" + std::to_string(m_steering.m_linear.x) + "y: " + std::to_string(m_steering.m_linear.y) << std::endl;
}

Steering Wander::getSteering()
{
	//Steering m_steering;
	//m_wanderOrientation += rand() % 2 * m_wanderRate;
	//m_targetOrientation = m_wanderOrientation + m_steering.m_rotation;


	return Steering();
}

double Wander::getRotation(MyVector3 t_vector)
{
	return RadianToDegrees((atan2f(t_vector.y, t_vector.x)));
}

double Wander::RadianToDegrees(float t_radian)
{
	return t_radian * (180.0f / PI);
}



