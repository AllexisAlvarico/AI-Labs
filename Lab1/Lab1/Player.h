#include "SFML/Graphics.hpp"
#pragma once
class Player
{
public:
	void handleInput();
	void setupSprite();
	void render();
	void update();

private:
	sf::Sprite m_sprite;
	sf::Texture m_texture;
	sf::Vector2f m_position;

};

