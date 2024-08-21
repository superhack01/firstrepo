#include<iostream>
#include<string>
#include<cmath>
#include<stack>

#define ll long long

using namespace std;

void push(int * arr,int & i, int & j){
    int x,y;
    cout<<"Enter the stack number and element to push\n";
    cin>>x>>y;
    if (i>=j){
        cout<<"No Space. Stack Overflow!\n";
    }
    else {
        if (x == 1){
            arr[i] = y;
            i++;
        }
        else {
            arr[j] = y;
            j--;
        }
    }
}

void pop(int * arr,int & i,int & j){
    int x;
    cout<<"Enter the stack number for the poping element\n";
    cin>>x;

    cout<<i<<endl;

    if (x == 1) i--;
    else j++;

    cout<<i<<endl;
}

int main () {
    int n;
    cin>>n;

    int * arr = new int[n];

    int i = 0,j = n-1;

    push(arr,i,j);
    push(arr,i,j);
    push(arr,i,j);
    push(arr,i,j);

    pop(arr,i,j);

    push(arr,i,j);

    cout<<"Stack 1 \n";
    for (int p = 0;p<i;p++){
        cout<<arr[p]<<" ";
    }cout<<endl;
    cout<<"Stack 2\n";
    for (int p = n-1;p>j;p--){
        cout<<arr[p]<<" ";
    }cout<<endl;

    return 0;
}
