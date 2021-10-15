#include "Arrive.h"

Arrive::Arrive()
{
	setupSprite();
}

void Arrive::setupSprite()
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
void Arrive::render(sf::RenderWindow& t_window)
{
	t_window.draw(m_sprite);
}

void Arrive::update(sf::Time t_deltaTime, MyVector3 t_playerPos)
{

	Steering m_steering = getSteering(t_playerPos);
	m_position = m_position + m_steering.m_linear;
	m_sprite.setPosition(m_position);
	m_sprite.setRotation(m_steering.m_rotation);
	//std::cout << "position x:" + std::to_string(m_steering.m_linear.x) + "y: " + std::to_string(m_steering.m_linear.y) << std::endl;
}

Steering Arrive::getSteering(MyVector3 t_targetPos)
{
	Steering m_steering;
	m_steering.m_linear = t_targetPos - m_position;
	float distance = m_steering.m_linear.length();
	if (distance < m_slowRadius) {
		m_steering.m_linear.normalise();
		m_steering.m_rotation = getRotation(m_steering.m_linear);
		m_steering.m_linear* m_maxSpeed* (distance / m_slowRadius);
	}
	else
	{
		m_steering.m_linear.normalise();
		m_steering.m_rotation = getRotation(m_steering.m_linear);
		m_steering.m_linear* m_maxSpeed;
	}
	return m_steering;
}
double Arrive::getRotation(MyVector3 t_vector)
{
	return RadianToDegrees((atan2f(t_vector.y, t_vector.x)));
}

double Arrive::RadianToDegrees(float t_radian)
{
	return t_radian * (180.0f / PI);
}


