#include <SFML/Graphics.hpp>
#include "Road.h"
#include "const.h"
#include "Game.h"
#include "barrier.h"

Game::Game() : window(sf::VideoMode(N* ts, M* ts), "Xonix Game!"),
player(100.f, 350.f), window_borders(sf::Vector2f(WINDOW_WIDTH - 35, WINDOW_HEIGHT - 35)),
//road1(0.f, 0.f),
//road2(0.f, -WINDOW_HEIGHT)
barrier1(200.f,40.f),
barrier2(200.f,-WINDOW_HEIGHT/2)

{
	
	window.setFramerateLimit(60);
	window_borders.setPosition(20,20);
	window_borders.setOutlineColor(sf::Color::Yellow);
	window_borders.setFillColor(sf::Color::Transparent);
	window_borders.setOutlineThickness(35);
}

void Game::play(){
	while (window.isOpen()) {
		check_event();
		update();
		draw();
		
	}
}
void Game::check_event(){

	sf::Event event;
	while (window.pollEvent(event)) {
		if (event.type == sf::Event::Closed) {

			window.close();
		}
	}
}
void Game::update(){
	player.update();
	road.update();
}
void Game::draw(){
	window.clear();
	road.draw(window);
	window.draw(window_borders);
	player.draw(window);
	barrier1.draw(window);
	barrier2.draw(window);
	window.display();
	

}

