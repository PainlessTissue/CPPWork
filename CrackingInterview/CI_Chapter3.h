#include "Trace.h"
#include <stack>

class CI_Chapter3 //stacks and queues
{

};

//question 2: create a custom stack that implements push, pop, and getMin all in O(1) time
struct StackMin
{
	StackMin();
	StackMin(int item);
	StackMin(const StackMin *stack);
	~StackMin() = default;

	void erase();
	int pop();
	void push(int item);
	int getMin() { return minNum; }

private:

	int num;
	StackMin *next;

	static int minNum;
	static StackMin *top;

};

//question 3: create a stack that, when it gets too large, creates a new stack (similar to stacking plates)
struct SetOfStacks
{
	SetOfStacks();
	~SetOfStacks();

	void push(int item);
	int pop();
	void erase();

private:
	std::stack<int> Stack;
	SetOfStacks *below, *above;

	static SetOfStacks *head;
};

