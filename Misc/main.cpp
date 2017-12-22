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

template <typename T>
struct LL
{
	LL* next, *prev;
	T item;

	LL()
		:next(0), prev(0), item(0) {}

	void erase(LL<T> *head)
	{
		LL<T> *iter = head;
		LL<T> *nex = 0;

		while (iter != 0)
		{
			nex = iter->next;

			delete iter;

			iter = nex;
		}
	}

	~LL<T>()
	{
		delete item;
	}
};

struct obj
{
	int thing;

	obj()
		:thing(0) {}
};

struct newObj
{
	bool nay;

	newObj()
		:nay(false) {}
};

int main()
{
	//obj
	LL<obj*> *head = new LL<obj*>;
	head->item = new obj;

	head->next = new LL<obj*>;

	head->erase(head);

	LL<newObj*> *hHead = new LL<newObj*>;
	hHead->item = new newObj;

	hHead->next = new LL<newObj*>;
	hHead->next->item = new newObj;
	//hHead->next->item->nay = true;

	head->erase(head);

	_CrtDumpMemoryLeaks();
}