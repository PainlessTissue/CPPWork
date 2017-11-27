
class CI_Chapter3 //stacks and queues
{
public:

	void question1(); //describe how you could use a single array to implement three stacks
	
};

struct StackMin //question 2: Implement a O(1) stack with min, pop, and push
{
private:
	float min, top, *p;
	

public:
	float pop()
	{

	}

	void push(float item)
	{
		if (item < min)
			min = item;
		
		
		

	}

	float getMin()
	{
		return min;
	}

};