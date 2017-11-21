#pragma once

#define OPEN 0
#define CLOSED 1
#define BOUNDARY 2

#define COLUMNS 10
#define ROWS 10

class Maze
{
public:
	Maze();
	~Maze();

	void print();
private:
	int maze[ROWS][COLUMNS];
	bool sucessfulMaze;

	bool testMaze();
	void searchMaze(int row, int col);
};

