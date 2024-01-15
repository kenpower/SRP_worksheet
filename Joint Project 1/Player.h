// Player class declaration
#pragma once

class Player
{
	// private data members
	int x, y;
	int dx, dy;

public:
	Player() {
		x = 100, y = 100;
		dx = dy = 0;

	}
	void loadAssets();
	void update();
	void render();


};