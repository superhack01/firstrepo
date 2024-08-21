#include<iostream>
#include<string>
#include<cmath>


#define ll long long

using namespace std;

bool isPosible(int arr[], int n, int m, int mid){
    int painterCount = 1;
    int pageSum = 0;
    for (int i = 0;i<n;i++){
        if ((pageSum + arr[i]) <= mid){
            pageSum += arr[i];
        }
        else {
            painterCount++;
            if ((painterCount > m)||(arr[i] > mid)){
                return false;
            }
           pageSum = arr[i];
        }
        if (painterCount > m){
            return false;
        }

    }

    return true;
}

int answewr(int arr[], int n, int m){
    int s = 0;
    int sum = 0;
    for (int i = 0;i<n;i++){
        sum += arr[i];
    }
    int e = sum;
    int ans = 1;
    int mid = s + (e-s)/2;
    // cout<<mid<<" " <<endl;
    while(s<=e){
        if (isPosible(arr,n,m,mid)==true){
            ans = mid;
            e = mid - 1;
        }
        else {
            s = mid + 1;
        }
        mid = s + (e-s)/2;
    }

    return ans;
}

int main () {
    int n,m;
    cin>>n>>m;
    int i,arr[n];
    for (i=0;i<n;i++){
        cin>>arr[i];
    }

    cout<<answewr(arr,n,m)<<endl;

    return 0;
}
