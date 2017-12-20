#include "ArraySorts.h"
#include "LinkedList.h"
#include "UniqueLL.h"
#include "Maze.h"
#include "BinaryTree.h"
#include "String.h"

//used to detect memory leaks
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>


int main()
{
	String d("finger");

	d += " me daddy";

	_CrtDumpMemoryLeaks();
}