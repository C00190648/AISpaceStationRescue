#include "Player.h"

Player::Player()
{
	playerTexture.loadFromFile("ASSETS/IMAGES/player1.png");
	player.setTexture(playerTexture);
	player.setOrigin(64, 45);

	position.x = 600;
	position.y = 600;
	rotation = player.getRotation();
	canMove = true;
	speed = 8;
}

Player::~Player()
{
}

void Player::checkCollsions(sf::Sprite sprite)
{
	if (player.getGlobalBounds().intersects(sprite.getGlobalBounds()))
	{
		if (position.x + 45 > sprite.getPosition().x + sprite.getGlobalBounds().width
			&& (position.y + 10 > sprite.getPosition().y
				&& position.y < sprite.getPosition().y + sprite.getGlobalBounds().height + 10)
			|| (position.y  > sprite.getPosition().y + sprite.getGlobalBounds().height
				&& velocity.y > 0 && velocity.y > velocity.x && velocity.y > velocity.x *-1)
			|| (position.y + 60 < sprite.getPosition().y
				&& velocity.y < 0 && velocity.y < velocity.x && velocity.y < velocity.x *-1))
		{
			position.x = position.x + (speed + 1);
		}
		if (position.x < sprite.getPosition().x
			&& (position.y + 10 > sprite.getPosition().y
				&& position.y < sprite.getPosition().y + sprite.getGlobalBounds().height + 10)
			|| (position.y  > sprite.getPosition().y + sprite.getGlobalBounds().height
				&& velocity.y > 0 && velocity.y > velocity.x && velocity.y > velocity.x *-1)
			|| (position.y  < sprite.getPosition().y
				&& velocity.y < 0 && velocity.y < velocity.x && velocity.y < velocity.x *-1))
		{
			position.x = position.x - (speed + 1);
		}
		if (position.y < sprite.getPosition().y
			&& (position.x + 10 > sprite.getPosition().x
				&& position.x < sprite.getPosition().x + sprite.getGlobalBounds().width + 10)
			|| (position.x  > sprite.getPosition().x + sprite.getGlobalBounds().width * 2
				&& velocity.x > 0 && velocity.x > velocity.y && velocity.x > velocity.y *-1)
			|| (position.x + 60 < sprite.getPosition().x
				&& velocity.x < 0 && velocity.x < velocity.y && velocity.x < velocity.y *-1))
		{
			position.y = position.y - (speed + 1);
		}
		if (position.y + 45 > sprite.getPosition().y + sprite.getGlobalBounds().height
			&& (position.x + 10 > sprite.getPosition().x
				&& position.x < sprite.getPosition().x + sprite.getGlobalBounds().width + 10)
			|| (position.x  > sprite.getPosition().x + sprite.getGlobalBounds().width * 2
				&& velocity.x > 0 && velocity.x > velocity.y && velocity.x > velocity.y *-1)
			|| (position.x + 60 < sprite.getPosition().x
				&& velocity.x < 0 && velocity.x < velocity.y && velocity.x < velocity.y *-1))
		{
			position.y = position.y + (speed + 1);
		}
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