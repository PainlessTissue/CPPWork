#include "ArraySorts.h"
#include "LinkedList.h"
#include "UniqueLL.h"
#include "Maze.h"
#include "BinaryTree.h"
#include "String.h"
#include "HashTable.h"

//used to detect memory leaks
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

int main()
{
	HashTable *table = HashTable::getInstance();

	table->addBook("Grandma Eats cows");
	table->addBook("Fingers and their friend");
	table->addBook("Hey");
	table->addBook("Grandma and her korean friend");
	table->addBook("yeH");
	table->addBook("German CookieSHeet");

	table = HashTable::getInstance();
	delete table;

	_CrtDumpMemoryLeaks();
}