#include <iostream>
#include <stack>
#include <queue>
using std::queue;
using std::stack;

#include "CI_Chapter3.h"

void CI_Chapter3::question1()
{

}



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
