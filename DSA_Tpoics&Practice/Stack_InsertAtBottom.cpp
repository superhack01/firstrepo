#include<iostream>
#include<string>
#include<cmath>
#include<stack>

#define ll long long

using namespace std;

void solve(stack<int> &st, int val){
    if (st.empty()){
        st.push(val);
        return;
    }

    int num = st.top();
    st.pop();

    //Recursive call 
    solve(st,val);

    st.push(num);
}

int main () {
    int n;
    stack<int> st;
    st.push(4);
    st.push(3);
    st.push(2);
    st.push(1);

    cin>>n;

    solve(st,n);

    while(!st.empty()){
        cout<<st.top()<<endl;
        st.pop();
    }

    return 0;
}