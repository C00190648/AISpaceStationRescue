#include "Player.h"

Player::Player()
{
	playerTexture.loadFromFile("player.png");
	player.setTexture(playerTexture);
	player.setOrigin(35, 25);

	position.x = 600;
	position.y = 600;
	rotation = player.getRotation();
	canMove = true;
	speed = 3;
}

Player::~Player()
{
}

void Player::checkCollsions(sf::Sprite sprite)
{
	if (player.getGlobalBounds().intersects(sprite.getGlobalBounds()))
	{
		position.x = position.x - 5 * velocity.x;
		position.y = position.y - 5 * velocity.y;
	}
}

void Player::update()
{
	if (pressed)
	{
		velocity.x = speed * cosf(rotation);
		velocity.y = speed * sinf(rotation);
		position = position + velocity;
	}
}


void Player::move()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		pressed = true;
	}

	if (!sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		pressed = false;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		rotation -= 0.0872;
		player.setRotation(player.getRotation() - 5);

	}


	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		rotation += 0.0872;
		player.setRotation(player.getRotation() + 5);

	}
}

void Player::draw(sf::RenderWindow& window)
{
	player.setPosition(position);
	window.draw(player);
}