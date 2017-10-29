#include "ArraySorts.h"

ArraySorts::ArraySorts() {}
ArraySorts::~ArraySorts() {}

void ArraySorts::selectSort(int arr[], int size)
{
	for (int index1 = 0; index1 < size; index1++)
	{
		for (int index2 = index1 + 1; index2 < size; index2++)
		{

			if (arr[index2] < arr[index1])
			{
				int tmp = arr[index2];

				arr[index2] = arr[index1];
				arr[index1] = tmp;
			}
		}
	}
}

void ArraySorts::bubbleSort(int arr[], int size)
{
	while (size-- >= 0)
	{
		for (int index = size - 1; index >= 0; index--)
		{
			if (arr[index] > arr[size])
			{
				int tmp = arr[index];
				arr[index] = arr[size];
				arr[size] = tmp;
			}
		}
	}
}

int ArraySorts::binarySearchRecursion(int arr[], int size, int num)
{
	int mid = size / 2;


	if (arr[mid] == num)
		return mid;


	else if (num > arr[mid])
		binarySearchRecursion(arr, (size + (mid / 2)), num);


	else if (num < arr[mid])
		binarySearchRecursion(arr, (mid / 2), num);

}

int ArraySorts::binarySearchIterative(int arr[], int size, int num)
{
	int mid = size / 2;

	while (arr[mid] != num && mid < size)
	{
		if (arr[mid] < num)
			mid = (mid + (mid / 2)) + 1;


		else if (arr[mid] > num)
			mid = (mid / 2) + 1;
	}

	return mid;
}

void ArraySorts::showArray(int arr[], int size)
{
	for (int i = 0; i < size; i++)
	{
		Trace::out("Contents of array\n");

		if (i % 25 == 0) //prettier formatting
			Trace::out("\n");

		Trace::out("%i", arr[i]);
	}
}
