#include<iostream>
#include<queue>

using namespace std;

class node{
    public : 
    int data;
    node * left;
    node * right;

    node(int value){
        this->data = value;
        this->left = NULL;
        this->right = NULL;
    }
};

node * buildTree(node * root){
    int d;
    // cout<<"Enter the data : ";
    cin>>d;

    root = new node(d);

    if (d == -1){
        return NULL;
    }

    root->left = buildTree(root->left);
    root->right = buildTree(root->right);

    return root;
}


void levelOrderTraversal(node * root){

    queue<node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        node * temp = q.front();
        q.pop();
        if (temp == NULL){
            cout<<endl;
            if (!q.empty()){
                q.push(NULL);
            }
        }
        else {
            cout<<temp->data<<" ";
            if (temp->left){
                q.push(temp->left);
            }
            if (temp->right){
                q.push(temp->right);
            }
        }
    }

    return  ;
}

void inorderTraversal(node * root){
    if (root == NULL) return ;

    inorderTraversal(root->left);
    cout<<root->data<<" ";
    inorderTraversal(root->right);


}

void preorderTraversal(node * root){
    if (root == NULL) return ;

    cout<<root->data<<" ";
    preorderTraversal(root->left);
    preorderTraversal(root->right);

}

void postOrderTraversal(node * root){
    if (root == NULL) return ;

    postOrderTraversal(root->left);
    postOrderTraversal(root->right);
    cout<<root->data<<" ";

}
int main(){
    node * root = NULL;

    root = buildTree(root);

    cout<<"The output for the LevelOrder Trversal : "<<endl;
    levelOrderTraversal(root);

    cout<<endl<<"The output for the Inorder Trversal : "<<endl;
    inorderTraversal(root);

    cout<<endl<<"The output for the PreOrder Trversal : "<<endl;
    preorderTraversal(root);

    cout<<endl<<"The output for the PostOrder Trversal : "<<endl;
    postOrderTraversal(root);

    return 0;
}