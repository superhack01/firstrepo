#include<iostream>
#include<queue>
#include<vector>

#define ll long long 

using namespace std;

class node {
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

void BuildTree(node * &root, int d){
    if (root == NULL){
        root = new node(d);
        return ;
    }

    if (d < root->data) BuildTree(root->left,d);
    else BuildTree(root->right,d);

}

void InOrder(node * root, vector<int> &ans){
    if (root == NULL){
        return ;
    }

    InOrder(root->left,ans);
    ans.push_back(root->data);
    InOrder(root->right,ans);
}

void solution(node * &root, int &i, vector<int> &ans){
    if (root == NULL){
        return ;
    }

    root->data = ans[i++];
    solution(root->left,i,ans);
    solution(root->right,i,ans);

}


void levelOrderTree(node * &root){
    if (root == NULL){
        return ;
    }

    queue<node* > q;
    q.push(root);
    q.push(NULL);
    while (!q.empty()){
        node * temp = q.front();
        q.pop();

        if (temp == NULL){
            cout<<endl;
            if (!q.empty()) q.push(NULL);
        }
        else {
            cout<<temp->data<<" ";
            if (temp->left) q.push(temp->left);
            if (temp->right) q.push(temp->right);
        }

    }
}

int main() {
    node * root = NULL;

    int d;
    cin>>d;
    
    while (d != -1){
        BuildTree(root, d);
        cin>>d;
    }

    levelOrderTree(root);

    vector<int> inorder;
    InOrder(root,inorder);

    cout<<"The inorder of the BST : "<<endl;
    for (auto i : inorder){
        cout<<i<<" ";
    }cout<<endl;

    int i = 0;
    solution(root,i,inorder);

    levelOrderTree(root);
    
    vector<int> result;
    InOrder(root,result);
    cout<<"The Inorder of the heap : "<<endl;
    for (auto i : result){
        cout<<i<<" ";
    }cout<<endl;

    return 0;
}