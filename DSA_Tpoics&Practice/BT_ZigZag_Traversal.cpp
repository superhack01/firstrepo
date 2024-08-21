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

void ZigZag(node * &root, vector<vector<int>> &ans){
    vector<int> result;
    if (root == NULL){
        return ;
    }

    queue<node * > q;
    q.push(root);
    q.push(NULL);

    bool flag = true;

    while (!q.empty()){
         node * temp = q.front();
         q.pop();

         if (temp == NULL){
            if (flag){
                ans.push_back(result);
            }
            else {
                reverse(result.begin(),result.end());
                ans.push_back(result);
            }

            if (!q.empty()){
                q.push(NULL);
            }

            flag = !flag;
            result.clear();
         }
         else {
            result.push_back(temp->data);
            if (temp->left){
                q.push(temp->left);
            }
            if (temp->right){
                q.push(temp->right);
            }
         }
    }
}

int main () {
    node * root = NULL;

    root = BuildTree(root);

    levelOrder(root);
    cout<<endl;

    vector<vector<int>> ans;

    ZigZag(root,ans);

    for (auto i : ans){
        for (auto j : i){
            cout<<j<<" ";
        }cout<<endl;
    }

    return 0;
}
