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


bool isIdentical(Node* x, Node* y)
{
	if (x == nullptr && y == nullptr)
		return true;
	if (x == nullptr)
		return false;
	if (y == nullptr)
		return false;

	return (x && y) && (x->data == y->data) && isIdentical(x->left, y->left) && isIdentical(x->right, y->right);
}

int main()
{
	Node* root1 = new Node(1);

	root1->left = new Node(2);
	root1->left->left = new Node(4);
	root1->right = new Node(3);
	root1->left->right = new Node(5);

	Node* root2 = new Node(1);

	root2->left = new Node(2);
	root2->left->left = new Node(4);
	root2->right = new Node(3);
	root2->left->right = new Node(5);

	if (isIdentical(root1, root2))
		cout << "YES\n";
	else
		cout << "NO\n";

	return 0;
}