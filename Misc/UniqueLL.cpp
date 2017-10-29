#include "UniqueLL.h"

UniqueLL::UniqueLL()
{
	this->next = 0;
	this->prev = 0;
	this->id = 0;
}

UniqueLL::UniqueLL(int const &id)
{
	this->id = id;
	this->next = 0;
	this->prev = 0;
}


UniqueLL::~UniqueLL()
{
	delete next;
	delete prev;
	delete this;
}

bool UniqueLL::inList(UniqueLL * head, int num)
{
	UniqueLL *iter = head;

	while (iter != 0)
	{
		if (iter->id == num)
			return true;

		iter = iter->next;
	}

	return false;
}

void UniqueLL::addToList(UniqueLL * head, int num)
{
	UniqueLL *iter = head;

	if (head == 0)
		head->id = num;


	while (iter->next != 0)
		iter = iter->next;


	if (iter->next == 0)
	{
		iter->next = new UniqueLL(num);

		iter->next->prev = iter;
	}
}

void UniqueLL::display(UniqueLL * head)
{
	UniqueLL *tmp = head;

	int count = 0;
	while (tmp != 0)
	{
		Trace::out("%i, ", tmp->id);

		tmp = tmp->next;

		//just to make things look a little prettier
		if (++count % 25 == 0) Trace::out("\n");
	}

	Trace::out("Size of list: %i\n", count);
}

void UniqueLL::sortList(UniqueLL * head)
{
	for (UniqueLL *uIter = head; uIter != 0; uIter = uIter->next)
	{
		for (UniqueLL *lIter = head; lIter != 0; lIter = lIter->next)
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
