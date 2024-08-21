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

node * InOrderBST(vector<int> &answer,int s, int e){
	if (s > e) return NULL;

	int mid = s + (e-s)/2;
	node * roott = new node(answer[mid]);
	roott->left = InOrderBST(answer,s,mid-1); 
	roott->right = InOrderBST(answer,mid+1,e); 

	return roott;
}

int main (){
	node * root = NULL;

	int d;
	cin>>d;

	while (d != -1){
		root = BuildTree(root,d);
		cin>>d;
	}

	vector<int> answer;
	InOrder(root, answer);

	for (auto i : answer) {
		cout<<i<<" ";
	}cout<<endl;

	node * newroot = NULL;

	newroot = InOrderBST(answer,0,answer.size()-1);

	vector<int> newanswer;
	InOrder(newroot,newanswer);

	for (auto i : newanswer) {
		cout<<i<<" ";
	}cout<<endl;



	return 0;
}
