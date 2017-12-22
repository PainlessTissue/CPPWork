
//a hash table implementation using storing books as an example to sort

class vNode;
class hNode;

class HashTable
{
	vNode *head;

public:
	HashTable();
	~HashTable();

	void addData(const char *bookTitle);
};

//this is the class that represents the "verticle" nodes, the ones that get the hash id
class vNode
{
	
	hNode *head; //each node has a horizontal node that is however many nodes the node holds
	vNode *below; //each vNode has a node thats below where it is currently 
	int hashID;

public:
	//no default constructor, if a vNode is being created, it needs a hashID
	vNode(int ID);
	~vNode();
};

//this is the class that represents the "horizontal" nodes, the ones that actually own the data
class hNode
{
	hNode *next; //each hNode has a next pointer to the next item in line
	char *bookTitle;

public:
	//no default constructor, if youre making a hNode, it has to come with a book title
	hNode(const char *title);
	~hNode();
	
	hNode *getNext() { return next; }
};