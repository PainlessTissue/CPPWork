#include "HashTable.h"
#include <iostream>


HashTable::HashTable()
{
}


HashTable::~HashTable()
{
}

vNode::vNode(int ID)
	:head(0), below(0), hashID(ID) {}

vNode::~vNode()
{
	hNode *iter(head), *next(0);

	while (iter != 0)
	{
		next = iter->getNext();
		delete iter;
		iter = next;
	}
}

hNode::hNode(const char * title)
	:next(0)
{
	bookTitle = new char[strlen(title) + 1]; //allocate necessary space
	strcpy_s(bookTitle, strlen(title) + 1, title); //copy into buffer
}

hNode::~hNode()
{
	delete bookTitle;
}
