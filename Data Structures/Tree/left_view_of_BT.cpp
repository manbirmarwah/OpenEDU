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
			if (temp->right)
				q.push(temp->left);
			if (temp->left)
				q.push(temp->right);

			/*
			If we want to print the right view,
			then we enqueue first temp->right, then temp->left
			***IMPORTANT***
			*/
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




// #include <iostream>
// #include <list>
// using namespace std;

// // Data structure to store a Binary Tree node
// struct Node
// {
// 	int key;
// 	Node *left, *right;

// 	Node(int key)
// 	{
// 		this->key = key;
// 		this->left = this->right = nullptr;
// 	}
// };

// // Iterative function to print left view of given binary tree
// void leftView(Node* root)
// {
// 	// return if tree is empty
// 	if (root == nullptr)
// 		return;

// 	// create an empty queue and enqueue root node
// 	list<Node*> queue;
// 	queue.push_back(root);

// 	// pointer to store current node
// 	Node* curr = nullptr;

// 	// run till queue is not empty
// 	while (!queue.empty())
// 	{
// 		// calculate number of nodes in current level
// 		int size = queue.size();
// 		int i = 0;

// 		// process every node of current level and enqueue their
// 		// non-empty left and right child to queue
// 		while (i++ < size)
// 		{
// 			curr = queue.front();
// 			queue.pop_front();

// 			// if this is first node of current level, print it
// 			if (i == 1)
// 				cout << curr->key << " ";

// 			if (curr->left)
// 				queue.push_back(curr->left);

// 			if (curr->right)
// 				queue.push_back(curr->right);
// 		}
// 	}
// }

// int main()
// {
// 	Node* root = nullptr;

// 	root = new Node(1);
// 	root->left = new Node(2);
// 	root->right = new Node(3);
// 	root->left->right = new Node(5);
// 	root->left->left = new Node(4);
// 	//root->right->left = new Node(5);
// 	//root->right->right = new Node(6);
// 	//root->right->left->left = new Node(7);
// 	//root->right->left->right = new Node(8);

// 	leftView(root);

// 	return 0;
// }