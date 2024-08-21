#include<iostream>
#include<cmath>
#include<climits>

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

node * BuildTree(node * root){
	int d;
	cin>>d;

	if (d == -1) return root;

	root = new node(d);

	root->left = BuildTree(root->left);
	root->right = BuildTree(root->right);

	return root;
}

int solution (node * root, int len, int &maxlen, int sum ,int & maxsum){
	if (root == NULL){
		if (len > maxlen){
			maxlen = len;
			maxsum = sum;
		}
		else if (len == maxlen){
			maxsum = max(maxsum, sum);
		}

		return maxsum;
	}

	sum += root->data;
	len++;

	int leftsum = solution(root->left,len,maxlen,sum, maxsum);
	int rightsum = solution(root->right,len,maxlen,sum, maxsum);

	return maxsum;
}

node * solve(node * root,int n1, int n2){
	if (root == NULL){
		return NULL;
	}

	if (root->data == n1 | root->data == n2){
		return root;
	}

	node * leftans = solve(root->left,n1,n2);
	node * rightans = solve(root->right,n1,n2);

	if (leftans == NULL && rightans == NULL){
		return NULL;
	}
	else if (leftans == NULL && rightans != NULL){
		return rightans;
	}
	else if (leftans != NULL && rightans == NULL) {
		return leftans;
	}
	else {
		return root;
	}
}

int main (){
	node * root = NULL;

	root = BuildTree(root);
	
	// int maxsum = INT_MIN;
	// int maxlen = 0;
	// int ans = solution(root,0,maxlen,0,maxsum);

	// cout<<ans<<endl;

	int n1,n2;
	cin>>n1>>n2;
	
	node * ans = solve(root,n1,n2);

	cout<<ans->data<<endl;
	return 0;
}
