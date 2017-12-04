#include "DEC_Pizza.h"
#include "DEC_Condiment.h"


#include "Trace.h"
#include <iostream>
#include <string>


int main()
{
	Pizza *piz = new CheesePizza;

	piz = new Pep(piz);
	piz = new Sausage(piz);

	std::cout << piz->getCost() << piz->getName();
	std::cin.ignore();
	

	delete piz;

	_CrtDumpMemoryLeaks();

	
	
	return 0;
}