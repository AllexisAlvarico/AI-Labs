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
	m_position = m_position + m_steering.m_linear;
	m_sprite.setPosition(m_position);
	m_sprite.setRotation(m_steering.m_rotation);
	std::cout << "position x:" + std::to_string(m_steering.m_linear.x) + "y: " + std::to_string(m_steering.m_linear.y) << std::endl;
}


Steering Seek::getSteering(MyVector3 t_targetPos)
{
	Steering m_steering;
	m_steering.m_linear = t_targetPos - m_position;
	m_steering.m_linear.normalise();
	m_steering.m_rotation = getRotation(m_steering.m_linear);
	m_steering.m_linear = m_steering.m_linear * m_maxVelocity;
	m_steering.m_angular = sf::Vector2f{ 0,0 };
	return m_steering;
}

double Seek::getRotation(MyVector3 t_vector)
{
	return RadianToDegrees((atan2f(t_vector.y, t_vector.x)));
}

double Seek::RadianToDegrees(float t_radian)
{
	return t_radian * (180.0f / PI);
}



