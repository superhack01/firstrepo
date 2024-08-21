#include<iostream>
#include<cmath>
#include<vector>
#include<stack>
#include<climits>
#include<algorithm>

using namespace std;

int main() {
    int n;
    cin>>n;

    int * arr = new int[n];
    for (int i = 0;i<n;i++) cin>>arr[i];

    int first = arr[0];

    int mx = INT_MIN;
    int position;
    for (int i = 0;i<n;i++){
        if (arr[i] > mx){
            position = i;
        }
    }
    position = n - position + 1;

    rotate(arr,arr+position,arr+n);
    for (int i = 0;i<n;i++){
        cout<<arr[i]<<" ";
    }cout<<endl;
    stack<int> st;
    vector<int> ans;
    for (int i = n-1;i>=0;i--){
        while (!st.empty() && st.top() <= arr[i]){
            st.pop();
        }

        if (st.empty()){
            ans.push_back(-1);
            st.push(arr[i]);
        }
        if (!st.empty() && st.top() > arr[i]){
            ans.push_back(st.top());
            st.push(arr[i]);
        }
        
    }

    for (int i = 0;i<n;i++){
        if (arr[i] == first){
            position = i;
        }
    }

    // position = n - position;

    reverse(ans.begin(),ans.end());
    rotate(ans.begin(),ans.begin()+position,ans.end());

    for (auto i : ans){
        cout<<i<<" ";
    }cout<<endl;


    return 0;
}