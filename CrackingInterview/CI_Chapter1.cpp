#include <algorithm> //for string sorting

#include "CI_Chapter1.h"
#include "Trace.h"

bool CI_Chapter1::question1STRING(const string str)
{
	for (unsigned int i = 0; i < str.length(); ++i)
	{
		for (unsigned int j = i + 1; j < str.length(); ++j)
		{
			if (str.at(i) == str.at(j))
				return false;
		}
	}
	return true;
}

bool CI_Chapter1::question1CHAR(const char * str)
{
	for (unsigned int i = 0; i < strlen(str) + 1; ++i)
	{
		for (unsigned int j = i + 1; j < strlen(str) + 1; ++j)
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

string CI_Chapter1::question3STRING(string str)
{
	for (unsigned int i = 0; i < str.length(); i++)
	{
		if (str.at(i) == ' ') //check if we found a space
		{
			str.replace(i, 1, "%20");
			i += 3; //exclude the additional new characters
		}
	}

	return str;
}

bool CI_Chapter1::question4STRING(string str)
{
	for (unsigned int i = 0; i < str.length(); i++) //first remove any spaces
	{
		if (str.at(i) == ' ')
			str.replace(i, 1, "");
	}

	unsigned int halfway = str.length() / 2;

	for (unsigned int i = 0; i < str.length(); i++)
	{
		if (halfway < i) //no need to go further than half of the string (adds safety)
			break;

		if (str.at(i) /*front*/ == str.at(str.length() - i - 1) /*back*/) //check the front back if the same
		{
		}

		else
			return false;
	}

	return true;
}

bool CI_Chapter1::question5STRING(string str1, string str2)
{
	if (str1.length() == str2.length()) //check if they are one edit away from being the same, or are the same
	{
		int edit = 0; // if this number is length - 1, then they are one edit away, otherwise they arent

		//this loop is checking how similar the two strings are
		for (unsigned int i = 0; i < str1.length(); ++i)
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

string CI_Chapter1::question6STRING(string str)
{
	string answer;

	unsigned int currentLocation(0), counter(0), iter(0);

	while (currentLocation < str.length())
	{
		//if there is a repeating string after the current locations string
		for (iter = 1; str.at(currentLocation) == str.at(currentLocation + iter); iter++)
		{
			//keep checking how far we can go until we dont have the same character
			counter++;
		}

		answer += str.at(currentLocation); //append the string
		if(counter > 0) //append how many times it occured (if it repeated more than once)
			answer += std::to_string(counter + 1);

		currentLocation += (counter + 1); //move further in the given string
		counter = 0; //reset how many variables we encounter
	}


	return answer;
}

void CI_Chapter1::question8()
{
	const int rowSize(3), colSize(4);

	int matrix[rowSize][colSize]; //maze used throughout the problem

	for (int row = 0; row < rowSize; row++)
	{
		for (int col = 0; col < colSize; col++)
		{
			if (matrix[row][col] == 0) //the setting process
			{
				for (int rowIter = 0; rowIter < rowSize; rowIter++) //all the rows set to 0
					matrix[rowIter][col] = 0;

				for (int colIter = 0; colIter < colSize; colIter++) //all the columns set to 0
					matrix[row][colIter] = 0;
			}
		}
	}
	
	for (int row = 0; row < rowSize; row++) //show the matrix
	{
		for (int col = 0; col < colSize; col++)
		{
			Trace::out("%i ", matrix[row][col]);
		}
	}
}

