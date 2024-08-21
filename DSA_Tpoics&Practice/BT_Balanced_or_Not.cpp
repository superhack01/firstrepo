#include<iostream>
#include<vector>
#include<queue>

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

/*
int height(node * root){
    if (root == NULL){
        return 0;
    }

    int lefth = height(root->left);
    int righth = height(root->right);

    return max(lefth,righth) + 1;
}

bool isBalanced(node * root){
    if (root == NULL) return true;

    int lefth = height(root->left);
    int righth = height(root->right);

    if (abs(lefth - righth) <= 1){
        return (isBalanced(root->left) && isBalanced(root->right));
    }
    else return false;

}

*/


pair<int,bool> Optimal(node * root){
    pair<int,bool> p;

    if (root == NULL){
        p = make_pair(0,true);
        return p;
    }

    pair<int, bool> leftpair = Optimal(root->left);
    pair<int, bool> rightpair = Optimal(root->right);

    pair<int, bool> ans;

    if (leftpair.second && rightpair.second && (abs(leftpair.first - rightpair.first) <= 1)){
        ans.second = true;
        ans.first = max(leftpair.first,rightpair.first) + 1;        
    }
    else {
        ans.second = false;
        ans.first = max(leftpair.first,rightpair.first) + 1;
    }

    return ans;

}

int main () {
    node * root = NULL;

    root = BuildTree(root);

    levelOrder(root);

    // cout<<height(root)<<endl;

    // cout<<isBalanced(root)<<endl;

    pair<int,bool> result = Optimal(root);

    cout<<result.first<<" "<<result.second<<endl;


    return 0;
}
