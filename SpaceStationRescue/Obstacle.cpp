#include "Obstacle.h"

Obstacle::Obstacle(sf::Vector2f pos)
{
	obstacleTexture.loadFromFile("ASSETS/IMAGES/wall.png");
	obs.setTexture(obstacleTexture);
	position = pos;
	obs.setPosition(position);
}

Obstacle::~Obstacle()
{
}

void Obstacle::draw(sf::RenderWindow& window)
{

	window.draw(obs);
}