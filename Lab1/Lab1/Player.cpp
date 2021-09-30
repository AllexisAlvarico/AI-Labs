#include "Player.h"

Player::Player()
{
	setupSprite();
}



void Player::handleInput()
{
}

void Player::setupSprite()
{
	if (!m_texture.loadFromFile("ASSETS\\IMAGES\\playerSprite.png")) {
		
		std::cout << "Error player's texture not found!" << std::endl; // Error on texture
	}
	m_texture.setSmooth(true);
	m_sprite.setTexture(m_texture);
	m_sprite.setPosition(m_position);
	m_sprite.setScale(sf::Vector2f(0.3f, 0.3f));
}

void Player::render(sf::RenderWindow &t_window)
{
	t_window.draw(m_sprite);
}

void Player::update(sf::Time t_deltaTime)
{
	//TODO add position movement here
}
