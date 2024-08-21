#include<iostream>

#define ll long long 

using namespace std;

int main(){
    int n;
    cin>>n;

    int * arr = new int[n];
    for (int i = 0;i<n;i++) cin>>arr[i];

    int mn;
    for (int i = 0;i<n;i++){
        mn = i;
        for (int j = i;j<n;j++){
            if (arr[j] < arr[mn]){
                mn = j;
            }
        }

        swap(arr[i],arr[mn]);
    }

    for (int i = 0;i<n;i++) cout<<arr[i]<<" ";

    cout<<endl;

    return 0;
}


/*
//// Insertion Sort 

#include<iostream>

#define ll long long 

using namespace std;

int main(){
    int n;
    cin>>n;

    int * arr = new int[n];
    for (int i = 0;i<n;i++) cin>>arr[i];

    for (int i = 0;i<n;i++){
        for (int j = i;j>0;j--){
            if (arr[j] < arr[j-1]){
                swap(arr[j],arr[j-1]);
            }
        }
    }

    for (int i = 0;i<n;i++) cout<<arr[i]<<" ";

    cout<<endl;

    return 0;
}

*/