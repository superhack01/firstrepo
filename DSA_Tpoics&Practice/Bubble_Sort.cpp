#include<iostream>

#define ll long long 

using namespace std;

int main(){
    int n;
    cin>>n;

    int * arr = new int[n];
    for (int i = 0;i<n;i++) cin>>arr[i];

    for (int i = 0;i<n;i++){
        for (int j = i+1;j<n;j++){
            if (arr[j] < arr[i]){
                swap(arr[j],arr[i]);
            }
        }
    }

    for (int i = 0;i<n;i++) cout<<arr[i]<<" ";

    cout<<endl;

    return 0;
}