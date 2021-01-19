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
	getLevel(root->left, hd - 1, mp);
	getLevel(root->right, hd + 1, mp);
}

void printLevel(Node* root)
{
	int ans = 0;
	map<int, vector<int> > mp;
	map<int, vector<int> >::iterator itr;

	int hd = 0;
	getLevel(root, hd, mp);

	for (auto itr = mp.begin() ; itr != mp.end() ; itr++)
	{
		ans = 0;
		for (int i = 0 ; i < itr->second.size() ; i++)
		{
			ans += itr->second[i];
		}
		cout << itr->first << " : " << ans << endl;
	}
	cout << endl;
}

int main()
{
	Node *root = new Node(1);
	root->left = new Node(2);
	root->right = new Node(3);
	root->left->left = new Node(4);
	root->left->right = new Node(5);
	root->right->left = new Node(6);
	root->right->right = new Node(7);
	root->right->left->right = new Node(8);
	root->right->right->right = new Node(9);

	printLevel(root);

	return 0;
}