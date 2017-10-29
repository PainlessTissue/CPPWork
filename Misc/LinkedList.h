#ifndef _LINKEDLIST
#define _LINKEDLIST

#include "Trace.h"

class LinkedList
{
public:
	LinkedList(); //default
	LinkedList(LinkedList const *newLL); //secialized
	LinkedList(LinkedList const &newLL); //copy
	LinkedList operator =(LinkedList const &newLL); //assignment
	virtual ~LinkedList(); //destructor 

						   //accessors
	const LinkedList *getNext() const;
	const LinkedList *getPrev() const;
	const int getId() const;

	//mutators
	const void setNext(LinkedList * const next);
	const void setPrev(LinkedList * const prev);
	const void setInt(int const id);

	//functions
	void createLL(LinkedList *head, int sizeOfLinkedList); //create the linked list
	void display(LinkedList *head); //display all the items in the linked list
	void sortList(LinkedList *head);

private:
	LinkedList *next;
	LinkedList *prev;
	int id;
};

#endif //header guard