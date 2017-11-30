#include "PointerStack.h"



PointerStack::PointerStack()
	:minNum(0), top(0), size(0) {}

PointerStack::~PointerStack()
{
	erase();
}

int PointerStack::pop()
{
	if (size == 0)
		return 0;

	else if (size == 1)
	{
		size--;
		int pop = *top;

		delete top; //no memory leaks
		top = 0; //set to 0 for pushing purposes

		return pop;
	}

	else
	{
		int pop = *top; //actual variable being removed

		int *tmp = new int[size - 1]; //reduce the new array size by one (since we are removing)

		int i; //counter

			   //copy all the data
		for (i = 1; i < size; i++)  //starting at 1 because we need to ignore pop-ed variable
		{
			*tmp = *(top + i);

			tmp++;
		}

		tmp -= (i - 1); //move to front of list

		delete top; //no memory leaks

		top = tmp; //set top to new pointer
		size--; //reduce offical size

		return pop;
	}
}

void PointerStack::push(int item)
{

	if (item < minNum) //set the min value first
		minNum = item;


	if (top == 0) //empty stack
	{
		top = new int(item);
		size++;
	}

	else
	{
		size++;

		int *tmp = new int[size]; //make a new array the size of the list

		*tmp = item; //set the head

		tmp++; //move forward 

		int i;

		for (i = 0; i < size - 1; i++) //copy all the data
		{
			*tmp = *(top + i);

			tmp++;
		}

		tmp -= (i + 1); //go back to start of head

		delete top; //no memory leaks from past allocation

		top = tmp; //set the top to our tmp
	}
}

int PointerStack::getMin()
{
	return minNum;
}

void PointerStack::erase()
{
	delete top;
}

void PointerStack::print()
{
	for (int i = 0; i < size; i++)
		Trace::out("%i\n", *(top + i));
}
