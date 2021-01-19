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

void topView(Node* root)
{
	if (root == nullptr)
		return ;
	int hd = 0;
	map<int, int> mp;
	queue<Node*> q;
	q.push(root);
	root->hd = hd;

	while (!q.empty())
	{
		hd = root->hd;

		if (mp.count(hd) == 0)
			mp[hd] = root->data;

		if (root->left)
		{
			root->left->hd = hd - 1;
			q.push(root->left);
		}
		if (root->right)
		{
			root->right->hd = hd + 1;
			q.push(root->right);
		}

		q.pop();
		root = q.front();
	}
	for (auto i = mp.begin() ; i != mp.end() ; i++)
		cout << i->second << " ";

	cout << endl;
}

int main()
{
	Node* root = new Node(1);

	root->left = new Node(2);
	root->left->left = new Node(4);
	root->right = new Node(3);
	root->left->right = new Node(5);

	topView(root);

	return 0;
}