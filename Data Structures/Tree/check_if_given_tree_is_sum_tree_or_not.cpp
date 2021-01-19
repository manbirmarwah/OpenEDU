#include <iostream>
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

// Recursive function to check if given binary tree is a sum tree or not
int isSumTree(Node *root)
{
    // base case: empty tree
    if (root == nullptr)
        return 0;

    // special case: leaf node
    if (root->left == nullptr && root->right == nullptr)
        return root->key;

    // if root's value is equal to sum of all elements present in its
    // left and right subtree
    if (root->key == isSumTree(root->left) + isSumTree(root->right))
        return 2 * root->key;

    return INT_MIN;
}

int main()
{
    Node* root = nullptr;
    /* Construct below tree
             44
            /  \
           /    \
          9     13
         / \    / \
        4   5  6   7
    */

    root = new Node(44);
    root->left = new Node(9);
    root->right = new Node(13);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    if (isSumTree(root) != INT_MIN)
        cout << "Yes";
    else
        cout << "No";

    return 0;
}