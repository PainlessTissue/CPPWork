#include "Trace.h"

#include "CI_Chapter1.h"
#include "CI_Chapter2.h"
#include "CI_Chapter3.h"

//used to detect memory leaks
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>


int main()
{
	SetOfStacks a;

	for (int i = 0; i < 200; i++)
		a.push(2);
	
	for (int i = 0; i < 100; i++)
		a.pop();

	Trace::out("%i\n", a.pop());

	a.erase();

	_CrtDumpMemoryLeaks(); //check if anything is leaking after delete

}

