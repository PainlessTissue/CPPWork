#include "Tries.h"
#include "Trace.h"


void Tries::recursiveHelper(Digit * node, int iter, const char * arr, int numLen, const char * address)
{
	GenericDigit *Gnode = (GenericDigit*)node;
	int arrayNum = arr[iter] - '0';
	if (iter == numLen - 1)
	{
		Gnode->digitArray[arrayNum] = new FinalDigit(arr[arrayNum], address, arr);
		return;
	}

	else
	{
		if (Gnode->digitArray[arrayNum] == 0)
			Gnode->digitArray[arrayNum] = new GenericDigit(arrayNum);

		recursiveHelper(Gnode->digitArray[arrayNum], iter + 1, arr, numLen, address);
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

FinalDigit::FinalDigit(int num, const char * address, const char * number)
	:address(address), numberString(number)
{
	this->number = num;
}

FinalDigit::~FinalDigit()
{
	delete address;
	delete numberString;
}
