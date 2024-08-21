#include<iostream>
#include<string>
#include<cmath>


#define ll long long

using namespace std;

int main () {
    int a,b;
    cin>>a>>b;
    int gcd;
    if (a==0){
       cout<<b<<endl;
       return 0;
    }
    if (b==0){
       cout<<a<<endl;
       return 0;
    }
    while(a != b){
        if (a>b){
            a -= b;
        }
        else {b -= a;}
    }
    cout<<a<<endl;
    return 0;
}
