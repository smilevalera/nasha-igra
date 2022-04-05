#pragma once
#include "player.h"
#include "Road.h"
#include "barrier.h"
class Game {
public:
	Game();
	void play();
private:
	void check_event();
	void update();
	void draw();
	

	sf::RenderWindow window;
	Player player;
	sf::RectangleShape window_borders;
	Road road;
	Barrier barrier1, barrier2;
	
};