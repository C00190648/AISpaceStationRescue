#include "SeekerBullet.h"
#define _USE_MATH_DEFINES
#include <math.h>
SeekerBullet::SeekerBullet(sf::Vector2f pos)
{
	texture.loadFromFile("ASSETS/IMAGES/nestBullet.png");
	sprite.setTexture(texture);
	position = pos;
	alive = true;
	timer = 150;
}
void SeekerBullet::update(Player player, std::vector<Obstacle*> &walls)
{
	angle = atan2(player.position.y - position.y, player.position.x - position.x);
	if (timer > 0)
	{
		timer--;
	}
	sprite.setRotation(angle * 180/M_PI);
	sf::Vector2f pToB = player.position - position;
	float length = sqrt((pToB.x * pToB.x) + (pToB.y * pToB.y));
	sf::Vector2f velocity = sf::Vector2f(8 * (pToB.x / length), 8 * (pToB.y / length));
	position = position + velocity;
	sprite.setPosition(position);
	if (sprite.getGlobalBounds().intersects(player.player.getGlobalBounds()) || timer == 0)
	{
		alive = false;
	}
	else
	{
		for (std::vector<Obstacle*>::iterator i = walls.begin(); i != walls.end(); i++)
		{
			if (sprite.getGlobalBounds().intersects((*i)->obs.getGlobalBounds()))
			{
				alive = false;
				break;
			}
		}
	}
}
void SeekerBullet::draw(sf::RenderWindow& window)
{
	window.draw(sprite);
}