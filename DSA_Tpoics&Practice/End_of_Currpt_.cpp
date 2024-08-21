#include<iostream>
#include<string>
#include<cmath>
#include<algorithm>
#include<vector>


#define ll long long

using namespace std;

int main () {
   ll n, m;
   cin>>n>>m;

   vector<ll> v;
   ll i, a[n+m];
   for (i=0;i<n+m;i++){
    cin>>a[i];
   }
   ll mx = 0;
   ll ans;
   for (i=0;i<n+m;i++){
       if (a[i]==(-1)){
        sort(a,a+i);
        // for(ll j=0;j<i;j++){
        //     cout<<a[j]<<" ";
        // }cout<<endl;
        ll f = i;
        for (ll j = 0;j<v.size();j++){
            if (a[f-1] == v[j]){
                f--;
            }
            ans = a[f-1];
        }
        v.push_back(a[f-1]);
       }
   }

   for(auto i: v){
    cout<<i<<" ";
   }cout<<endl;
    return 0;
}
