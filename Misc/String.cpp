#include "String.h"

#include <iostream> //needed for c-string operations


int String::sizeOf(const char *string)
{
	int iter = 0;

	//loop through to find the right size of string ('/0' is NULL)
	for (iter; string[iter] != '\0'; iter++)
	{
	}

	return iter;
}

String::String(const char * string)
{
	int size = sizeOf(string);
	this->str = new char[size + 1];

	//truncate is a little cheat i found while googling. 
	//it does all the work for me when asking for size
	strcpy_s(this->str, _TRUNCATE, string);
}

String::~String()
{
	delete str;
}


void String::operator+=(const char * string)
{
	//temp variable of current string
	const char *tmp = this->str;
	
	//override the old string variable with a clean slate, being the size of both 
	str = new char[sizeOf(tmp) + sizeOf(string) + 1];

	strcpy_s(this->str, _TRUNCATE, tmp); //copy all the data over
	strcat_s(this->str, _TRUNCATE, string); //concatinate the new string on top
}

char String::charAt(int index)
{
	return str[index];
}
