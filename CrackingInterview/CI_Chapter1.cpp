#include <algorithm> //for string sorting

#include "CI_Chapter1.h"
#include "Trace.h"

bool CI_Chapter1::question1STRING(const string str)
{
	for (int i = 0; i < str.length(); ++i)
	{
		for (int j = i + 1; j < str.length(); ++j)
		{
			if (str.at(i) == str.at(j))
				return false;
		}
	}
	return true;
}

bool CI_Chapter1::question1CHAR(const char * str)
{
	for (int i = 0; i < strlen(str) + 1; ++i)
	{
		for (int j = i + 1; j < strlen(str) + 1; ++j)
		{
			if (str[i] == str[j])
			{
				return false;
			}
		}
	}
	return true;
}

bool CI_Chapter1::question2STRING(string str1, string str2)
{
	std::sort(str1.begin(), str1.end());
	std::sort(str2.begin(), str2.end());

	if (str1 == str2)
		return true;

	return false;
}

bool CI_Chapter1::question2CHAR( char * str1,  char * str2)
{
	(void*)str1;
	(void*)str2;
	return false;
	//qsort(str1, strlen(str1), sizeof(char*), stringCompare);
}

int CI_Chapter1::stringCompare(const char* p1, const char* p2)
{
	return strcmp(p1, p2);
}