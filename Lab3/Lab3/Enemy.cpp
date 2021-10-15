#include "Enemy.h"

Enemy::Enemy()
{
	setupSprite();
}

void Enemy::setupSprite()
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

void Enemy::render(sf::RenderWindow& t_window)
{
	t_window.draw(m_sprite);
}

void Enemy::update(sf::Time t_deltaTime)
{
}


void Enemy::getNewOrientation(MyVector3 t_currentOrientation, MyVector3 t_velocity)
{

}
