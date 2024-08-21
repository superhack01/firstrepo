#include<iostream>
#include<cmath>

using namespace std;

void mergeArray(int * &arr, int s,int e){
    int mid = s + (e-s)/2;

    int len1 = mid - s + 1;
    int len2 = e - mid;

    int * firstarr = new int[len1];
    int * secondarr = new int[len2];

    int arrindex = s;
    for (int i = 0;i<len1;i++){
        firstarr[i] = arr[arrindex++];
    }

    arrindex = mid+1;
    for (int i = 0;i<len2;i++){
        secondarr[i] = arr[arrindex++];
    }

    int index1 = 0,index2 = 0;
    arrindex = s;

    while (index1 < len1 && index2 < len2){
        if (firstarr[index1] < secondarr[index2]){
            arr[arrindex++] = firstarr[index1++];
        }
        else {
            arr[arrindex++] = secondarr[index2++];
        }
    }

    while (index1 < len1){
        arr[arrindex++] = firstarr[index1++];
    }

    while(index2 < len2) {
        arr[arrindex++] = secondarr[index2++];
    }

}

void solve(int * &arr, int s, int e){
    if (s >= e){
        return ;
    }

    int mid = s + (e-s)/2;

    solve(arr,s,mid);
    solve(arr,mid+1,e);

    mergeArray(arr,s,e);
    
    return ;
}

int main(){
    int n;
    cin>>n;

    int * arr = new int[n];
    for (int i = 0;i<n;i++) cin>>arr[i];

    solve(arr,0,n-1);

    for (int i = 0;i<n;i++){
        cout<<arr[i]<<" ";
    }cout<<endl;

    return 0;
}