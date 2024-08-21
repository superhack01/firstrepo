#include<iostream>
#include<vector>

#define ll long long

using namespace std;

void solve(vector<string> &ans,string s,int index,string pre,int n){
    if (index == n){
        ans.push_back(pre);
        return ;
    }

    //for including
    char ele = s[index];
    pre.push_back(ele);

    solve(ans,s,index+1,pre,n);
    pre.pop_back();

    //for excluding
    solve(ans,s,index+1,pre,n);

    return ;
}

int main (){
    int n;
    cin>>n;

    string str;
    cin>>str;

    vector<string> ans;
    string pre = "";
    // vector<vector<string>> result;

    solve(ans,str,0,pre,n);

    for (auto i : ans){
        cout<<i<<" ";
    }cout<<endl;

    return 0;
}


/*
///Question based on it 

#include<iostream>
#include<vector>
#include<unordered_set>

#define ll long long

using namespace std;

void solve(vector<string> &ans,string s,int index,string pre,int n){
    if (index == n){
        ans.push_back(pre);
        return ;
    }

    //for including
    char ele = s[index];
    pre.push_back(ele);

    solve(ans,s,index+1,pre,n);
    pre.pop_back();

    //for excluding
    solve(ans,s,index+1,pre,n);

    return ;
}

int main (){
    // int n;
    // cin>>n;

    string str1,str2;
    cin>>str1;
    cin>>str2;

    vector<string> ans1,ans2;
    string pre = "";

    solve(ans1,str1,0,pre,str1.length());
    solve(ans2,str2,0,pre,str2.length());

    unordered_set<string> sett;
    for (auto i : ans1){
        // cout<<i<<" ";
        sett.insert(i);
    }cout<<endl;

    ll x = sett.size();
    sett.clear();

    for (auto i : ans2){
        // cout<<i<<" ";
        sett.insert(i);
    }cout<<endl;

    ll y = sett.size();
    sett.clear();

    cout<<x-1<<" "<<y-1<<endl;

    return 0;
}

*/