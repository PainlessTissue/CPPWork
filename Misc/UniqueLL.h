#ifndef _UNIQUELL
#define _UNIQUELL

#include "Trace.h"

class UniqueLL
{
public:
	//TODO implement both next and prev in all of these
	UniqueLL();
	UniqueLL(int const &id);
	~UniqueLL();

	bool inList(UniqueLL *head, int num);
	void addToList(UniqueLL *head, int num);
	void display(UniqueLL *head);
	void sortList(UniqueLL *head);

private:
	UniqueLL *next;
	UniqueLL *prev;
	int id;
};

#endif //header guard