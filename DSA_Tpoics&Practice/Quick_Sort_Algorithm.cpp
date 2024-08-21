#include<iostream>
#include<string>
#include<cmath>


#define ll long long

using namespace std;

ll partion(ll * arr, ll s, ll e){
    ll pivot = arr[s];
    ll cnt = 0;
    for (ll i = s + 1;i<=e;i++){
        if (arr[i] <= pivot){
            cnt++;
        }
    }
    ll pivotIndex = s + cnt;
    swap(arr[pivotIndex], arr[s]);

    ll i = s, j = e;

    while((i<pivotIndex) && (j>pivotIndex)){
        while(arr[i] <= pivot){
            i++;
        }
        while(arr[j] > pivot){
            j--;
        }

        if ((i<pivotIndex) && (j>pivotIndex)){
            swap(arr[i++],arr[j--]);
        }

        return pivotIndex;
    }

}

void quickSort(ll * arr, ll s, ll e){
    //base case 
    if (s>=e){
        return ;
    }

    ll p = partion(arr,s,e);

    //left part
    quickSort(arr,s,p-1);

    //right part
    quickSort(arr,p+1,e);

    return;
}

int main () {
     ll arr[] = {3,2,5,6,7,1,9};
     ll n = 7;

     quickSort(arr,0,n-1);
     
     for (ll i =0;i<n;i++){
        cout<<arr[i]<<" ";
     }cout<<endl;

    return 0;
}
