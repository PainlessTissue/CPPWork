#include "BinaryTree.h"
#include "Trace.h"

#include <random>
#include <time.h>

int BinaryTree::nodeNum = 0;


BinaryTree::BinaryTree()
	:num(0), left(0), right(0)
{
	srand(time(NULL));
}


BinaryTree::~BinaryTree()
{
}

BinaryTree * BinaryTree::createTree()
{
	//first two rows (head and row 2)
	BinaryTree *head = new BinaryTree(rand() % 200);
	head->left = new BinaryTree(rand() % 200);
	head->right = new BinaryTree(rand() % 200);

	//third row, left side
	head->left->left = new BinaryTree(rand() % 200);
	head->left->right = new BinaryTree(rand() % 200);

	//third row, right side
	head->right->left = new BinaryTree(rand() % 200);
	head->right->right = new BinaryTree(rand() % 200);


	return head;
}

void BinaryTree::sort(BinaryTree * head)
{
	bool d = false;

	do
	{
		sortHelper(head);
		checkSorted(head, d);
	} while (d == false);
}

void BinaryTree::inOrderTraversal(BinaryTree * head)
{
	if (head != 0)
	{
		inOrderTraversal(head->left);
		Trace::out("%i, ", head->num);
		inOrderTraversal(head->right);
	}
}

void BinaryTree::preOrderTraversal(BinaryTree * head)
{
	if (head != 0)
	{
		Trace::out("%i, ", head->num);
		preOrderTraversal(head->left);
		preOrderTraversal(head->right);
	}
}

void BinaryTree::postOrderTraversal(BinaryTree * head)
{
	if (head != 0)
	{
		postOrderTraversal(head->left);
		postOrderTraversal(head->right);
		Trace::out("%i, ", head->num);
	}
}

void BinaryTree::checkSorted(BinaryTree *node, bool &status)
{
	if (node)
	{
		if (node->left)
		{
			if (node->num > node->left->num)
			{
				status = true;
				checkSorted(node->left, status);
			}

			else
				status = false;
		}

		else
			status = true;

		if (node->right)
		{
			if (node->num < node->right->num)
			{
				status = true;
				checkSorted(node->right, status);
			}

			else
				status = false;
		}

		else 
			status = true;
	}

	status = true;
}

void BinaryTree::sortHelper(BinaryTree * node)
{
	if (node != 0)
	{
		if (node->left)
		{
			if (node->num < node->left->num) //left node is greater than current node (shouldnt be)
			{
				int tmp = node->num;

				node->num = node->left->num;
				node->left->num = tmp;
			}

			else if (node->num > node->left->num) //if left node is less than current node (Correct)
			{
			}
		} //node->left

		else if (node->right)
		{
			if (node->num > node->right->num) //if right node is less than current node (shouldnt be)
			{
				int tmp = node->num;

				node->num = node->right->num;
				node->right->num = tmp;
			}

			else if (node->num < node->right->num) //if right node is greater than current node (correct)
			{
			}
		} //node->right

		sortHelper(node->left);
		sortHelper(node->right);
	} //node != 0
}

