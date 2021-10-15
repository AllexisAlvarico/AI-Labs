#include "Seek.h"

Seek::Seek()
{
	setupSprite();
}

void Seek::setupSprite()
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

void Seek::render(sf::RenderWindow& t_window)
{
	t_window.draw(m_sprite);
}

void Seek::update(sf::Time t_deltaTime, MyVector3 t_playerPos)
{
	Steering m_steering = getSteering(t_playerPos);
	m_steering.m_linear += m_position;

	m_sprite.move(m_steering.m_linear);

	//std::cout << "position x:" + std::to_string(m_steering.m_linear.x) + "y: " + std::to_string(m_steering.m_linear.y) << std::endl;
}

void Seek::getNewOrientation(MyVector3 t_currentOrientation, MyVector3 t_velocity)
{
} 


Steering Seek::getSteering(MyVector3 t_targetPos)
{
	Steering m_steering;
	m_steering.m_linear = t_targetPos - m_position;
	m_steering.m_linear = magnitude(m_steering.m_linear);
	m_steering.m_linear.normalise();
	m_steering.m_linear = m_steering.m_linear * m_maxVelocity;
	m_steering.m_angular = { 0,0,0 };
	return m_steering;
}

sf::Vector3f Seek::magnitude(MyVector3 t_vector3)
{
	MyVector3 m_result = { t_vector3.x * t_vector3.x, t_vector3.y * t_vector3.y, 0 };
	return m_result;
}
