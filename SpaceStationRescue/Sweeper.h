#pragma once

#include "SFML\Graphics.hpp"
#include "Obstacle.h"
#include <stdlib.h>


class Sweeper
{
public:
	Sweeper(sf::Vector2f pos);
	~Sweeper();

	void draw(sf::RenderWindow& window);
	void update(std::vector<Obstacle*> &walls);
	bool checkCollsions(sf::Sprite sprit);
	void checkWallCollsions(sf::Sprite sprit);



private:

	sf::Texture sweeperTexture;
	sf::Sprite sweeper;
	sf::Vector2f position;
	sf::Vector2f velocity;
	int timer;
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

