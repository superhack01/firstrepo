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

vector<vector<int>>  AllTraverse(node * root){
    stack<pair<node*,int>> st;
    vector<int> pre,post,In;

    if (root == NULL) return {};

    st.push(make_pair(root,1));

    while (!st.empty()){
        auto it = st.top();
        st.pop();
        if (it.second == 1){
            pre.push_back(it.first->data);
            it.second++;
            st.push(it);

            if (it.first->left != NULL){
                st.push(make_pair(it.first->left,1));
            }
        }
        else if (it.second == 2){
            In.push_back(it.first->data);
            it.second++;
            st.push(it);

            if (it.first->right != NULL){
                st.push(make_pair(it.first->right,1));
            }
        }
        else {
            post.push_back(it.first->data);
        }
    }

    vector<vector<int>> ans;
    ans.push_back(pre);
    ans.push_back(post);
    ans.push_back(In);

    return ans;
}

int main(){
    node * root = NULL;

    root = BuildTree(root);

    vector<vector<int>> solution = AllTraverse(root);

    cout<<"{";
    for (auto i : solution){
        cout<<"[";
        for (auto j : i){
            cout<<j<<" ";
        }cout<<"] ";
    }cout<<"}";

    return 0; 
}