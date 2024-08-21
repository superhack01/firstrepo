#include<iostream>
#include<map>
#include<vector>
#include<algorithm>

#define ll long long 

using namespace std;
bool comparator(pair<pair<int,int>,int> a,pair<pair<int,int>,int> b){
    return  a.second < b.second;
}

int main() {
    int n,m;
    cin>>n>>m;

    int * a = new int[n];
    int * b = new int[m];
    for (int i = 0;i<n;i++) cin>>a[i];
    for (int i = 0;i<m;i++) cin>>b[i];

    map<pair<int,int>,int> mp;
    for (int i = 0;i<n;i++){
        for (int j = 0;j<m;j++){
            mp[make_pair(a[i],b[j])] = a[i]+b[j];
        }
    }

    vector<pair<pair<int,int> ,int> > v (mp.begin(),mp.end());

    sort(v.begin(),v.end(),comparator);
    for (auto i : v){
        cout<<i.first.first<<" "<<i.first.second<<","<<i.second<<endl;
    }cout<<endl;

    return 0;
}
