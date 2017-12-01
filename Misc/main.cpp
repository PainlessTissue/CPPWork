#include "ArraySorts.h"
#include "LinkedList.h"
#include "UniqueLL.h"
#include "Maze.h"
#include "BinaryTree.h"

int main()
{
	BinaryTree *head = BinaryTree::createTree();// = new BinaryTree;
	
	head->sort(head);
	//Trace::out("In order\n");
	//head->inOrderTraversal(head);
	//Trace::out("\n\n");

	//Trace::out("Post order\n");
	//head->postOrderTraversal(head);
	//Trace::out("\n\n");

	//Trace::out("Pre order\n");
	//head->preOrderTraversal(head);
	//Trace::out("\n\n");
}