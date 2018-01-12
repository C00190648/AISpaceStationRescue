#pragma once
#include "SFML\Graphics.hpp"

class Ground
{
public:
	Ground(sf::Vector2f pos);
	~Ground();
	void draw(sf::RenderWindow& window);
	sf::Vector2f position;

private:

	sf::Texture groundTexture;
	sf::Sprite ground;

};

