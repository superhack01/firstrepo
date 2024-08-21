#include<iostream>
#include<vector>
#include<stack>
#include<climits>

#define ll long long 

using namespace std;

class node {
    public:
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
    int n;
    cin>>n;

    root = new node(n);

    //Base case
    if (n == -1){
        return NULL;
    }

    root->left = BuildTree(root->left);
    root->right = BuildTree(root->right);
    
    return root;
}

int SumTotal(node * root,int &mx){
    if (root == NULL){
        return 0;
    }

    int currentSum;

    int leftSum = max(0,SumTotal(root->left,mx));
    int rightSum = max(0,SumTotal(root->right,mx));

    currentSum = leftSum + rightSum + root->data;

    // cout<<currentSum<<endl;

    mx = max(mx,currentSum);

    return max(leftSum,rightSum) + root->data;
}

int maxPathSum(node * root){
    int mx = INT_MIN;

    SumTotal(root,mx);

    return mx;
}

int MaxSumMine(node * root, int mx){
    if (root == NULL){
        return 0;
    }

    int leftSum = MaxSumMine(root->left,mx);
    int RightSum = MaxSumMine(root->right,mx);

    int maximum = max(leftSum,RightSum);

    mx = max(maximum,leftSum+RightSum+root->data);

    return mx;
}

int main(){

    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);

    node * root = NULL;

    root = BuildTree(root);

    int mx = INT_MIN;

    cout<<MaxSumMine(root,mx)<<endl;


    return 0; 
}