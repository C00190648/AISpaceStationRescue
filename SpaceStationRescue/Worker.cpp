#include "Worker.h"
#define _USE_MATH_DEFINES
#include <math.h>
Worker::Worker(sf::Vector2f pos)
{
	timer = 5;
	speed = 2;
	texture.loadFromFile("ASSETS/IMAGES/worker.png");
	sprite.setTexture(texture);
	sprite.setOrigin(16, 16);
	orientation = sprite.getRotation();
	position = pos;
	rotation = 7.5;
	rotationDir = rand() % 2;
	srand(time(NULL));
}
void Worker::update(std::vector<Obstacle*> &walls)
{
	//velocity update for wander
	velocity.x = speed * cosf(orientation);
	velocity.y = speed * sinf(orientation);
	position = position + velocity;
	for (std::vector<Obstacle*>::iterator i = walls.begin(); i != walls.end(); i++)
	{
		checkWallCollsions((*i)->obs);
	}
	if (timer > 0)
	{
		timer--;
	}
	else
	{
		//rotates the alien 7.5 degrees right or left depending on a random number generator
		//using the previous rotation direction the alien is more likely to rotate the same direction again to look more realistic

			int rotDir = rand() % 3;
			if (rotDir == 0 || rotDir == 2 && rotationDir == 0)
			{
				rotationDir = 0;
				orientation -= rotation * M_PI / 180;
				sprite.setRotation((orientation * 180 / M_PI));
			}
			else
			{
				rotationDir = 1;
				orientation += rotation * M_PI / 180;
				sprite.setRotation((orientation * 180 / M_PI));
			}
		//}
		timer = 5;
	}
}
bool Worker::checkCollsions(sf::Sprite sprit)
{
	if (sprite.getGlobalBounds().intersects(sprit.getGlobalBounds()))
	{
		return true;
	}
	else
	{
		return false;
	}
}
void Worker::checkWallCollsions(sf::Sprite sprit)
{
	if (sprite.getGlobalBounds().intersects(sprit.getGlobalBounds()))
	{
		if (position.x + 16 > sprit.getPosition().x + sprit.getGlobalBounds().width
			&& (position.y + 10 > sprit.getPosition().y
				&& position.y < sprit.getPosition().y + sprit.getGlobalBounds().height + 10)
			|| (position.y > sprit.getPosition().y + sprit.getGlobalBounds().height
				&& velocity.y > 0 && velocity.y > velocity.x && velocity.y > velocity.x *-1)
			|| (position.y + 16 < sprit.getPosition().y
				&& velocity.y < 0 && velocity.y < velocity.x && velocity.y < velocity.x *-1))
		{
			position.x = position.x + (speed + 1);
		}
		if (position.x < sprit.getPosition().x
			&& (position.y + 10 > sprit.getPosition().y
				&& position.y < sprit.getPosition().y + sprit.getGlobalBounds().height + 10)
			|| (position.y > sprit.getPosition().y + sprit.getGlobalBounds().height
				&& velocity.y > 0 && velocity.y > velocity.x && velocity.y > velocity.x *-1)
			|| (position.y + 16 < sprit.getPosition().y
				&& velocity.y < 0 && velocity.y < velocity.x && velocity.y < velocity.x *-1))
		{
			position.x = position.x - (speed + 1);
		}
		if (position.y < sprit.getPosition().y
			&& (position.x + 10 > sprit.getPosition().x
				&& position.x < sprit.getPosition().x + sprit.getGlobalBounds().width + 10)
			|| (position.x > sprit.getPosition().x + sprit.getGlobalBounds().width * 2
				&& velocity.x > 0 && velocity.x > velocity.y && velocity.x > velocity.y *-1)
			|| (position.x + 16 < sprit.getPosition().x
				&& velocity.x < 0 && velocity.x < velocity.y && velocity.x < velocity.y *-1))
		{
			position.y = position.y - (speed + 1);
		}
		if (position.y + 16 > sprit.getPosition().y + sprit.getGlobalBounds().height
			&& (position.x + 10 > sprit.getPosition().x
				&& position.x < sprit.getPosition().x + sprit.getGlobalBounds().width + 10)
			|| (position.x > sprit.getPosition().x + sprit.getGlobalBounds().width * 2
				&& velocity.x > 0 && velocity.x > velocity.y && velocity.x > velocity.y *-1)
			|| (position.x + 16 < sprit.getPosition().x
				&& velocity.x < 0 && velocity.x < velocity.y && velocity.x < velocity.y *-1))
		{
			position.y = position.y + (speed + 1);
		}
		//int turn = rand() % 2;
		//if (turn == 0)
		//{
		//	fixLeft = true;
		//	fixRight = false;
		//}
		//else
		//{
		//	fixRight = true;
		//	fixLeft = false;
		//}
	}
}
void Worker::draw(sf::RenderWindow & window)
{
	sprite.setPosition(position);
	window.draw(sprite);
}