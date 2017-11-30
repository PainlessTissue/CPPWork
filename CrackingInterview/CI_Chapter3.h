#include "Trace.h"

class CI_Chapter3 //stacks and queues
{
public:

	void question1(); //describe how you could use a single array to implement three stacks

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

