#pragma once

class Level
{
public:
	Level();
	~Level();

private:

	static const int maxCol = 30;
	static const int maxRow = 39;

	static const int level1Layout[maxCol][maxRow];
};

