#include<iostream>
#include<cmath>
#include<climits>
#include<vector>

using namespace std;

class node{
	public :
		int data;
		node * left;
		node * right;

		node (int value){
			this->data = value;
			this->left = NULL;
			this->right = NULL;
		}
};

class info{
	public :
	 int max;
	 int min;
	 bool isBST;
	 int size;
};

node * BuildTree(node * root,int d){
	if (root == NULL){
		root = new node(d);
		return root;
	}

	if (d > root->data){
		root->right = BuildTree(root->right,d);
	}
	else root->left = BuildTree(root->left,d);

	return root;
}

void InOrder(node * root, vector<int> &ans){
	if (root == NULL){
		return ;
	}

	InOrder(root->left,ans);
	ans.push_back(root->data);
	InOrder(root->right,ans);
}

info solve(node * root, int &ans){
	//base case
	if (root == NULL){
		return {INT_MIN,INT_MAX,true,0};
	}

	info left = solve(root->left,ans);
	info right = solve(root->right,ans);

	info current;
	current.size = left.size + right.size + 1;
	current.max = max(root->data, right.max);
	current.min = min(root->data, left.min);

	if (left.isBST && right.isBST && (root->data > left.max && root->data < right.min)){
		current.isBST = true;
	}
	else current.isBST = false;

	//update the answer 
	if (current.isBST){
		ans = max(ans,current.size);
	}

	return current;
}

int largestBST(node* &root){
	int maxsize = 0;
	info temp = solve(root,maxsize);

	return maxsize;
}
int main (){
	node * root = NULL;

	int d;
	cin>>d;

	while (d != -1){
		root = BuildTree(root,d);
		cin>>d;
	}

	////largest BST Time Complexity is O(n);
	return 0;
}
