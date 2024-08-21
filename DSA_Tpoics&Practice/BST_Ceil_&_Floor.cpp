#include<iostream>
#include<queue>

using namespace std;

class node {
    public:
     int data ;
     node * left;
     node * right;

     node (int value){
        this->data = value;
        this->left = NULL;
        this->right = NULL;
     }
};

node * BuildBST(node * root,int d){
    // base case 
    if (root == NULL){
        root = new node(d);
        return root;
    }

    if (d > root->data){
        root->right = BuildBST(root->right,d);
    }
    else root->left = BuildBST(root->left, d);

    return root;
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

void ceilInBST(node * &root, int target){

    node * temp = root;
    int ans;

    while (temp != NULL){
        if (temp->data >= target){
            ans = temp->data;
            temp = temp->left;
        }
        else {
            temp = temp->right;
        }
    }

    cout<<ans<<endl;

}


void floorInBST(node * &root, int target){

    node * temp = root;
    int ans;

    while (temp != NULL){
        if (temp->data <= target){
            ans = temp->data;
            temp = temp->right;
        }
        else {
            temp = temp->left;
        }
    }

    cout<<ans<<endl;

}


int main() {
    node * root = NULL;

    int d;
    cin>>d;

    while (d != -1){
        root = BuildBST(root,d);
        cin>>d;
    }

    // levelOrderTree(root);

    int n;
    cin>>n;

    ceilInBST(root,n);

    floorInBST(root,n);

    return 0;
}