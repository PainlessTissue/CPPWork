#include "Tries.h"
#include "Trace.h"


void Tries::recursiveHelper(Digit * node, int iter, const char * arr, int numLen, const char * address)
{
	if (iter >= numLen)
		return;
	else
	{
		if (node->digitArray[arr[iter] - '0'] == 0)
			node->digitArray[arr[iter]] = new GenericDigit(arr[iter]);

		recursiveHelper(node->digitArray[arr[iter]], iter + 1, arr, numLen, address);
	}
}

void Tries::createNumber(Digit * head, const char * arr, int arrayLen, const char * address)
{
	if (head == 0)
		head = new GenericDigit(1);

	recursiveHelper(head, 1, arr, arrayLen, address);
}

GenericDigit::GenericDigit(int num)
{
	for (int i = 0; i < 10; i++)
		this->digitArray[i] = 0;
	this->number = num;
}

GenericDigit::~GenericDigit()
{
	for (int i = 0; i < 10; i++)
	{
		if (this->digitArray[i] != 0)
			delete this->digitArray[i];
	}
}
