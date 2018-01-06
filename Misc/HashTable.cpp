#include "HashTable.h"

#include <iostream>

HashTable *HashTable::instance = 0;

HashTable::HashTable()
	:vHead(0) {}

int HashTable::createHash(const char * str)
{
	int hashId = 0;

	for (int i = 0; i < strlen(str); i++)
		hashId += str[i] * 3; //use the strings characters to make the hashId

	return hashId;
}

void HashTable::addToList(const char * bookTitle, int hashId)
{
	if (vHead == 0)
		vHead = new vNode(hashId, bookTitle);
	

	else
	{
		if (hashId < vHead->getId()) //create new head
		{
			vNode *tmp = new vNode(hashId, bookTitle); 
			tmp->setNext(vHead);
			vHead = tmp;
			return;
		}

		//loop through to put the node in the right spot
		for (vNode *iter = vHead; iter != 0; iter = iter->getNext())
		{
			if (iter->getId() == hashId) //if we are adding onto the hList
			{
				iter->addNode(bookTitle);
				return;
			}

			else if (hashId > iter->getId() && iter->getNext() == 0) //end of list, tail
			{
				iter->setNext(new vNode(hashId, bookTitle)); //add to end of list
				return;
			}
		
			else if (hashId > iter->getId() && hashId < iter->getNext()->getId())
			{
				vNode *tmp = iter->getNext();
				iter->setNext(new vNode(hashId, bookTitle));
				iter->getNext()->setNext(tmp);
				return;
			}
		}
	}
}

HashTable * HashTable::getInstance()
{
	if (instance == 0)
		instance = new HashTable;

	return instance;
}

HashTable::~HashTable()
{
	vNode *iter(vHead), *next(0);

	while (iter != 0)
	{
		next = iter->getNext();
		delete iter;
		iter = next;
	}
}

void HashTable::addBook(const char * bookTitle)
{
	int hashId = createHash(bookTitle);
	addToList(bookTitle, hashId);
}

vNode::vNode(int ID, const char *bookTitle)
	:hHead(0), below(0), hashID(ID)
{
	addNode(bookTitle);
}

vNode::~vNode()
{
	hNode *iter(hHead), *next(0);

	while (iter != 0)
	{
		next = iter->getNext();
		delete iter;
		iter = next;
	}
}

void vNode::addNode(const char * bookTitle)
{
	if (hHead == 0)
		hHead = new hNode(bookTitle);

	else
	{
		hNode *newHead = new hNode(bookTitle);
		newHead->setNext(hHead);
		hHead = newHead;
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
