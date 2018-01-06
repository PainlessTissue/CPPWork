
//a hash table implementation using storing books as an example to sort

class vNode;
class hNode;

//a hashtable that holds all the information required for the table itself.
//implemented as a singleton so we dont have too many hashtables at once
class HashTable
{
	vNode *vHead; //beginning of hashtable
	static HashTable *instance; //singleton instance of hashtable

	HashTable();

	int createHash(const char *str);
	void addToList(const char *bookTitle, int hashId);

public:
	//singleton instance because there is no need for more than one table
	static HashTable *getInstance();

	~HashTable();

	void addBook(const char *bookTitle);
};

//this is the class that represents the "verticle" nodes, the ones that get the hash id
class vNode
{
	hNode *hHead; //each node has a horizontal node that is however many nodes the node holds
	vNode *below; //each vNode has a node thats below where it is currently 
	int hashID;
	
public:
	//no default constructor, if a vNode is being created, 
	//it needs a hashId for the node itself, and a book title for its hNode
	vNode(int ID, const char *bookTitle);
	~vNode();	

	int getId() { return hashID; }
	vNode *getNext() { return below; }
	void setNext(vNode *next) { this->below = next; }
	void addNode(const char *bookTitle);

};

//this is the class that represents the "horizontal" nodes, the ones that actually own the data
class hNode
{
	hNode *next; //each hNode has a next pointer to the next item in line
	char *bookTitle; //and the hNodes store the actual book title

	
public:
	//no default constructor, if youre making a hNode, it has to come with a book title
	hNode(const char *title);
	~hNode();

	hNode *getNext() { return next; }
	void setNext(hNode *next) { this->next = next; }
};