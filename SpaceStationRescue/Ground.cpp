#include "Ground.h"

Ground::Ground(sf::Vector2f pos)
{
	position = pos;
	groundTexture.loadFromFile("ground.png");
	ground.setTexture(groundTexture);
}

Ground::~Ground()
{
}

void Ground::draw(sf::RenderWindow& window)
{
	window.draw(ground);
}