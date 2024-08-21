#include<iostream>
#include<string>
#include<cmath>
#include<vector>


#define ll long long

using namespace std;

vector<int> primess(int n)
{
    vector<int> ans;
    if (n<2){
        cout<<"0"<<endl;
        return ans;
    }

    int * a = new int[n+1];
    for (int i=2;i<=n;i++){
        a[i] = i;
    }
    int count = 0;

    for (int i = 2;i<n;i++){
        for(int j = i * i;j<=n;j += i){
            a[j] = 0;
        }
    }

    for (int i = 2;i<=n;i++){
        if (a[i] != 0){
            ans.push_back(i);
            count++;
        }
    }
    // cout<<count<<endl;

    return ans;
}
