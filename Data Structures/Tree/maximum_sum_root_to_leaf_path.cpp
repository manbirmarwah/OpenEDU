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

bool printPath(Node* root, int sum)
{
	if (sum == 0)
		return true;
	if (root == nullptr)
		return false;

	bool left = printPath(root->left, sum - root->data);
	bool right = printPath(root->right, sum - root->data);

	if (left || right)
		cout << root->data << " ";
	return left || right;

}

int getSum(Node* root)
{
	if (root == nullptr)
		return 0;
	int left = getSum(root->left);
	int right = getSum(root->right);

	return (left > right ? left : right) + root->data;
}

void final(Node* root)
{
	int ans = getSum(root);
	cout << "The maximum sum is : " << ans << endl;
	cout << "The maximum sum path is : ";
	printPath(root, ans);
}

int main()
{
	Node* root = new Node(1);
	root->left = new Node(2);
	root->right = new Node(3);
	root->left->left = new Node(8);
	root->left->right = new Node(4);
	root->right->left = new Node(5);
	root->right->right = new Node(6);
	root->left->right->left = new Node(10);
	root->right->left->left = new Node(7);
	root->right->left->right = new Node(9);
	root->right->right->right = new Node(5);

	final(root);

	return 0;
}