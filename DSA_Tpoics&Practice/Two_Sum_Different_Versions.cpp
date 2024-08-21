#include<iostream>
#include<set>
#include<unordered_map>

#define ll long long 

using namespace std;

bool ansYN(int n){

    set<int> arr;
    for (int i = 0;i<n;i++)
    {
        int x;
        cin>>x;

        arr.insert(x);
    }

    int target;
    cin>>target;

    for(auto i : arr){
        int x = target-i;
        if (arr.count(x) == 1) return true;

    }

    return false;
}

pair<int,int> indexes(int n){
    int * arr = new int(n);
    for (int i = 0;i<n;i++) cin>>arr[i];

    int target;cin>>target;

    unordered_map<int,int> mp;
    for (int i = 0;i<n;i++) mp[arr[i]] = i;

    for (int i= 0;i<n;i++){
        int x = target - arr[i];

        if (mp.find(x) != mp.end()){
            return make_pair(i,mp[x]);
        }

    }

    return {-1,-1};
}

int main() {
    int n;
    cin>>n;

    pair<int,int> result = indexes(n);
    cout<<result.first<<" "<<result.second<<endl;
    
    return 0;
}