#include<iostream>
#include<queue>
#include<algorithm>

#define ll long long 

using namespace std;

void heapify(int * &arr, int size, int i){
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < size && arr[left] > arr[largest]){
        largest = left;
    }
    if (right < size && arr[right] > arr[largest]){
        largest = right;
    }

    if (largest != i){
        swap(arr[i],arr[largest]);
        heapify(arr,size,largest);
    }
}
void heapSort(int * &arr, int size){
    while (size > 1){
        //step 1 Swap the max and last nodes
        swap(arr[0],arr[size-1]);

        // decrease the size
        size--;

        //place the 0th item at right place
        heapify(arr,size,0);
    }
}
int main(){
    int n;
    cin>>n;
    
    int * arr = new int[n];
    for(int i = 0;i<n;i++) cin>>arr[i];

    make_heap(arr,arr+n);

    for (int i = 0;i<n;i++){
        cout<<arr[i]<<" ";
    }cout<<endl;

    heapSort(arr,n);

    for (int i = 0;i<n;i++){
        cout<<arr[i]<<" ";
    }cout<<endl;

    return 0;
}

