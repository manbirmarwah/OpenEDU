#include<bits/stdc++.h>
using namespace std;


class Node
{
public :
	int data;
	int hd;
	Node* left;
	Node* right;

	Node(int data)
	{
		this->data = data;
		hd = INT_MAX;
		left = right = NULL;
	}
};

void bottomView(Node* root)
{
	if (root == nullptr)
		return ;
	int hd = 0;
	map<int, int> mp;
	queue<Node*> q;
	root->hd = hd;
	q.push(root);

	while (!q.empty())
	{
		Node* temp = q.front();
		q.pop();

		hd = temp->hd;
		mp[hd] = temp->data;


		if (temp->left)
		{
			temp->left->hd = hd - 1;
			q.push(temp->left);
		}

		if (temp->right)
		{
			temp->right->hd = hd + 1;
			q.push(temp->right);
		}


	}
	for (auto i = mp.begin() ; i != mp.end() ; i++)
	{
		cout << i->second << " ";
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

	bottomView(root);

	return 0;
}