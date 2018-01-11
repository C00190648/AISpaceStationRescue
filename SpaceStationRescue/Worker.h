#pragma once

#include <SFML\Graphics.hpp>
#include <SFML\Window.hpp>
#include <stdlib.h>
#include "Obstacle.h"

class Worker
{
public:
	Worker();
	~Worker();
	Worker(sf::Vector2f pos);
	void draw(sf::RenderWindow & window);
	void update(std::vector<Obstacle*> &walls);
	void move();
	bool checkCollsions(sf::Sprite sprite);
	void checkWallCollsions(sf::Sprite sprit);
	sf::Vector2f position;
	sf::Vector2f velocity;

private:
	int timer;
	sf::Texture texture;
	sf::Sprite sprite;
	sf::Sprite closestWall;
	//0.0827 change by
	int dir;
	float rotation;
	float rotationDir;
	float orientation;
	float closestDis;
	bool canMove;
	float speed;
	bool fixRight;
	bool fixLeft;
};
