#include<iostream>
#include<queue>
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

void LOT(Node* root)
{
	queue<Node*> q;
	q.push(root);

	Node* temp = nullptr;


	while (q.size())
	{

		temp = q.front();
		q.pop();

		cout << temp->data << " ";

		if (temp->left)
			q.push(temp->left);
		if (temp->right)
			q.push(temp->right);
	}
	cout << endl;
}

int main()
{
	Node* root = new Node(1);

	root->left = new Node(2);
	root->left->left = new Node(4);
	root->right = new Node(3);
	root->left->right = new Node(5);

	LOT(root);

	return 0;
}