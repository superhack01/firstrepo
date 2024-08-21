#include<iostream>
#include<string>

using namespace std;

void number(int n, string arr[]){

    if (n == 0){
        return ;
    }

    int rem = n % 10;

    n /= 10;

    number(n,arr);

    cout<<arr[rem]<<" ";

    return;
}

int main(){
    int n;
    cin>>n;

    string arr[] = {"Zero","One","Two","Three","Four","Five","Six","Seven","Eight","Nine"};

    number(n,arr);
    cout<<endl;

    return 0;
}