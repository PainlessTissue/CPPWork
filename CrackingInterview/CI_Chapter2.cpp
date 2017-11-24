#include "CI_Chapter2.h"
#include "Trace.h"

#include <random> //for list creation
#include <ctime> //for seed generation
#include <iostream>
#include <string>
using std::string;
using std::cout;
using std::cin;

void CI_Chapter2::showList()
{
	Node *iter = head;

	int counter = 0;
	while (iter != 0)
	{
		if (counter % 25 == 0)
			Trace::out("\n");

		Trace::out("%i, ", iter->key);

		iter = iter->next;
		++counter;
	}

	Trace::out("\nList size: %i\n", counter);
}

void CI_Chapter2::showSortedList()
{
	sortList();
	showList();
}

void CI_Chapter2::question1()
{
	for (Node *upper = head; upper != 0; upper = upper->next)
	{
		for (Node *lower = upper->next; lower != 0; lower = lower->next)
		{
			if (upper->key == lower->key)
			{
				Node *move = lower->next; //for deletion and link purposes
				
				//removal process
				if(lower->prev) //safety
					lower->prev->next = lower->next;
				
				if (lower->next) //safety
					lower->next->prev = lower->prev;
				
				delete lower;
				
				if (move == 0) //this is for safety purposes, incase we are the end of the list
					break;

				lower = move;
			}

		}
	}
}

int CI_Chapter2::findSizeOfList()
{
	int counter = 0;

	for (Node *iter = head; iter != 0; iter = iter->next)
		++counter;

	return counter;
}

void CI_Chapter2::sortList()
{
	for (Node *upper = head; upper != 0; upper = upper->next)
	{
		for (Node *lower = upper->next; lower != 0; lower = lower->next)
		{
			if (upper->key > lower->key)
			{
				int tmp = upper->key;

				upper->key = lower->key;
				lower->key = tmp;
			}
		}
	}
}

Node * CI_Chapter2::getKInList(int k)
{
	int counter = 0;
	for (Node *iter = head; iter != 0; iter = iter->next)
	{
		if (counter == k)
			return iter;

		++counter;
	}

	return nullptr;
}

void CI_Chapter2::question2(int k)
{
	int counter = 0;
	Node *iter = head;
	while (iter != 0 && counter != k)
	{
		iter = iter->next;
		++counter;
	}

	//assuming we found the kth
	if (iter != 0)
		Trace::out("\n%i\n", iter->key);

	else
		Trace::out("\nNumber too large for list size\n");
}

void CI_Chapter2::question3(Node * remove)
{
	//(void*)remove; //assuming the given node is a valid node to remove (this is to shut up warnings)

	Node *iter = head;
	while (iter != 0 && iter->next != remove)
		iter = iter->next;
	

	if (iter != 0 && iter->next == remove) //check and safety
	{
		iter->next = remove->next;
		remove->prev = 0;
		remove->next = 0;
		
		delete remove;
	}
}

void CI_Chapter2::question5()
{
	string list;

	int i = 1;
	for (Node *iter = tail; iter != 0 && i < 5; iter = iter->prev)
	{
		list.append(std::to_string(iter->key));
		list.append(" ");
		
		if (i % 25 == 0) //formatting
			list.append("\n");
		++i;
	}
	
	//Trace::out("\n%s\n", list);
	cout << list;
	cin.ignore();
}

bool CI_Chapter2::question6()
{
	Node *headIter = head;
	Node *tailIter = tail;

	while (headIter != 0 && tailIter != 0)
	{
		if (headIter->key == tailIter->key) {}

		else
			return false;
	}

	return true;
}

bool CI_Chapter2::question7(Node *firstHead, Node *secondHead)
{
	for (Node *firstIter = firstHead; firstIter != 0; firstIter = firstIter->next)
	{
		for (Node *secondIter = secondHead; secondIter != 0; secondIter = secondIter->next)
		{
			if (firstIter == secondIter)
				return true;
		}
	}

	return false;
}

Node * CI_Chapter2::question8()
{
	for (Node *iter = head; iter != 0; iter = iter->next)
	{
		for (Node *lower = head->next; lower != 0; lower = lower->next)
		{
			if (iter == lower)
				return iter;
		}
	}

	return nullptr;
}










void CI_Chapter2::createList()
{
	srand(GetTickCount());

	head = new Node(rand() % 300);

	Node *iter = head;
	head->prev = 0;

	int i = 1;
	Node *past = 0;
	while (iter != 0 && i < 300)
	{
		past = iter;
		iter->next = new Node(rand() % 300);

		iter = iter->next;
		iter->prev = past;
		++i;
	}
	tail = iter;
}