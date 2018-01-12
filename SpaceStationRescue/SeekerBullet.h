#pragma once

#include <SFML\Graphics.hpp>
#include <SFML\Window.hpp>
#include <stdlib.h>
#include "Player.h"
#include "Obstacle.h"

class SeekerBullet
{
public:
	SeekerBullet(sf::Vector2f pos);
	~SeekerBullet();
	void draw(sf::RenderWindow& window);
	sf::Vector2f position;
	sf::Sprite sprite;
	void update(Player player, std::vector<Obstacle*> &walls);
	bool alive;
	int timer;
	float angle;
private:

	sf::Texture texture;

};