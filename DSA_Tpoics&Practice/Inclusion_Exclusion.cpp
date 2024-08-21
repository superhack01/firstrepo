#include<iostream>
#include<string>
#include<cmath>
#include<vector>

#define ll long long

using namespace std;

void solve(vector<ll> num, vector<ll>output, ll index, vector<vector<ll>>& ans){
    // base case 
    if (index>= num.size()){
        ans.push_back(output);
        return;
    }

    //exclude
    solve(num, output, index++, ans);

    //include
    ll element = num[index];
    output.push_back(element);
    solve(num, output,index++, ans);

    return ;
}

vector<vector<ll>> result(vector<ll>& num){
    vector<vector<ll>> ans;
    vector<ll> output;

    solve(num,output,0,ans);

    for (ll i =0;i<ans.size();i++){
        for(ll j = 0;j<ans[i].size();j++){
            cout<<ans[i][j]<<" ";
        }cout<<endl;
    }
    return ans;
}

int main () {
    ll n;
    cin>>n;
    
    vector<ll> num;
    for (ll i = 0;i<n;i++){
        ll x;
        cin>>x;
        num.push_back(x); 
    }

    result(num);
    
    
    return 0;
}
