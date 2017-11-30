#include <iostream>
#include <stack>
#include <queue>
using std::queue;
using std::stack;

#include "CI_Chapter3.h"

//static variables for StackMin
int StackMin::minNum = 0;
StackMin *StackMin::top = 0;

StackMin::StackMin()
	:num(0), next(0) {}

StackMin::StackMin(int item)
	: num(item), next(0) {}

StackMin::StackMin(const StackMin * stack)
	: num(stack->num), next(stack->next) {}

int StackMin::pop()
{
	if (top == 0)
		return 0;


	int tmp = top->num;

	top = top->next;

	//delete top;

	return tmp;
}

void StackMin::push(int item)
{
	if (top == 0) //no stack
	{
		top = new StackMin(item);
		minNum = item;
	}

	else
	{
		if (item < minNum)
			minNum = item;


		this->next = new StackMin(top);
		top = this;
		top->num = item;
	}
}

void StackMin::erase()
{
	StackMin *tmp = 0;

	while (top != 0)
	{
		tmp = top->next;

		//delete top;

		top = tmp;
	}
}

//static variable for SetOfStacks
SetOfStacks *SetOfStacks::head = new SetOfStacks;

SetOfStacks::SetOfStacks()
	:below(0), above(0) {}


SetOfStacks::~SetOfStacks()
{
}


void SetOfStacks::push(int item)
{
	if (head->Stack.size() >= 50)
	{
		SetOfStacks *tmp = head; 

		head->above = new SetOfStacks;
		head->above->below = tmp;

		head = head->above;
	}

	head->Stack.push(item);
}

int SetOfStacks::pop()
{
	if (head->Stack.size() == 0)
	{
		if (head->below)
		{
			SetOfStacks *tmp = head->below;
			delete head; 
			head = tmp;
			head->above = 0;
		}

		else
			return 0;
	}
	
	//I dont know why but this is necessary. I cant just return head->stack.pop()
	//i need a variable of the top then i can pop it
	int d = head->Stack.top();
	head->Stack.pop();
	return d;
}

void SetOfStacks::erase()
{
	SetOfStacks *bel = 0;

	while (head != 0)
	{
		bel = head->below;

		delete head;

		head = bel;
	}
}
