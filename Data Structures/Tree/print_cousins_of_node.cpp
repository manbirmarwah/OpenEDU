#include<iostream>
using namespace std;


class Node
{
public :
	int data;
	Node* left;
	Node* right;

	Node(int data)
	{
		this->data = data;
		left = right = NULL;
	}
};


int getLevel(Node *root, Node *node, int level)
{

	// base cases
	if (root == NULL)
		return 0;
	if (root == node)
		return level;

	// If node is present in left subtree
	int downlevel = getLevel(root->left,
	                         node, level + 1);
	if (downlevel != 0)
		return downlevel;

	// If node is not present in left subtree
	return getLevel(root->right, node, level + 1);
}

/* Print nodes at a given level such that
sibling of node is not printed if it exists */
void printGivenLevel(Node* root, Node *node, int level)
{
	// Base cases
	if (root == NULL || level < 2)
		return;

	// If current node is parent of a node
	// with given level
	if (level == 2)
	{
		if (root->left == node || root->right == node)
			return;
		if (root->left)
			cout << root->left->data << " ";
		if (root->right)
			cout << root->right->data;
	}

	// Recur for left and right subtrees
	else if (level > 2)
	{
		printGivenLevel(root->left, node, level - 1);
		printGivenLevel(root->right, node, level - 1);
	}
}

// This function prints cousins of a given node
void printCousins(Node *root, Node *node)
{
	// Get level of given node
	int level = getLevel(root, node, 1);

	// Print nodes of given level.
	printGivenLevel(root, node, level);
}

int main()
{
	Node *root = new Node(1);
	root->left = new Node(2);
	root->right = new Node(3);
	root->left->left = new Node(4);
	root->left->right = new Node(5);
	root->left->right->right = new Node(15);
	root->right->left = new Node(6);
	root->right->right = new Node(7);
	root->right->left->right = new Node(8);

	printCousins(root, root->left->right);
	cout << endl;

	return 0;
}