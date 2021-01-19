#include<iostream>
#include<list>
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

void leftView(Node* root)
{

	if (root == nullptr)
		return;

	queue<Node*> q;
	q.push(root);
	// cout << root->data << " ";
	Node* temp = nullptr;

	while (!q.empty())
	{
		int size = q.size();
		int i = 0;

		while (i++ < size)
		{
			temp = q.front();
			q.pop();

			if ( i == 1)
				cout << temp->data << " ";

			if (temp->left)
				q.push(temp->right);


			if (temp->right)
				q.push(temp->left);

		}
	}
}

int main()
{
	Node* root = new Node(1);

	root->left = new Node(2);
	root->left->left = new Node(4);
	root->right = new Node(3);
	root->left->right = new Node(5);

	leftView(root);

	return 0;
}
