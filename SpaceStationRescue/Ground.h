#pragma once
#include "SFML\Graphics.hpp"

class Ground
{
public:
	Ground(sf::Vector2f pos);
	~Ground();
	void draw(sf::RenderWindow& window);

private:

	sf::Texture groundTexture;
	sf::Sprite ground;
	sf::Vector2f position;

};

