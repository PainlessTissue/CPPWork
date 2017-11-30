#include "Trace.h"

//custom stack done entirely through pointer math
class PointerStack
{
public:
	PointerStack();
	~PointerStack();

	int pop();
	void push(int item);
	int getMin();
	void erase(); //function used to remove all unncessary pointer (needed if not allocating on heap
	void print(); //simple printing function to see whats in stack

private:
	int minNum, size, *top;
};

