#include<iostream>
#include<queue>
#include<vector>

#define ll long long 

using namespace std;

void MergeTwoHeap(vector<ll> &a, vector<ll> &b){
    for (auto i : b){
        a.push_back(i);
    }

}

void heapify(vector<ll> &a,ll i,ll n){
    ll largest = i;
    ll left = 2*i + 1;
    ll right = 2 * i + 2;

    if (left < n && a[left] > a[largest]){
        largest = left;
    }
    if (right < n && a[right] > a[largest]){
        largest = right;
    }

    if (largest != i){
        swap(a[i],a[largest]);
        heapify(a,largest,n);
    }

    return ;
}


int main() {
    ll n,m;
    cin>>n>>m;

    vector<ll> a,b;
    for (ll i = 0;i<n;i++){
        ll x;
        cin>>x;

        a.push_back(x);
    }

    for(ll i = 0;i<m;i++){
        ll x;
        cin>>x;

        b.push_back(x);
    }

    MergeTwoHeap(a,b);
    
    for (ll i = ((n+m)/2)-1 ; i>=0;i--){
        heapify(a,i,n+m);
    }

    for (auto i : a){
        cout<<i<<" ";
    }cout<<endl;

    return 0;
}