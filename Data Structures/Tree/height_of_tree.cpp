// C++ program to find height of tree
#include <iostream>
using namespace std;

struct Node
{
	int data;
	struct Node* left;
	struct Node* right;

	Node(int data)
	{
		this->data = data;
		left = right = NULL;
	}
};

int height(Node* root)
{
	if (root == NULL)
		return 0;

	return 1 + max(height(root->right), height(root->left));
}


// Driver code
int main()
{
	struct Node *root = new Node(1);

	root->left = new Node(2);
	root->right = new Node(3);
	root->left->left = new Node(4);
	root->left->right = new Node(5);

	cout << "Height of tree is " << height(root) << endl;
	return 0;
}

