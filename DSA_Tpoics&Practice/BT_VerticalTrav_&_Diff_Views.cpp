#include<iostream>
#include<vector>
#include<queue>
#include<map>

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

void VarticalOrder(node * &root){
    map<int,map<int,vector<int>>> mp;
    queue<pair<node*,pair<int,int>>> q;

    vector<int> ans;
    if (root == NULL) {
        return ;
    }

    q.push(make_pair(root,make_pair(0,0)));
    
    while(!q.empty()){
        pair<node*,pair<int,int>> temp = q.front();
        q.pop();

        node * nd = temp.first;
        int hd = temp.second.first;
        int lvl = temp.second.second;

        mp[hd][lvl].push_back(nd->data);

        if (nd->left){
            q.push(make_pair(nd->left,make_pair(hd-1,lvl+1)));
        }
        if (nd->right){
            q.push(make_pair(nd->right,make_pair(hd+1,lvl+1)));
        }
    }

    for (auto i : mp){
        for (auto j : i.second){
            for (auto k : j.second){
                ans.push_back(k);
            }
        }
    }

    for (auto i : ans){
        cout<<i<<" ";
    }cout<<endl;

}

void topView(node * &root){
    map<int,int> mp;
    queue<pair<node*, int>> q;
    vector<int> ans;

    if (root == NULL){
        return ;
    }

    q.push(make_pair(root,0));

    while (!q.empty()){
        pair<node*, int> temp = q.front();
        q.pop();

        node * frnd = temp.first;
        int hd = temp.second;

        if (mp.find(hd) == mp.end()){
            mp[hd] = frnd->data;
        }

        if (frnd->left){
            q.push(make_pair(frnd->left,hd-1));
        }
        if (frnd->right){
            q.push(make_pair(frnd->right,hd+1));
        }

    }

    for (auto i : mp){
        ans.push_back(i.second);
    }

    for (auto i : ans){
        cout<<i<<" ";
    }cout<<endl;

}

void BottomView(node * root){
    map<int,int> mp;
    queue<pair<node*,int>> q;
    vector<int> ans;

    if (root == NULL) return ;

    q.push(make_pair(root,0));

    while (!q.empty()){
        pair<node* , int> temp = q.front();
        q.pop();

        node * frontnode = temp.first;
        int hd = temp.second;

        mp[hd] = frontnode->data;

        if (frontnode->left){
            q.push(make_pair(frontnode->left,hd-1));
        }
        if (frontnode->right){
            q.push(make_pair(frontnode->right,hd+1));
        }

    }

    for (auto i : mp){
        ans.push_back(i.second);
    }

    for (auto i : ans){
        cout<<i<<" ";
    }cout<<endl;

}

void leftView(node * root){
    map<int,int> mp;
    queue<pair<node*,int>> q;
    vector<int> ans;

    if(root == NULL){
        return;
    }

    node * nn = NULL;
    q.push(make_pair(root,0));

    while (!q.empty()){
        pair<node*,int> temp = q.front();
        q.pop();

        node * frontnode = temp.first;
        int lvl = temp.second;

        if (mp.find(lvl) == mp.end()){
            mp[lvl] = frontnode->data;
        }

        if (frontnode->left){
            q.push(make_pair(frontnode->left,lvl+1));
        }
        if (frontnode->right){
            q.push(make_pair(frontnode->right,lvl+1));
        }
    }

    for (auto i : mp){
        ans.push_back(i.second);
    }

    for (auto i : ans){
        cout<<i<<" ";
    }cout<<endl;
}

void RightView(node * root){
    map<int,int> mp;
    queue<pair<node*,int>> q;
    vector<int> ans;

    if(root == NULL){
        return;
    }

    node * nn = NULL;
    q.push(make_pair(root,0));

    while (!q.empty()){
        pair<node*,int> temp = q.front();
        q.pop();

        node * frontnode = temp.first;
        int lvl = temp.second;

        mp[lvl] = frontnode->data;

        if (frontnode->left){
            q.push(make_pair(frontnode->left,lvl+1));
        }
        if (frontnode->right){
            q.push(make_pair(frontnode->right,lvl+1));
        }
    }

    for (auto i : mp){
        ans.push_back(i.second);
    }

    for (auto i : ans){
        cout<<i<<" ";
    }cout<<endl;
}

int main () {
    node * root = NULL;

    root = BuildTree(root);

    // levelOrder(root);
    // cout<<endl;

    // VarticalOrder(root);
    // cout<<endl;

    // topView(root);

    // BottomView(root);

    // leftView(root);

    RightView(root);

    return 0;
}
