#pragma once

#include <SFML\Graphics.hpp>
#include <SFML\Window.hpp>
#include <stdlib.h>

class Obstacle
{
public:
	Obstacle();
	~Obstacle();
	void draw(sf::RenderWindow& window);
	sf::Vector2f position;
	sf::Sprite obs;
private:

	sf::Texture obstacleTexture;

};

