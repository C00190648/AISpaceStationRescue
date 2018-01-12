#pragma once
#include <SFML\Graphics.hpp>
#include <SFML\Window.hpp>
#include <stdlib.h>
#include "Player.h"
#include "Obstacle.h"
#include "SeekerBullet.h"

class Nest
{

public:
	Nest(sf::Vector2f pos);
	~Nest();
	void draw(sf::RenderWindow& window);
	void spawnPredator();
	void update(Player player, std::vector<Obstacle*> &walls);
	sf::Vector2f position;
	sf::Sprite sprite;
private:
	int timer;
	std::vector<SeekerBullet*> bullet;
	sf::Texture texture;

};

