#include <iostream>
#include <unordered_map>
using namespace std;

// Data structure to store a Binary Tree node
struct Node
{
	int key;
	Node *left, *right;

	Node(int key)
	{
		this->key = key;
		this->left = this->right = nullptr;
	}
};

// Traverse the tree in pre-order fashion and store count of nodes
// in each level
void preorder(Node *root, int level, auto &map)
{
	// base case: empty tree
	if (root == nullptr)
		return;

	// increment count of nodes in current level
	map[level]++;

	// recur for left and right subtree by increasing level by 1
	preorder(root->left, level + 1, map);
	preorder(root->right, level + 1, map);
}

// Recursive function to find maximum width of the tree
void maxWidth(Node *root)
{
	// create an empty map to store count of nodes in each levels
	unordered_map<int, int> map;

	// traverse the tree and fill map
	preorder(root, 1, map);

	// stores maximum width
	int res = 0;

	// iterate through the map and update maximum width
	for (auto it : map)
		res = max(res, it.second);

	cout << "Maximum width is " << res;
}

int main()
{
	Node* root = nullptr;

	root = new Node(15);
	root->left = new Node(10);
	root->right = new Node(20);
	root->left->left = new Node(8);
	root->left->right = new Node(12);
	root->right->left = new Node(16);
	root->right->right = new Node(25);

	maxWidth(root);

	return 0;
}