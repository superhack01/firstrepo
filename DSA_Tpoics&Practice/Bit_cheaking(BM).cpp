#include<iostream>
#include<cmath>
#include<algorithm>

#define ll long long 

using namespace std;

int main (){
    int n;
    cin>>n;

    int position;
    cin>>position;

    if ((n&(1<<position)) != 0){
        cout<<"This position bit is 1."<<endl;

    }
    else cout<<"This position bit is 0."<<endl;
}
