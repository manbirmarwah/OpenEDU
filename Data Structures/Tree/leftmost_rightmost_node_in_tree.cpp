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


	while (!q.empty())
	{
		int n = q.size();
		for (int i = 0 ; i < n ; i++)
		{
			temp = q.front();
			q.pop();

			if (i == 0 || i == n - 1)
				cout << temp->data << " ";

			if (temp->left)
				q.push(temp->left);
			if (temp->right)
				q.push(temp->right);
		}

	}
	cout << endl;
}

int main()
{
	Node *root =  new Node(15);
	root->left = new Node(10);
	root->right = new Node(20);
	root->left->left = new Node(8);
	root->left->right = new Node(12);
	root->right->left = new Node(16);
	root->right->right = new Node(25);

	LOT(root);

	return 0;
}