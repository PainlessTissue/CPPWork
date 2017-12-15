#include "Trace.h"

#include "CI_Chapter1.h"
#include "CI_Chapter2.h"
#include "CI_Chapter3.h"
#include "CI_Chapter12.h"

//used to detect memory leaks
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

#include <iostream>


int main()
{
	//CI_Chapter12 a;

	//a.question2("animal");
	
	_CrtDumpMemoryLeaks();
}

