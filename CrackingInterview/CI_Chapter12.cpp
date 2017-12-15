#include "CI_Chapter12.h"

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
using namespace std;


void CI_Chapter12::question1(int numLines)
{
	//this is just to make a simple text file to read from
	ofstream openFile("dog.txt"); //opens file in constructor
	//openFile.open("dog.txt");

	openFile << "First line\n second line \n thirdline";

	openFile.close();
	//end file creation for test
	

	//actual code to fine last k
	ifstream file("dog.txt");
	int numlines = 0;
	
	string str;

	//see how many lines are in the file
	for (; getline(file, str); numlines++)
	{
	}

	//close file, then re open it to do reading
	file.close();
	file.open("dog.txt");
	
	vector<string> lines;

	//get to the line in the file we want to start reading from
	for (int i = 0; i < numlines - numLines; i++)
	{
		getline(file, str);
	}

	while (numLines> 0)
	{
		numLines--;
		getline(file, str); //move to next line
		lines.push_back(str); //add to list
	}


	//print
	while (lines.size() > 0)
	{
		cout << lines.front() << endl;
		lines.pop_back();
	}
	cin.ignore();
}

void CI_Chapter12::question2(char * str)
{
	string s; //reversed string

	for (int i = 0; i <= strlen(str); i++)
		s += str[strlen(str) - i]; //concatinate the backward string

	//print
	cout << s;
	cin.ignore();
}

void CI_Chapter12::question3()
{
	/*
	a hash table sorts and finds variables by their hash code
	while a stl map finds and sorts input by their mapped to variable
	ex: map<int, string> finds the int theyre associated with, 
	and then stores the string according to int
	*/
}

void CI_Chapter12::question4()
{
	/*
	virtual functions are to correctly achieve runtime polymorphism.
	virutal functions are meant to be overriden by the children, 
	they also allow to create pure virtual functions, or interfaces
	*/
}

void CI_Chapter12::question5()
{
	/*
	deep and shallow copying is the idea of creating a variables own data VS just being another instance of that variable
	shallow copying is having a pointer point to another pointer, in essence just being another varible poiting to the same spot
	this makes it so if either variable changes changes, both change
	
	Ex: foo *d(5); (create variable)
		foo *r = d; (shallow copy r)
		r->num = 4; (change r's num, as well as d's)

	deep copying is taking the same data as one variable, but making a new, seperate instance of the varible
	this makes it so you can change either variable, and it wont effect the other one
	
	Ex: foo *d(5); (create variable)
		foo *r = new foo; (create own instance of foo variable)
		r->num = d->num; (deep copy num into r, making own instance of it)
		r->num = 2; (r's num is now 2, d's is still 5)
	*/
}
void CI_Chapter12::question6()
{
	/*
	volitile is used to make it so the compiler doesnt optimize your code during runtime
	this is useful because if outside factors are changing the varibles, having the 
	comiler optimize the code may lead to unforseen circumstances you cant easily control
	*/
}

void CI_Chapter12::question7()
{
	/*
	the purpose of the virutal destructor is so when a parent is deleted, it deletes
	all children associated before it deletes the parent itself
	*/
}
