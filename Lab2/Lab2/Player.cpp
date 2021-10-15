#include "Player.h"

Player::Player()
{
	setupSprite();
}

Player::~Player()
{
	std::cout << "De-constructing player";
}



void Player::movement()
{
	m_radians = m_angle * (PI / 180); // gets the radians and sets it
	m_sprite.setRotation(m_angle); // rotate the sprite by the angle
	m_position = m_sprite.getPosition(); // set the previous player position after the speed
	m_velocity = m_newVelocity; // set the new velocity to the current velocity
	m_sprite.move(m_velocity * m_speed); // moves the player

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) || sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) // input of the user
	{
		m_newVelocity.x = cos(m_radians); // takes cos and turn into an angle 
		m_newVelocity.y = sin(m_radians); // takes sin and turn into an angle 


		if (m_speed <= m_maxVelocity) // if speed is below max speed
		{
			m_speed += 0.1; // increase the speed

		}
		else
		{
			m_speed += 0; // stop the increase the of the speed
		}
		if (m_minVelocity >= m_speed) // if its greater
		{
			m_speed = 0; // set it to zero
		}
		else
		{
			m_speed -= 0.02; // decrease the speed when stationary
		}
	}
	else
	{
		if (m_minVelocity >= m_speed) // if its greater
		{
			m_speed = 0; // set it to zero
		}
		else
		{
			m_speed -= 0.02; // decrease the speed when stationary
		}
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		m_angle-= 3;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		m_angle+= 3;
	}

	//std::cout << "Speed: " << m_speed << std::endl;


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
	getPosition();
	movement();
	setBoundary();


	//TODO add position movement here
}

void Player::setBoundary()
{
	if (m_sprite.getPosition().x < -128.5f)
	{
		m_sprite.setPosition(sf::Vector2f(m_windowWidth + 128.5f, m_sprite.getPosition().y));
	}
	if (m_sprite.getPosition().x > m_windowWidth + 128.5f)
	{
		m_sprite.setPosition(sf::Vector2f(-128.5f, m_sprite.getPosition().y));
	}

	if (m_sprite.getPosition().y < -123.0f)
	{
		m_sprite.setPosition(sf::Vector2f(m_sprite.getPosition().x, m_windowHeight + 123.0f));
	}
	if (m_sprite.getPosition().y > m_windowHeight + 123.0f)
	{
		m_sprite.setPosition(sf::Vector2f(m_sprite.getPosition().x, -123.0f));
	}
}

MyVector3 Player::getPosition()
{	
	//std::cout << "Player's Position: " + std::to_string(m_position.x) + ", " + std::to_string(m_position.y) + ", " + std::to_string(m_position.z) << std::endl;
	return m_position;
}
