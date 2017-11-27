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

bool CI_Chapter1::question5STRING(string str1, string str2)
{
	if (str1.length() == str2.length()) //check if they are one edit away from being the same, or are the same
	{
		int edit = 0; // if this number is length - 1, then they are one edit away, otherwise they arent
		
		//this loop is checking how similar the two strings are
		for (int i = 0; i < str1.length(); ++i)
		{
			if (str1.at(i) == str2.at(i))
				++edit;
		}

		if (edit == str1.length())
			return true; //they are the same string

		else if (edit == str1.length() - 1)
			return true; //one edit way

		else
			return false; //not one edit away
	}

	else if (str1.length() + 1 == str2.length() || str1.length() - 1 == str2.length()) //possiblity of being one edit away (modifying str1)
	{
//
	}
		
		
	return false;
}

