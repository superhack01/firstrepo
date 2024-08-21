#include<iostream>
#include<queue>

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


//Function to create a tree by recursion
node * buildTree(node * root){
    cout<<"Enter the data : ";
    int d;
    cin>>d;

    root = new node(d);

    if (d == -1){
        return NULL;
    }

    cout<<"Enter the left node of : "<<root->data<<" ";
    root->left = buildTree(root->left);

    cout<<"Enter the right node of: "<<root->data<<" ";
    root->right = buildTree(root->right);


    return root;
}

int main(){
    node * root = NULL;

    //Creating a tree
    root = buildTree(root);

    return 0;
}