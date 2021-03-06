#pragma once

#include <SFML\Graphics.hpp>
#include <SFML\Window.hpp>
#include <stdlib.h>

class Player
{
public:
	Player();
	~Player();
	void draw(sf::RenderWindow & window);
	void update();
	void move();
	void checkCollsions(sf::Sprite sprite);
	sf::Vector2f position;
	sf::Vector2f velocity;
	sf::Sprite player;

private:

	sf::Texture playerTexture;
	//0.0827 change by
	float rotation;
	float rotationDir;
	bool pressed;
	bool canMove;
	float speed;
};

