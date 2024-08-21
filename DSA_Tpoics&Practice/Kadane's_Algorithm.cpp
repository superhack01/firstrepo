#include<iostream>
#include<unordered_map>
#include<climits>

#define ll long long 

using namespace std;

int main(){
    int n;
    cin>>n;

    int * arr = new int[n];
    for (int i = 0;i<n;i++) cin>>arr[i];

    int sum = 0;
    int mx = INT_MIN;
    int start = 0;
    int ansstart = -1, ansend = -1;
    for (int i = 0;i<n;i++) {
        if (sum == 0) start = i;

        sum += arr[i];

        if (sum < 0){
            sum = 0;
        }

        if (sum > mx){
            mx = sum;
            ansend = i;
            ansstart = start;
        }

    }

    cout<<mx<<endl;
    cout<<ansstart<<" "<<ansend<<endl;

    return 0;
}