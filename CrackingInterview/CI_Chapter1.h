#include <iostream>
using std::string;

//strings and arraylists
class CI_Chapter1
{
public:
	//since c++ has operations with char pointers and strings, I will be doing both

	bool question1STRING(const string str); //is unique
	bool question1CHAR(const char *str); //is unique

	bool question2STRING(string str1, string str2); //check permutation
	bool question2CHAR( char * str1,  char * str2); //check permutation
	int stringCompare(const char*, const char*);
};

