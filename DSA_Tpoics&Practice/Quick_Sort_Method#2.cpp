#include<iostream>
#include<cmath>

using namespace std;

int partition(int * &arr, int s,int e){
    int pivot = arr[s];
    int count = 0;

    for (int i = s;i<=e;i++){
        if (arr[i] < pivot){
            count++;
        }
    }

    int pivotindex = s + count;

    swap(arr[s],arr[pivotindex]);

    int i = s;
    int j = e;

    while (i < pivotindex && j > pivotindex){
        if (arr[i] < pivot) {
            i++;
            continue;
        }
        if (arr[j] > pivot) {
            j--;
            continue;
        }

        swap(arr[i++],arr[j--]);
    }

    return pivotindex;
}

void quickSort(int * &arr, int s, int e){
    if (s >= e) return ;

    //partition method 
    int p = partition(arr,s,e);

    //Recursive call stack;
    quickSort(arr,s,p-1);
    quickSort(arr,p+1,e);

    return ;
}

int main(){
    int n;
    cin>>n;

    int * arr = new int[n];
    for (int i = 0;i<n;i++) cin>>arr[i];

    quickSort(arr,0,n-1);

    for (int i = 0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;


    return 0;
}