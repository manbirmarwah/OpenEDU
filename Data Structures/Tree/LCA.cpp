#include<bits/stdc++.h>
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

bool findPath(Node* root, vector<int> &path, int k)
{
	if (root == NULL)
		return false;

	path.push_back(root->data);

	if (root->data == k)
		return true;

	if ((root->left && findPath(root->left, path, k))  ||  ((root->right) && findPath(root->right, path, k)))
		return true;

	path.pop_back();
	return false;

}


int LCA(Node* root, int n1, int n2)
{

	vector<int> path1;
	vector<int> path2;
	if (!findPath(root, path1, n1) || !findPath(root, path2, n2))
		return -1;

	int i;
	for (i = 0 ; i < path1.size() && i < path2.size() ; i++)
	{
		if (path1[i] != path2[i])
			break;
	}
	return path1[i - 1];
}

int main()
{
	Node * root = new Node(1);
	root->left = new Node(2);
	root->right = new Node(3);
	root->left->left = new Node(4);
	root->left->right = new Node(5);
	root->right->left = new Node(6);
	root->right->right = new Node(7);

	cout << LCA(root, 4, 5) << endl;

	return 0;
}

