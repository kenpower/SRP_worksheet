#include<iostream>
#include "SFML/Graphics.hpp" 
#include "Player.h"   // include Player header file

void Player::loadAssets(std::string imageFile, sf::IntRect clipRect ) {
	if (!m_texture.loadFromFile(imageFile))
	{
		std::cout << "error with image file";
	}
	m_sprite.setTexture(m_texture);
	m_sprite.setTextureRect(clipRect);
}

void Player::update(){
	velX = velY = 0;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		velX = -1;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		velY = -1;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		velX = +1;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		velY = +1;
	}
	x += velX;
	y += velY;

}

void Player::render(sf::RenderWindow& window) {
	std::cout << "rendering at " << x << ", " << y << std::endl;
	m_sprite.setPosition(x, y);
	window.draw(m_sprite);
}