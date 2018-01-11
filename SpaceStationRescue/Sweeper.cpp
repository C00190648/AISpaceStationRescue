#include "Sweeper.h"

Sweeper::Sweeper(sf::Vector2f pos)
{
	sweeperTexture.loadFromFile("ASSETS/IMAGES/sweeper.png");
	sweeper.setTexture(sweeperTexture);
	position = pos;
	sweeper.setPosition(position);
}

Sweeper::~Sweeper()
{

}

void Sweeper::draw(sf::RenderWindow& window)
{
	window.draw(sweeper);
}