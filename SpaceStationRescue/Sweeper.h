#pragma once

#include "SFML\Graphics.hpp"


class Sweeper
{
public:
	Sweeper(sf::Vector2f pos);
	~Sweeper();

	void draw(sf::RenderWindow& window);

private:

	sf::Texture sweeperTexture;
	sf::Sprite sweeper;
	sf::Vector2f position;
	sf::Vector2f velocity;

};

