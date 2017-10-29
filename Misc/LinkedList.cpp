#include <iostream>
#include <time.h>

#include "LinkedList.h"



LinkedList::LinkedList()
	:next(0), prev(0), id(0) {}

LinkedList::LinkedList(LinkedList const *newLL)
{

}

LinkedList::LinkedList(LinkedList const &newLL)
{
	this->next = new LinkedList(newLL.next);
	this->prev = new LinkedList(newLL.prev);

	id = newLL.id;
}

LinkedList LinkedList::operator=(LinkedList const &newLL)
{
	this->next = new LinkedList(newLL.next);
	this->prev = new LinkedList(newLL.prev);

	id = newLL.id;

	return *this;
}

LinkedList::~LinkedList()
{
	delete next;
	delete prev;
	delete this;
}

const LinkedList * LinkedList::getNext()const
{
	return next;
}

const LinkedList * LinkedList::getPrev()const
{
	return prev;
}

const int LinkedList::getId() const
{
	return this->id;
}

const void LinkedList::setNext(LinkedList * const next)
{
	this->next = next;
}

const void LinkedList::setPrev(LinkedList * const prev)
{
	this->prev = prev;
}

const void LinkedList::setInt(int const id)
{
	this->id = id;
}

void LinkedList::createLL(LinkedList * head, int sizeOfLinkedList)
{
	LinkedList *tmp = head;

	for (int i = 0; i < 100; i++)
	{
		//sets the id to something between 50 everytime
		int setID = rand() % 100;

		//set the id of the node
		tmp->id = setID;

		//make a new next variable
		tmp->next = new LinkedList();

		//set the next to the current node
		tmp->next->prev = tmp;

		//keep going
		tmp = tmp->next;
	}
}

void LinkedList::display(LinkedList * head)
{
	LinkedList *tmp = head;

	int count = 0;

	while (tmp != 0)
	{
		//display number
		Trace::out("%i, ", tmp->id);

		tmp = tmp->next;

		//just to make things look a little prettier
		if (++count % 25 == 0) Trace::out("\n");
	}

	Trace::out("Size of list: %i", count);

}

void LinkedList::sortList(LinkedList * head)
{
	for (LinkedList *uIter = head; uIter != 0; uIter = uIter->next)
	{
		for (LinkedList *lIter = head; lIter != 0; lIter = lIter->next)
		{
			if (uIter->id < lIter->id)
			{
				int tmp = uIter->id;

				uIter->id = lIter->id;

				lIter->id = tmp;
			}
		}
	}

}
