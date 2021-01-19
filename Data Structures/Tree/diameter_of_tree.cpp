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


int height(Node* root, int &ans)
{
	if (root == nullptr)
		return 0;

	int left = height(root->left, ans);
	int right = height(root->right, ans);

	ans = max(ans, 1 + left + right);

	return 1 + max(left, right);
}

int diameter(Node* root)
{
	int ans = INT_MIN;

	if (root == nullptr)
		return 0;

	int height_tree = height(root, ans);
	return ans;
}

int main()
{
	Node* root = new Node(1);

	root->left = new Node(2);
	root->left->left = new Node(4);
	root->right = new Node(3);
	root->left->right = new Node(5);

	cout << diameter(root) << endl;

	return 0;
}