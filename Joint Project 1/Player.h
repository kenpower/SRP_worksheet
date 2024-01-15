// Player class declaration
#pragma once
#include<string>


class Player
{
	int x, y;
	int velX, velY;

	sf::Texture m_texture;  
	sf::Sprite m_sprite;    

public:
	Player() {
		x = 100, y = 100;
		velX = velY = 0;

	}
	void loadAssets(std::string);
	void update();
	void render(sf::RenderWindow&);
};