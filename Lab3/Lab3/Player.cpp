#include "Player.h"

Player::Player()
{
	setupSprite();
}

Player::~Player()
{
	std::cout << "De-constructing player";
}



void Player::movement(sf::Time t_deltaTime)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) || sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) // input of the user
	{

		m_speed += 2;

		if (m_speed > m_maxVelocity)
		{
			m_speed = m_maxVelocity;
		}
		m_velocity.normalise();
		m_velocity = m_velocity * m_speed;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) || sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) // input of the user
	{
		m_speed -= 2;

		if (m_speed < m_minVelocity)
		{
			m_speed = m_minVelocity;
		}
		m_velocity.normalise();
		m_velocity = m_velocity * m_speed;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		m_orientation -= m_rotation * t_deltaTime.asSeconds();
		m_velocity = MyVector3{ cosf(m_orientation), sinf(m_orientation), 0.0 } *m_speed;

		m_sprite.setRotation(RadianToDegrees(atan2f(m_velocity.y, m_velocity.x)));
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		m_orientation += m_rotation * t_deltaTime.asSeconds();
		m_velocity = MyVector3{ cosf(m_orientation), sinf(m_orientation), 0.0 } *m_speed;
		m_sprite.setRotation(RadianToDegrees((atan2f(m_velocity.y, m_velocity.x))));
	}

	m_position = m_position + m_velocity * t_deltaTime.asSeconds();
	m_sprite.setPosition(m_position);
	//std::cout << "velocity: " + std::to_string(m_velocity.x) << std::endl;
}

void Player::setupSprite()
{
	if (!m_texture.loadFromFile("ASSETS\\IMAGES\\playerSprite.png")) {
		
		std::cout << "Error player's texture not found!" << std::endl; // Error on texture
	}
	m_texture.setSmooth(true);
	m_sprite.setTexture(m_texture);
	m_sprite.setPosition(m_position);
	m_sprite.setOrigin(m_sprite.getGlobalBounds().width / 2.0, m_sprite.getGlobalBounds().height / 2.0);
	m_sprite.setScale(sf::Vector2f(0.3f, 0.3f));
	m_rotation = m_angle * (PI / 180);

}

void Player::render(sf::RenderWindow &t_window)
{
	t_window.draw(m_sprite);
}

void Player::update(sf::Time t_deltaTime)
{
	getPosition();
	movement(t_deltaTime);
	setBoundary();

	std::cout << "Player Position x:" + std::to_string(m_position.x) + "y: " + std::to_string(m_position.y) << std::endl;
	//TODO add position movement here
}

void Player::setBoundary()
{
	if (m_sprite.getPosition().x < -128.5f)
	{
		m_position = (sf::Vector2f(m_windowWidth + 128.5f, m_sprite.getPosition().y));
	}
	if (m_sprite.getPosition().x > m_windowWidth + 128.5f)
	{
		m_position = (sf::Vector2f(-128.5f, m_sprite.getPosition().y));
	}

	if (m_sprite.getPosition().y < -123.0f)
	{
		m_position = (sf::Vector2f(m_sprite.getPosition().x, m_windowHeight + 123.0f));
	}
	if (m_sprite.getPosition().y > m_windowHeight + 123.0f)
	{
		m_position = (sf::Vector2f(m_sprite.getPosition().x, -123.0f));
	}
}

sf::Vector2f Player::getPosition()
{	
	return m_position;
}

double Player::RadianToDegrees(float t_radian)
{
	return t_radian * (180.0f / PI);
}
