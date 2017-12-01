
class BinaryTree
{
public:
	BinaryTree();
	BinaryTree(const int numer)
		:num(numer) {}

	~BinaryTree();

	//create the tree, returns the head of the tree
	static BinaryTree *createTree();

	void sort(BinaryTree *head);

	void inOrderTraversal(BinaryTree *head);
	void preOrderTraversal(BinaryTree *head);
	void postOrderTraversal(BinaryTree *head);

private:
	bool checkSorted(BinaryTree *node);
	void sortHelper(BinaryTree *node);

	int num;
	BinaryTree *left, *right;

	static int nodeNum;
};

