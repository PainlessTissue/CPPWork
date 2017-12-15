#include "CI_Chapter13.h"



void CI_Chapter13::question1()
{
	/*
	the purpose of private constructors in terms of inheritance is so, when creating a child (inheriting)
	you cannot make a parent while doing so. Instead, you have to use defined methods to create an object,
	which underlyingly may not allow that 
	*/
}

void CI_Chapter13::question2()
{
	/*
	finally is used typically in exception handling to do cleanup code when an exeption is called
	it is able to be called even after a return statement
	*/
}

void CI_Chapter13::question3()
{
	/*
	final makes it so a variable cannot be changed throughout the code after being declared 
	finally was stated above
	finalize is called for garbage collection when there is no more references to the object
	*/
}

void CI_Chapter13::question4()
{
	/*
	c++ templaces, or stl, are microsoft defined generic data structures that are meant to simplify
	a coders work by not worrying about the underlying code. Vector, list, or map are three common ones

	Generics in java are a similar idea, using names like ArrayList, Integer, or String to be type safe and simple
	to the programmer
	*/
}

void CI_Chapter13::question5()
{
	/*
	Hashmap is implemented as a hashtable and isnt ordered
		Best option: for simple data storage that can be accessed quickly. Good for templating out ideas
	Treemap is implemented as a red black tree and is ordered that way
		Best option: for fast access and quick runtime.
	Linkedhashmap is implemented to keep the insertion order
		Best option: for constant time pop and push, or O(n) time search

	*/
}

void CI_Chapter13::question6()
{
	/*
	object reflection is the idea of being able to inspect classes/objects, and their methods, and able to
	change objects during runtime. c++ supports object introspection, being able to inspect,
	but does not support reflection, being able to change the class

	This is useful because you can write code where you dont actually know everything about the class
	making it so you have versitile code
	*/
}
