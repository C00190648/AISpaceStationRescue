// author Peter Lowe
#ifndef GAME
#define GAME
#include "Player.h"
#include "Obstacle.h"
#include "Ground.h"
#include "Worker.h"
#include "Level.h"
#include "Sweeper.h"
#include <SFML/Graphics.hpp>

class Game
{
public:
	Game();
	~Game();
	/// <summary>
	/// main method for game
	/// </summary>
	void run();

private:

	void processEvents();
	void update(sf::Time t_deltaTime);
	void render();
	
	void setupFontAndText();
	void setupSprite();

	sf::RenderWindow m_window; // main SFML window
	sf::Font m_ArialBlackfont; // font used by message
	sf::Text m_welcomeMessage; // text used for message on screen
	sf::Texture m_logoTexture; // texture used for sfml logo
	sf::Sprite m_logoSprite; // sprite used for sfml logo
	bool m_exitGame; // control exiting game
	std::vector<Ground*> grounds;
	std::vector<Obstacle*> walls;
	std::vector<Worker*> workers;
	std::vector<Sweeper*> sweepers;
	Level level;
};

#endif // !GAME

