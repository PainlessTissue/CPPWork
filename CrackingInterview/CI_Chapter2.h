
struct Node; //forward decleration

			 //linked lists
class CI_Chapter2
{
public:
	CI_Chapter2()
	{ 
		createList(); 
	}

	//helper functions
	void showList();
	void showSortedList();
	Node *getKInList(int k);

	void question1(); //remove dups
	void question2(int k); //find Kth to last in SINGLY linked list
	void question3(Node *remove); //remove a node in the middle from SINGLY linked list (node doesnt have to be directly in middle)
	void question5(); //NOT FINISHED
	bool question6(); //check if palindrome
	bool question7(Node *firstHead, Node *secondHead); //check if two linked lists intersect (by address)
	Node *question8(); //check if a Linked List is circular, and return the node that is circular

private:
	//helper functions
	void createList();
	int findSizeOfList();
	void sortList();

	Node *head; //head node in class
	Node *tail; //tail node for class
};

struct Node //node class for Linked list
{
	Node(int key)
	{
		next = 0;
		prev = 0;
		this->key = key;
	}

	Node *next;
	Node *prev;
	int key;
};
