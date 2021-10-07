#include "Player.h"

Player::Player()
{
	setupSprite();
}



void Player::handleInput()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {

		//if (m_velocity > m_minVelocity && m_velocity < m_maxVelocity)
		//{
			m_velocity += 0.1;
			std::cout << "Increased velocity: " + std::to_string(m_velocity) << std::endl;
		//}
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {

		//if (m_velocity < m_maxVelocity && m_velocity > m_minVelocity)
		//{
			m_velocity -= 0.1;
			std::cout << "Decreasing velocity: " + std::to_string(m_velocity) << std::endl;
		//}
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		m_angle--;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		m_angle++;
	}
}

void Player::setupSprite()
{
	if (!m_texture.loadFromFile("ASSETS\\IMAGES\\playerSprite.png")) {
		
		std::cout << "Error player's texture not found!" << std::endl; // Error on texture
	}
	m_texture.setSmooth(true);
	m_sprite.setTexture(m_texture);
	m_sprite.setPosition(m_position);
	m_sprite.setOrigin(128.5f, 123.0f);
	m_sprite.setScale(sf::Vector2f(0.3f, 0.3f));
}

void Player::render(sf::RenderWindow &t_window)
{
	t_window.draw(m_sprite);
}

void Player::update(sf::Time t_deltaTime)
{
	handleInput();
	setBoundary();

	m_sprite.move(sf::Vector2f(m_velocity, 0.0f));
	m_sprite.setRotation(m_angle);
	//TODO add position movement here
}

void Player::setBoundary()
{
	if (m_sprite.getPosition().x < -200)
	{
		m_sprite.setPosition(sf::Vector2f(m_windowWidth + 100, m_sprite.getPosition().y));
	}
	if (m_sprite.getPosition().x > m_windowWidth + 200)
	{
		m_sprite.setPosition(sf::Vector2f(-200, m_sprite.getPosition().y));
	}

	if (m_sprite.getPosition().y < -200)
	{
		m_sprite.setPosition(sf::Vector2f(m_sprite.getPosition().x, m_windowHeight + 100));
	}
	if (m_sprite.getPosition().y > m_windowHeight + 200)
	{
		m_sprite.setPosition(sf::Vector2f(m_sprite.getPosition().x, - 200));
	}
}
