#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int kthSmallest(int * arr, int k, int n){
    priority_queue<int> pq;
    for (int i = 1;i<=k;i++){
        pq.push(arr[i]);
    }

    for (int i = k + 1;i<=n;i++){
        if (pq.top() > arr[i]){
            pq.pop();
            pq.push(arr[i]);
        }
    }

    int ans = pq.top();

    return ans;
}
int kthlargest(int * arr, int k, int n){
    priority_queue<int,vector<int>, greater<int> > pq;
    for (int i = 1;i<=k;i++){
        pq.push(arr[i]);
    }

    for (int i = k + 1;i<=n;i++){
        if (pq.top() < arr[i]){
            pq.pop();
            pq.push(arr[i]);
        }
    }

    int ans = pq.top();

    return ans;
}

int main(){
    int n,k;
    cin>>n>>k;

    int * arr = new int[n+1];
    arr[0] = -1;
    for (int i = 1;i<=n;i++) cin>>arr[i];

    cout<<kthSmallest(arr,k,n)<<endl;

    cout<<kthlargest(arr,k,n)<<endl;

    return 0;
}