#include "CI_Chapter1.h"
#include "Trace.h"

bool CI_Chapter1::question1(string str)
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
