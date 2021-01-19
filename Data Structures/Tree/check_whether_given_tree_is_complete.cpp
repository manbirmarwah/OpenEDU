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


bool isComplete(Node* root)
{
	queue<Node*> q;
	q.push(root);

	bool flag = false;

	while (q.empty())
	{
		Node* temp = q.front();
		q.pop();

		if (temp->left)
		{
			if (flag == true)
				return false;
			else
				flag = true;
		}
		if (temp->right)
		{
			if (flag == true)
				return false;
			else
				flag = true;
		}

	}
	return true;
}

int main()
{
	Node* root = new Node(1);

	root->left = new Node(2);
	root->left->left = new Node(4);
	root->right = new Node(3);
	root->left->right = new Node(5);


	if (isComplete(root) == true)
		cout << "YES\n";
	else
		cout << "NO\n";

	return 0;
}