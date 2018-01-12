#include "Nest.h"

Nest::Nest(sf::Vector2f pos)
{
	timer = 80;
	texture.loadFromFile("ASSETS/IMAGES/nest.png");
	sprite.setTexture(texture);
	int dir = rand() % 4;
	if (dir == 0)
	{
		position = pos;

	}
	else if (dir == 1)
	{
		position = pos;
		sprite.setRotation(sprite.getRotation() + 180);
	}
	else if (dir == 2)
	{
		position = pos;
		sprite.setRotation(sprite.getRotation() + 90);
	}
	else if (dir == 3)
	{
		position = pos;
		sprite.setRotation(sprite.getRotation() - 90);
	}
	sprite.setPosition(position);
}
void Nest::update(Player player, std::vector<Obstacle*> &walls)
{
	if (timer > 0)
	{
		timer--;
	}
	sf::Vector2f pToN = (player.position - (position + sf::Vector2f(sprite.getGlobalBounds().width/4, sprite.getGlobalBounds().height /4)));
	float length = sqrt((pToN.x * pToN.x) + (pToN.y * pToN.y));
	if (length < 600 && bullet.size() == 0 && timer == 0)
	{
		bullet.push_back(new SeekerBullet(position));
		timer = 80;
	}

	if (!bullet.size() == 0)
	{
		if (!bullet.at(0)->alive)
		{
			bullet.clear();
		}
		else
		{
			bullet.at(0)->update(player, walls);
		}
	}
}
void Nest::draw(sf::RenderWindow& window)
{
	window.draw(sprite);
	if (!bullet.size() == 0)
	{
		bullet.at(0)->draw(window);
	}
}