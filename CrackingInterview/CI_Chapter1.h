#include <iostream>
#include <string>
using std::string;

//strings and arraylists
class CI_Chapter1
{
public:	
	//since c++ has operations with char pointers and strings, I will be doing both
	
	//is unique
	bool question1STRING(const string str); 
	bool question1CHAR(const char *str); 

	//check permutation between two strings
	bool question2STRING(string str1, string str2); 
	//bool question2CHAR( char * str1,  char * str2); 

	//url-ify a string
	string question3STRING(string str); 
	
	//permutation check between single string ("taco cat", "race car")
	bool question4STRING(string str); 

	//check if a string is one(or 0) edits away from being the same string 
	bool question5STRING(string str1, string str2); //NOT FINISHED

	//string compression (aaaabbbc = a4b3c)
	string question6STRING(string str); //NOT FINISHED

	//set the rows and column of a matrix to 0 if any of them have 0
	void question8();
};

