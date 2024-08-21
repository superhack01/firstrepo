// #include<bits/stdc++.h>
#include<iostream>


using namespace std;

int main (){
    int t;
    cin>>t;
    while(t--){
        int n ;
        cin>>n;
        cin.ignore();

        char arr[100];
        cin.getline(arr, n);
        cin.ignore();

        int i = 0;
        int curr = 0, mx = 0;
        int st=0,mxst = 0;
        while (true){
            if (arr[i] == ' ' || arr[i] == '\0'){
                if (curr>mx){
                    mx = curr;
                    mxst = st;
                }
                st = i + 1;
                curr = 0;
            }
            else 
                curr++;
            
            if (arr[i]=='\0')
                break;

            i++;

        }

        cout<<mx<<endl;
        for (i=0;i<mx;i++){
            cout<<arr[i+mxst];
        }
        cout<<endl;

    }

    return 0;
}
