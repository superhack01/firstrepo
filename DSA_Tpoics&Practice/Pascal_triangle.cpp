#include<iostream>
#include<cmath>

using namespace std;

int fact(int n){
  int y,fact=1;
  for (y=n;y>0;y--){
    fact *= y;
  }
  return fact;
}

int ncr(int i,int j){
  int result;
  result  = (fact(i)) / ((fact(i-j)) * (fact(j)));

  return result;

}
int main (){
  int i, j;
  int x;
  cout<<"Enter the number of rows : ";
  cin>>x;

  for (i=0;i<x;i++){
   for (j=0;j<=i;j++){
     cout<<ncr(i,j);
     cout<<"\t";
   }
   cout<<endl;
  }

  return 0;
}
