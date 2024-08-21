#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

#define ll long long 

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

node * BuildTree(node * root){
    int d;
    cin>>d;

    root = new node(d);

    if (d == -1) return NULL;

    root->left = BuildTree(root->left);
    root->right = BuildTree(root->right);

    return root;
}

void levelOrder(node * &root){
    // if (root == NULL){
    //     return ;
    // }

    queue<node *> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty()){
        node * temp = q.front();
        q.pop();

        if (temp == NULL){
            cout<<endl;
            if (!q.empty()) {
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

    return ;
}

void lefttraversal(node * root, vector<int> &ans){
    if (root->left == NULL && root->right == NULL){
        return ;
    }

    ans.push_back(root->data);
    if (root->left){
        lefttraversal(root->left,ans);
    }
    else lefttraversal(root->right,ans);

    return;
}

void bottomtraversal(node * root, vector<int> &ans){
    if (root == NULL){
        return ;
    }

    if (root->left == NULL && root->right == NULL){
        ans.push_back(root->data);
        return ;
    }

    bottomtraversal(root->left,ans);
    bottomtraversal(root->right,ans);

}

void righttraversal(node * root, vector<int> &ans){
    if (root->left == NULL && root->right == NULL){
        return ;
    }

    if (root->right){
        righttraversal(root->right,ans);
    }
    else righttraversal(root->left,ans);

    ans.push_back(root->data);

}

void BoundaryTraversal(node * root,vector<int> &ans){

    lefttraversal(root,ans);
    bottomtraversal(root,ans);
    righttraversal(root,ans);

}

int main () {
    node * root = NULL;

    root = BuildTree(root);

    // levelOrder(root);
    // cout<<endl;

    vector<int> ans;

    BoundaryTraversal(root,ans);

    //// because the root node include in left and right traversal as well 
    ans.pop_back();

    for (auto i : ans){
        cout<<i<<" ";
    }cout<<endl;

    return 0;
}
