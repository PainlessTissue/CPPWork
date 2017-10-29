#ifndef _ARRAYSORT
#define _ARRAYSORT

#include "Trace.h"

class ArraySorts
{
public:
	ArraySorts();
	~ArraySorts();

	void selectSort(int arr[], int size);
	void bubbleSort(int arr[], int size);
	int binarySearchRecursion(int arr[], int size, int num);
	int binarySearchIterative(int arr[], int size, int num);

	void showArray(int arr[], int size);
};

#endif //header guards