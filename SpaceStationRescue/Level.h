#pragma once

#include "Ground.h"
#include "Obstacle.h"
#include "Worker.h"
#include "Sweeper.h"

class Level
{
public:
	Level();
	~Level();
	void setupLevel(std::vector<Ground*> &ground, std::vector<Obstacle*> &walls, std::vector<Worker*> &workers, std::vector<Sweeper*> &sweepers);
	void init(float worldUnit);

private:

	static const int maxCol = 60;
	static const int maxRow = 66;

	static const int level1Layout[maxCol][maxRow];
	//int m_currentLevel;
	int* m_pointerToLevel;

	float m_worldUnit;
};

