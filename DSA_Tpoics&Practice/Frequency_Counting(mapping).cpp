#include<iostream>
#include<algorithm>
#include<map>

#define ll long long

using namespace std;

int main()
{
    int n;
    cin>>n;

    int * arr = new int[n];

    for (int i = 0;i<n;i++){
        cin>>arr[i];
    }

    map<int, int> m;
    for (int i = 0;i<n;i++){
        m[arr[i]]++;
    }

    for(auto i : m){
        cout<<i.first<<" -> "<<i.second<<endl;
    }

    return 0;
}
