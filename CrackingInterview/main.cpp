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
	StackMin a;

	a.push(3);
	a.push(4);
	a.push(43);
	Trace::out("POPPED: %i\n", a.pop());
	Trace::out("POPPED: %i\n", a.pop());
	Trace::out("POPPED: %i\n", a.pop());
	a.push(32);
	Trace::out("POPPED: %i\n", a.pop());


	_CrtDumpMemoryLeaks(); //check if anything is leaking after delete

}