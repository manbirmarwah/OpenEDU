#include<bits/stdc++.h>
using namespace std;
string s;
string s2;

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

void inorder(Node* root)
{

	s.push_back(root->data);
	inorder(root->left);
	inorder(root->right);
}

void Inorder(Node* root)
{

	s2.push_back(root->data);
	inorder(root->left);
	inorder(root->right);
}

int main()
{
	Node* root = new Node(1);
	root->left = new Node(2);
	root->right = new Node(3);
	root->left->left = new Node(4);
	root->left->right = new Node(5);
	root->right->left = new Node(6);
	root->right->right = new Node(7);

	Node* temp = new Node(3);
	temp->left = new Node(6);
	temp->right = new Node(7);

	inorder(temp);
	Inorder(root);
	int l1 = s.length();

	int l2 = s2.length();
	bool flag = false;
	for (int i = 0 ; i < s2.length() ; i++)
	{
		if ((i + l1) < s2.length())
		{
			if (s == s2.substr(i, i + l1))
			{
				flag = true;
				break;
			}
		}


	}
	if (flag == true)
		cout << "YES\n";
	else
		cout << "NO\n";


	return 0;
}