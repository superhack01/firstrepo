#include<iostream>
#include<string>
#include<cmath>
#include<vector>
#include<algorithm>

#define ll long long

using namespace std;

bool evennumber(ll n){
    bool x;
    if ((n%2)==0){
        x = true;
    }
    else 
        x = false;

    return x;
}

int main () {
    ll n;
    cin>>n;
    ll i, a[n];
    for (i=0;i<n;i++){
        cin>>a[i];
    }

    vector <int> even;
    vector <int> odd;

    for (i=0;i<n;i++){
        if (evennumber(a[i])){
            even.push_back(a[i]);
        }
        else {
            odd.push_back(a[i]);
        }
    }
    sort(even.begin(),even.end());
    sort(odd.begin(),odd.end());

    for (i=0;i<even.size();i++){
        cout<<even[i]<<" ";
    }
    cout<<endl;
    for (i=0;i<odd.size();i++){
        cout<<odd[i]<<" ";
    }
    cout<<endl;

    return 0;
}