#include <iostream>
using namespace std;

// Data structure to store a Binary Tree node
struct Node
{
    int data;
    Node *left, *right;

    Node(int data)
    {
        this->data = data;
        this->left = this->right = nullptr;
    }
};

// Function to perform preorder traversal of the binary tree
void preorder(Node* root)
{
    if (root == nullptr)
        return;

    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}


void convertToMirror(Node* root)
{
    if (root == nullptr)
        return ;
    convertToMirror(root->left);
    convertToMirror(root->right);

    swap(root->left, root->right);
}


int main()
{
    Node* root = nullptr;
    /* Construct below tree
          1
        /   \
       /     \
      2       3
     / \     / \
    4   5   6   7   */

    root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    convertToMirror(root);
    preorder(root);

    return 0;
}