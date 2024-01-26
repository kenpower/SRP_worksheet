#include<iostream>
#include "SFML/Graphics.hpp" 
#include "Player.h"   // include Player header file


//void Player::loadAssets(std::string imageFile, sf::IntRect clipRect ) {
void ImageRenderer::loadAssets(std::string imageFile, sf::IntRect clipRect ) {
	if (!m_texture.loadFromFile(imageFile))
	{
		std::cout << "error with image file";
	}
	m_sprite.setTexture(m_texture);
	m_sprite.setTextureRect(clipRect);
}

//void Player::render(sf::RenderWindow& window) {
void ImageRenderer::render(sf::RenderWindow& window, int x, int y) {
	std::cout << "rendering at " << x << ", " << y << std::endl;
	m_sprite.setPosition(x, y);
	window.draw(m_sprite);
}


//void Player::update() {
//	velX = velY = 0;
//	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
//	{
//		velX = -1;
//	}
//	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
//	{
//		velY = -1;
//	}
//	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
//	{
//		velX = +1;
//	}
//	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
//	{
//		velY = +1;
//	}
//	x += velX;
//	y += velY;
//
//}

Velocity UserInput::inputToVelocity() {
	Velocity v{ 0,0 };
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		v.x = -1;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		v.y = -1;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		v.x = +1;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		v.y = +1;
	}
	return v;
}

void Player::update(UserInput& pc){
	Velocity v = pc.inputToVelocity();
	x += v.x;
	y += v.y;

}

