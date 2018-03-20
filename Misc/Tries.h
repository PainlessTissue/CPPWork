#pragma once

class Digit;
class GenericDigit;
class FinalDigit;

class Tries
{
public:
	static Digit *head;

	void recursiveHelper(Digit *node, int iter, const char* arr, int numLen, const char* address);
	Tries() {}

	void createNumber(Digit* head, const char* arr, int arrayLen, const char* address);
};

/*
my idea is to represent phone numbers using a trie structure
all nodes will inherit from the generic interface "Digit"
and all the information will be stored in the final node at the bottom
*/

//virtual interface class for inheriting
class Digit
{
public:
	int number;

	virtual ~Digit() {}
};

//these are all the numbers that represent 9 out of the 10 digits in a phone number
//they should only store the digits below them (children)
class GenericDigit : public Digit
{
public:
	Digit * digitArray[10];

	GenericDigit(int num);
	virtual ~GenericDigit();
};

//this is the final digit in the trie, storing all the further information
//regarding the phone number (address, name, email, etc)
class FinalDigit : public Digit
{
	char* address;
	char* numberString;

public:
	FinalDigit(int num, const char* address, const char *number);
	virtual ~FinalDigit();
};