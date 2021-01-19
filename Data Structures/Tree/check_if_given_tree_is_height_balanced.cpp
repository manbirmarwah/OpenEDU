
#include <bits/stdc++.h>
using namespace std;

/* A binary tree node has data,
pointer to left child and
a pointer to right child */
class node {
public:
	int data;
	node* left;
	node* right;
};

bool isBalanced(Node* root)
{
	if (root == nullptr)
		return true;
	int lh, rh;

	lh = height(root->left);
	rh = height(root->right);

	if (abs(lh - rh) <= 1 && isBalanced(root->left) && isBalanced(root->rght))
		return true;

	return false;
}

int height(node* node)
{
	/* base case tree is empty */
	if (node == NULL)
		return 0;

	/* If tree is not empty then
	height = 1 + max of left
	    height and right heights */
	return 1 + max(height(node->left),
	               height(node->right));
}

int main()
{
	node* root = new Node(1);
	root->left = new Node(2);
	root->right = new Node(3);
	root->left->left = new Node(4);
	root->left->right = new Node(5);
	root->left->left->left = new Node(8);

	if (isBalanced(root))
		cout << "Tree is balanced";
	else
		cout << "Tree is not balanced";
	return 0;
}