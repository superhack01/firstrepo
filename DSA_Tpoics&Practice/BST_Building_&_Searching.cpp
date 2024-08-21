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

bool binarySearchTree(node * root, int target){
    if (root == NULL){
        return false;
    }

    if (root->data == target){
        return true;
    }

    if (root->data > target){
        return binarySearchTree(root->left,target);
    }
    else return binarySearchTree(root->right,target);
}

/* To find the minimum and the maximum of BST -->

int minimumInBST(node * &root){
    if (root->left == NULL && root->right == NULL){
        return root->data;
    }

    return minimumInBST(root->left);
}

int maxmumInBST(node * &root){
    if (root->left == NULL && root->right == NULL){
        return root->data;
    }

    return maxmumInBST(root->right);
}

*/

/*
///// To find the Kth Largest and smallest element in BST


void KthSmallest(node * &root,int &i,int k){
    if (root == NULL) return ;

    KthSmallest(root->left,i,k);
    i++;
    if (i == k){
        cout<<root->data<<endl;
        return ;
    }
    KthSmallest(root->right,i,k);

}

///And for largest the k value is the (n-k);

*/


int main() {
    node * root = NULL;

    int d;
    cin>>d;

    while (d != -1){
        root = BuildBST(root,d);
        cin>>d;
    }

    levelOrderTree(root);

    int n;
    cin>>n;

    if (binarySearchTree(root,n)) cout<<"YES!"<<endl;
    else cout<<"NO."<<endl;

    return 0;
}