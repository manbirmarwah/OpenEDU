#include<iostream>
#include<map>
#include<vector>
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


void getLevel(Node* root, int hd, map<int, vector<int> > &mp)
{
	if (root == nullptr)
		return ;
	mp[hd].push_back(root->data);
	getLevel(root->left, hd + 1, mp);
	getLevel(root->right, hd, mp);
}

void printLevel(Node* root)
{
	map<int, vector<int> > mp;
	map<int, vector<int> >::iterator itr;

	int hd = 0;
	getLevel(root, hd, mp);

	for (auto itr = mp.begin() ; itr != mp.end() ; itr++)
	{
		for (int i = 0 ; i < itr->second.size() ; i++)
		{
			cout << itr->second[i] << " ";
		}
		cout << endl;
	}

}

int main()
{
	Node* root = new Node(8);
	root->left = new Node(3);
	root->right = new Node(10);
	root->left->left = new Node(1);
	root->left->right = new Node(6);
	root->right->right = new Node(14);
	root->right->right->left = new Node(13);
	root->left->right->left = new Node(4);
	root->left->right->right = new Node(7);

	printLevel(root);

	return 0;
}