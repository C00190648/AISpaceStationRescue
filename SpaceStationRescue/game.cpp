// author Peter Lowe

#include "Game.h"
#include <iostream>


//Gets the resolution, size, and bits per pixel for the screen of the PC that is running this program.
sf::VideoMode desktop = sf::VideoMode::getDesktopMode();
Player player;

sf::View view(sf::FloatRect(0, 0, 1408, 1280));

const int window_height = desktop.height;
const int window_width = desktop.width;

Game::Game() :
	m_window{ sf::VideoMode{ 1408, 1280, 32 }, "SFML Game" },
	//m_window(sf::VideoMode(desktop.width, desktop.height, desktop.bitsPerPixel), "Boids", sf::Style::None),

	m_exitGame{false} //when true game will exit
{
	setupFontAndText(); // load font 
	setupSprite(); // load texture
	level.init(64);
	level.setupLevel(ground, wall,sweepers);
}

Game::~Game()
{
}


void Game::run()
{
	sf::Clock clock;
	sf::Time timeSinceLastUpdate = sf::Time::Zero;
	sf::Time timePerFrame = sf::seconds(1.f / 60.f); // 60 fps
	while (m_window.isOpen())
	{
		processEvents(); // as many as possible
		timeSinceLastUpdate += clock.restart();
		while (timeSinceLastUpdate > timePerFrame)
		{
			timeSinceLastUpdate -= timePerFrame;
			processEvents(); // at least 60 fps
			update(timePerFrame); //60 fps
		}
		render(); // as many as possible
	}
}
/// <summary>
/// handle user and system events/ input
/// get key presses/ mouse moves etc. from OS
/// and user :: Don't do game update here
/// </summary>
void Game::processEvents()
{
	sf::Event event;
	while (m_window.pollEvent(event))
	{
		if ( sf::Event::Closed == event.type) // window message
		{
			m_window.close();
		}
		if (sf::Event::KeyPressed == event.type) //user key press
		{
			if (sf::Keyboard::Escape == event.key.code)
			{
				m_exitGame = true;
			}
		}
	}
}

/// <summary>
/// Update the game world
/// </summary>
/// <param name="t_deltaTime">time interval per frame</param>
void Game::update(sf::Time t_deltaTime)
{
	m_window.setView(view);

	if (m_exitGame)
	{
		m_window.close();
	}
	player.move();
	view.setCenter(player.position.x, player.position.y);
	player.update();
	for (std::vector<Obstacle*>::iterator i = wall.begin(); i != wall.end(); i++)
	{
		player.checkCollsions((*i)->obs);
	}
}

/// <summary>
/// draw the frame and then switch bufers
/// </summary>
void Game::render()
{
	m_window.clear(sf::Color::Black);

	for (std::vector<Ground*>::iterator i = ground.begin(); i != ground.end(); i++)
	{
		(*i)->draw(m_window);
	}
	for (std::vector<Obstacle*>::iterator i = wall.begin(); i != wall.end(); i++)
	{
		(*i)->draw(m_window);
	}

	for (std::vector<Sweeper*>::iterator i = sweepers.begin(); i != sweepers.end(); i++)
	{
		(*i)->draw(m_window);
	}

	player.draw(m_window);
	m_window.display();

}

/// <summary>
/// load the font and setup the text message for screen
/// </summary>
void Game::setupFontAndText()
{


}

/// <summary>
/// load the texture and setup the sprite for the logo
/// </summary>
void Game::setupSprite()
{

}
