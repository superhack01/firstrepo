#include <iostream>
#include <vector>
#include <queue>
#include <map>

#define ll long long

using namespace std;

class node
{
public:
    int data;
    node *left;
    node *right;

    node(int value)
    {
        this->data = value;
        this->left = NULL;
        this->right = NULL;
    }
};

node *BuildTree(node *root)
{
    int d;
    cin >> d;

    root = new node(d);

    if (d == -1)
        return NULL;

    root->left = BuildTree(root->left);
    root->right = BuildTree(root->right);

    return root;
}

void levelOrder(node *&root)
{
    // if (root == NULL){
    //     return ;
    // }

    queue<node *> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        node *temp = q.front();
        q.pop();

        if (temp == NULL)
        {
            cout << endl;
            if (!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {
            cout << temp->data << " ";
            if (temp->left)
            {
                q.push(temp->left);
            }
            if (temp->right)
            {
                q.push(temp->right);
            }
        }
    }

    return;
}

void PathToNode(node *root, vector<int> &ans, int target)
{
    if (root == NULL)
    {
        return;
    }

    ans.push_back(root->data);

    if (root->data == target)
    {
        for (auto i : ans)
        {
            cout << i << " ";
        }
        cout << endl;
        return;
    }

    PathToNode(root->left, ans, target);

    PathToNode(root->right, ans, target);

    ans.pop_back();
}

int main()
{
    node *root = NULL;

    root = BuildTree(root);

    // levelOrder(root);
    // cout<<endl;

    vector<int> ans;
    int target;
    cin >> target;

    PathToNode(root, ans, target);

    return 0;
}
