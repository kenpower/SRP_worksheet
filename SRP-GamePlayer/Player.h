// Player class declaration
#pragma once
#include<string>


class ImageRenderer {
	sf::Texture m_texture;
	sf::Sprite m_sprite;
public:
	void loadAssets(std::string, sf::IntRect);
	void render(sf::RenderWindow&, int, int);
};

struct Velocity {
	int x, y;
};

class UserInput {
public:
	Velocity inputToVelocity();
};

class Player
{
	int x, y;
	int velX, velY; // do we need anymore?

public:
	Player() {
		x = 100, y = 100;
		velX = velY = 0;
	}

	int posX() { return x; }
	int posY() { return y; }

	//void loadAssets(std::string, sf::IntRect);
	//void update();
	//void render(sf::RenderWindow&);
	void update(UserInput& pc);

};