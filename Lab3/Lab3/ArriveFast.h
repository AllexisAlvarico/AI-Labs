#include "SFML/Graphics.hpp"
#include <iostream>
#include "Global.h"
#include "MyVector3.h"

class ArriveFast
{
	ArriveFast();
	void setupSprite();
	void render(sf::RenderWindow& t_window);
	void update(sf::Time t_deltaTime);
	void getNewOrientation(MyVector3 t_currentOrientation, MyVector3 t_velocity);

private:
	sf::Sprite m_sprite;
	sf::Texture m_texture;
	MyVector3 m_position{ (m_windowWidth / 2),(m_windowHeight / 2) + 100,0 };
	MyVector3 m_velocity{};
	MyVector3 m_newVelocity{};

	double m_maxVelocity{ 10.0f };
	double m_minVelocity{ 0.0 };
	double m_radians{ 0.0 };
	double m_angle{ 0.0 };
	double m_speed{ 0.0 };
};

