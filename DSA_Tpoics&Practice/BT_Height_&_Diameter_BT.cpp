#include<iostream>
#include<vector>
#include<stack>

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

int heightOfTree(node * root){
    if (root == NULL){
        return 0;
    }

    int left = heightOfTree(root->left);
    int right = heightOfTree(root->right);

    int h = max(left,right) + 1;

    return h;
}

int DiameterOfTree(node * root){
    if (root == NULL){
        return 0;
    }

    /// Here are three cases- 1. The diameter is in only left part
    int op1 = DiameterOfTree(root->left);
    //2. The diameter is in only in the left part.
    int op2 = DiameterOfTree(root->right);
    // 3. The Diameter is the combination of the left and right part.
    int op3 = heightOfTree(root->left) + 1 + heightOfTree(root->right);

    return max(op3,max(op1,op2));
}

pair<int, int> HandD(node * root){
    if (root == NULL){
        pair<int,int> p = make_pair(0,0);
        return p;
    }

    pair<int,int> leftpair = HandD(root->left);
    pair<int,int> rightpair = HandD(root->right);

    int op1 = leftpair.first;
    int op2 = rightpair.first;
    int op3 = leftpair.second + 1 + rightpair.second;

    pair<int,int> ans;
    ans.first = max(op3,max(op1,op2));
    ans.second = max(leftpair.second,rightpair.second) + 1;
    return ans;
}

int main(){
    node * root = NULL;

    root = BuildTree(root);

    cout<<heightOfTree(root)<<endl;

    // cout<<DiameterOfTree(root)<<endl;

    cout<<HandD(root).first<<endl;

    return 0; 
}