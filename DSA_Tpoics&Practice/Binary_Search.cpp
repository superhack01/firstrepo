#include<iostream>
#include<string>
#include<cmath>


#define ll long long

using namespace std;

int binarySearch(int a[], int size, int key){
    int s = 0;
    int end = size - 1;
    int mid = (s + end) / 2;

    while(s <= end){
        if (a[mid]==key){
            return mid;
        }
        if (a[mid]>key){
            end = mid - 1;
        }
        else {
            s = mid + 1;
        }
        mid = (s + end) / 2;
    }
    return -1;
}
int main () {
    int a[5] = {2,3,4,5,6};
    int b[6] = {4,5,6,7,8,9};
    cout<<binarySearch(a,5,6)<<endl;
    cout<<binarySearch(b,6,4)<<endl;

    return 0;
}