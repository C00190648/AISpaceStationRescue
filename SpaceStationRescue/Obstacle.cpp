#include "Obstacle.h"

Obstacle::Obstacle()
{
	obstacleTexture.loadFromFile("obstacle.png");
	obs.setTexture(obstacleTexture);
	position.x = 500;
	position.y = 1000;
}

Obstacle::~Obstacle()
{
}

void Obstacle::draw(sf::RenderWindow& window)
{
	obs.setPosition(position);
	window.draw(obs);
}