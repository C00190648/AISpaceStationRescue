#include "Ground.h"

Ground::Ground(sf::Vector2f pos)
{
	position = pos;
	groundTexture.loadFromFile("ASSETS/IMAGES/ground.png");
	ground.setTexture(groundTexture);
	ground.setPosition(position);
}

Ground::~Ground()
{
}

void Ground::draw(sf::RenderWindow& window)
{
	window.draw(ground);
}