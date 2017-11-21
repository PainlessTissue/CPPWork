#include <random> //for random

#include "Maze.h"
#include "Trace.h"

Maze::Maze()
	:sucessfulMaze(false) //assume false
{

	//these two are for setting the boundaries
	for (int i = 0; i < ROWS; i++)
	{
		maze[0][i] = BOUNDARY;
		maze[ROWS - 1][i] = BOUNDARY;
	}

	for (int i = 0; i < COLUMNS; i++)
	{
		maze[i][0] = BOUNDARY;
		maze[i][COLUMNS - 1] = BOUNDARY;
	}

	do //make sure i create a good maze
	{
		srand(GetTickCount()); //resets seed
		
		//this is for setting the maze
		for (int i = 1; i < ROWS - 1; ++i)
		{
			for (int j = 1; j < COLUMNS - 1; ++j)
			{
				maze[i][j] = (rand() % 2);
			}
		}


		Trace::out("\n");
	} while (testMaze() == false);
}


Maze::~Maze()
{
}

void Maze::print()
{
	for (int i = 0; i < ROWS; i++) //for displaying purposes
	{
		for (int j = 0; j < COLUMNS; j++)
		{
			Trace::out("%i", maze[i][j]);
		}
		Trace::out("\n");
	}
}

bool Maze::testMaze()
{
	searchMaze(1, 1); //start off the boundaries

	return sucessfulMaze;
}

void Maze::searchMaze(int row, int col)
{
	if (maze[row][col] == CLOSED)
	{
	}

	else if (maze[row][col] == OPEN) //base case
	{
		//Trace::out("%i, %i free\n", row, col);

			searchMaze(++row, col);

			searchMaze(row, ++col);

		
		//else if (maze[row - 1][col] == OPEN) //move up
		//	searchMaze(--row, col);

		//else if (maze[row][col - 1] == OPEN) //move left
		//	searchMaze(row, --col);

	}

	else if (maze[row][col] == BOUNDARY) //if we ever reach a boundary, success (for now)
	{
		if (sucessfulMaze == true) {}
			//sucessfulMaze = true;
		else
			sucessfulMaze = true;
	}
}

