#include "Wander.h"

void Wander::setupSprite()
{
}

void Wander::render(sf::RenderWindow& t_window)
{
}

void Wander::update(sf::Time t_deltaTime)
{
}

void Wander::getNewOrientation(MyVector3 t_currentOrientation, MyVector3 t_velocity)
{
}

Steering Wander::getSteering(MyVector3 t_target)
{
	Steering m_steering;
	std::default_random_engine m_generator;
	std::binomial_distribution<int> m_distribution(9, 0.5);


	m_wanderOrientation += m_distribution(m_generator) * m_wanderRate;



	return m_steering;
}
