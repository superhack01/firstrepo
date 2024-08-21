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

    ////Bit Setting 
    cout<<(n|(1<<position))<<endl;
    cout<<"Bit Setted!"<<endl;

    ////Bit Unsetting
    cout<<(n&(~(1<<position)))<<endl;
    cout<<"Bit UnSetted!"<<endl;

    return 0;
}
