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

bool isIdentical(node * root1, node * root2){
    if (root1 == NULL && root2 == NULL){
        return true;
    }
    if (root1 ==NULL && root2 != NULL) return false ;
    if (root1 != NULL && root2 == NULL) return false;

    bool leftpart = isIdentical(root1->left, root2->left);
    bool rightpart = isIdentical(root1->right, root2->right);

    bool condition = root1->data == root2->data;

    if (leftpart && rightpart && condition){
        return true;
    }
    else return false;

}

int main(){

    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);

    node * root1 = NULL;
    node * root2 = NULL;

    // cout<<"Enter the first tree : ";
    root1 = BuildTree(root1);
    // cout<<endl<<"Enter the Second tree : ";
    root2 = BuildTree(root2);

    if (isIdentical(root1,root2)){
        cout<<"YES"<<endl;
    }
    else cout<<"NO"<<endl;

    return 0; 
}