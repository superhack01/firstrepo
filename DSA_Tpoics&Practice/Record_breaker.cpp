#include<iostream>
#include<cmath>

using namespace std;

int main (){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int i , a[n];
        for (i=0;i<n;i++){
            cin>>a[i];
        }

        int ans = a[0],curr=0;
        for (i=0;i<n;i++){
            if (ans>a[i]){
                // cout<<"NO"<<endl;
                continue;
            }
            else {
                ans = max(ans,a[i]);
                if ((a[i]>a[i+1]) && ((i+1)<n)){
                    curr++;
                }
                else if ((i+1)==n) 
                     curr++;
            }
        }
        cout<<curr<<endl;
    }

    return 0;
}