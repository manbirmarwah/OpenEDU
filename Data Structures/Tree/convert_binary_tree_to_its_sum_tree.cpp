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

void preOrder(Node* root)
{
	if (root == nullptr)
		return ;
	cout << root->data << " ";
	preOrder(root->left);
	preOrder(root->right);
}

int sumTree(Node* root)
{
	if (root == NULL)
		return 0;

	int left = sumTree(root->left);
	int right = sumTree(root->right);

	int old = root->data;

	root->data = left + right;

	return root->data + old;
}

int main()
{
	Node* root = new Node(1);

	root->left = new Node(2);
	root->left->left = new Node(4);
	root->right = new Node(3);
	root->left->right = new Node(5);

	sumTree(root);
	preOrder(root);
	cout << endl;

	return 0;
}